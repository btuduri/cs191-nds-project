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
	
	dmaCopy(	(void*)&mario_idleBitmap[curImage * IMAGE_SIZE_32x32H],
    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_32x32);

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

void CMarioIdle::load(SpriteEntry *se) {

	se->objSize = OBJSIZE_32;
	
	nextImage = 1;
	curImage = 0;

	dmaCopy(mario_idlePalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_idlePaletteLength);
	
	update(se);
}

