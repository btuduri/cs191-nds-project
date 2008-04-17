#include "CMarioRun.h"
#include "graphics/mario_idle.h"

CMarioRun::CMarioRun()
{	
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 8;
}

CMarioRun::~CMarioRun()
{
}

void CMarioRun::update(u16 index) {
	
	dmaCopy(	(void*)&mario_runBitmap[curImage * IMAGE_SIZE_64x64H],
    			(void*)&SPRITE_GFX[index * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_64x64);//mario_idleBitmapLength);
	
	curImage++;
	
	if(curImage == numImages)
		curImage = 0;
}

void CMarioRun::load() {

	curImage = 0;
	
	// Load the sprite palette.
	dmaCopy(mario_runPalette, SPRITE_PALETTE, mario_runPaletteLength);
	
	// Load the sprite binary data into the VRAM
//	dmaCopy(mario_runBitmap, SPRITE_GFX, mario_runBitmapLength);

}

