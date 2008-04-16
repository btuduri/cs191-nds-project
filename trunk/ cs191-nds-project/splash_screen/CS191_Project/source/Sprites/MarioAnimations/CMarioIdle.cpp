#include "CMarioIdle.h"

CMarioIdle::CMarioIdle()
{
	xoffset = 0;
	yoffset = 0;
	nextImage = 1;
	curImage = 0;
	numImages = 4;
	imageSize = 32;
}

CMarioIdle::~CMarioIdle()
{
}


void CMarioIdle::update(SpriteEntry *se) {
	
	se->tileIdx = curImage * 128;
		
	if(nextImage > curImage)	//increasing
	{
		curImage++;
		if(nextImage == (numImages - 1))
			nextImage--;
		else
			nextImage++;
	}
	else						//decreasing
	{
		curImage--;
		if(nextImage == 0)
			nextImage++;
		else
			nextImage--;
	}
	
}

void CMarioIdle::load(u16 oamID, u16 tileIdx) {
//void CMarioIdle::load() {

	nextImage = 1;
	curImage = 0;

    dmaCopyHalfWords(	SPRITE_DMA_CHANNEL,
    					mario_idlePalette,
    					&SPRITE_PALETTE[oamId * COLORS_PER_PALETTE],
    					mario_idlePaletteLength);

    /* Copy the sprite graphics to sprite graphics memory */

    dmaCopyHalfWords(	SPRITE_DMA_CHANNEL,
    					mario_idleBitmap,
    					&SPRITE_GFX[tileIdx * OFFSET_MULTIPLIER],
    					mario_idleBitmapLength);
	
	return tileIdx + mario_idleBitmapLength / BYTES_PER_16_COLOR_TILE;

    
    // Load the sprite palette.
//	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	
	// Load the sprite binary data into the VRAM
//	dmaCopy(mario_idleBitmap, SPRITE_GFX, mario_idleBitmapLength);

}

