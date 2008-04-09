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

void CMarioIdle::load() {
	
	nextImage = 1;
	curImage = 0;

	// Load the sprite palette.
	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_idleBitmap, SPRITE_GFX, mario_idleBitmapLength);

}

