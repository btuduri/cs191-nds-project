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


void CMarioIdle::update(u16 index) {
	
//	se->tileIdx = 0;//curImage * 128;

    /* Copy the sprite graphics to sprite graphics memory */

    //dmaCopyHalfWords(	SPRITE_DMA_CHANNEL,
	dmaCopy(	(void*)&mario_idleBitmap[curImage * IMAGE_SIZE_64x64H],
    			(void*)&SPRITE_GFX[index * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_64x64);//mario_idleBitmapLength);

//	dmaCopy(mario_runBitmap, SPRITE_GFX, mario_runBitmapLength);

	
	
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

void CMarioIdle::load() {
//void CMarioIdle::load() {

	nextImage = 1;
	curImage = 0;

	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	
//    dmaCopyHalfWords(	SPRITE_DMA_CHANNEL,
//    					mario_idlePalette,
//    					&SPRITE_PALETTE[0 * COLORS_PER_PALETTE],
//    					mario_idlePaletteLength);
	
//	return tileIdx + mario_idleBitmapLength / BYTES_PER_16_COLOR_TILE;

    
    // Load the sprite palette.
//	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	
	// Load the sprite binary data into the VRAM
//	dmaCopy(mario_idleBitmap, SPRITE_GFX, mario_idleBitmapLength);

}

