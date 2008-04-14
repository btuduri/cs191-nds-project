#/usr/bin/python
#
#    [general]
#    input: pacman.png
#    transparent: 0xFF00FF
#    dimension: 1
#    
#    [sprite0]
#    x: 0
#    y: 0
#    width: 32
#    height: 32
import sys
import Image
import ConfigParser
import binascii
import datetime

# spritemaker main code
if __name__ == "__main__":
    config = ConfigParser.ConfigParser()
    
    if len(sys.argv) != 2:
        print "usage: spritemaker.py infilename"
        sys.exit()
        
    config.read(sys.argv[1])
    
    # Create palette and tile data. This is done outside the loop since there can onl be one sprite palette and tile data.
    # The tile data holds the converted image in 555 quantized 8x8 tile tessellated form.
    palette = []
    tile_data = []

    sprite = 0
    
    # Get our overall configuration parameters.
    try:
        infile = config.get("general", "input")
        infile_base = infile[:-4]
        dimension = config.getint("general", "dimension")
        transparent = config.get("general", "transparent")
    
        # Check to see if we compute transparencies if so, get the color.
        if(transparent != "none"):
            transparent_color = (int(transparent[2:4], 16), int(transparent[4:6], 16), int(transparent[6:8], 16))
            palette.append(transparent_color)
    except:
        print "Invalid general input parameter, exiting."
        sys.exit()
    
    # Read in the entire image file and check to make sure it's the correct type.
    input_image = Image.open(infile)
    if input_image.mode != "RGBA":
        print "spritemaker only supports PNGs currently, sorry."
        sys.exit()
    
    # Construct palette only using unique colors. we must end up with less than 256 colors though.
    for (r, g, b, a) in input_image.getdata():
        if not (r,g,b) in palette:
            palette.append((r,g,b))
    if len(palette) > 256:
        print "More than 256 colors used, exiting." % sprite
        sys.exit()
        
    # Fill out the rest of the palette so you have 256 colors exactly
    palette_filler = [ (0,0,0) for i in range(256 - len(palette))]
    palette = palette + palette_filler        
       
    # Process the individual sprites
    while config.has_section("sprite%s" % sprite):
        spritesection = "sprite%s" % sprite
        
        # Get the sprite specific configuration parameters.
        try:
            x = config.getint(spritesection, "x")
            y = config.getint(spritesection, "y")
            width = config.getint(spritesection, "width")
            height = config.getint(spritesection, "height")
        except:
            print "Invalid sprite input parameter for sprite %s, exiting." % sprite
            sys.exit()
        
        # Check to make sure that we can tesselate the input image using 8x8 tiles.
        if (width % 8 != 0) or (height % 8 != 0):
            print "Sprite dimensions are not divisible by 8 and therefore cannot be tiled, exiting." % sprite
            sys.exit()
    
        # Extract the sprite data from the input image    
        sprite_image = input_image.crop((x, y, x + width, y + height))
        
        # For each sprite we tessellate the sprite using 8x8 tiles (64 bytes). Each tile is then converted to a palletized
        # representation and output.
        for tile_y in range(0, height, 8):
            for tile_x in range(0, width, 8): 
                tile_image = sprite_image.crop((tile_x, tile_y, tile_x + 8, tile_y + 8))
                for (r, g, b, a) in tile_image.getdata():
                    tile_data.append(palette.index((r,g,b)))
        
        sprite =  sprite + 1
        
   # Create palette C file. The palette needs to be quantized to a 555 format entry from an 888 format
   # entry. This is done on a per color basis as we're outputting the file.
    palette_source = open("%s.c" % infile_base, "w")
    palette_source.write("//-----------------------------------------------------------------\n")
    palette_source.write("// %s.c\n" % infile_base)
    palette_source.write("// \n")
    palette_source.write("// Created by spritemaker.py at %s\n" % datetime.datetime.today())
    palette_source.write("// spritemaker.py by Dean Nevins\n")
    palette_source.write("//-----------------------------------------------------------------\n")
    palette_source.write("const unsigned short %sPalette[256] =\n" % infile_base)
    palette_source.write("    {\n    ")
    wItem = 0
    for palette_entry in palette:
        if wItem % 64 == 0 and wItem != 0:
            palette_source.write("\n")
        if wItem % 8 == 0 and wItem != 0:
            palette_source.write("\n")
            palette_source.write("    ")
        # Write out palette color. NOTE: DS palette is in BGR format.
        palette_source.write("0x%04X, " % (int(palette_entry[2] / 8) * 1024 + (int(palette_entry[1] / 8) * 32) + int(palette_entry[0] / 8)))
        wItem = wItem + 1
    palette_source.write("\n    };\n")

    palette_source.write("\nconst unsigned short %sBitmap[%d] =\n" % (infile_base, int(len(tile_data) / 2)))
    palette_source.write("    {\n    ")
    for wTile in range(0, len(tile_data), 2):
        if wTile % 64 == 0 and wTile != 0:
            palette_source.write("\n")
        if wTile % 16 == 0 and wTile != 0:
            palette_source.write("\n")
            palette_source.write("    ")
        # Output the pixel data corresponding to the palette entry. Note that the order is reversed from what you might
        # expect it to be due to ARM chips' 16 bit memory layout.
        palette_source.write("0x%04X, " % (tile_data[wTile + 1] * 256 + tile_data[wTile]))
    palette_source.write("\n    };\n\n")

    # Create palette header file.
    palette_header = open("%s.h" % infile_base, "w")
    palette_header.write("//-----------------------------------------------------------------\n")
    palette_header.write("// %s.h\n" % infile_base)
    palette_header.write("// \n")
    palette_header.write("// Created by spritemaker.py at %s\n" % datetime.datetime.today())
    palette_header.write("// spritemaker.py by Dean Nevins\n")
    palette_header.write("//-----------------------------------------------------------------\n")
    palette_header.write("#ifndef __%s__\n" % infile_base.upper())
    palette_header.write("#define __%s__\n\n" % infile_base.upper())
    
    palette_header.write("#define %sPaletteLength %d\n" % (infile_base, 2 * len(palette)))
    palette_header.write("extern const unsigned short %sPalette[256];\n" % infile_base)
    
    
    palette_header.write("\n#define %sBitmapLength %d\n" % (infile_base, len(tile_data)))
    palette_header.write("extern const unsigned short %sBitmap[%d];\n" % (infile_base, int(len(tile_data) / 2)))
    
    palette_header.write("\n#endif\n")




