#include "CMarioWalk.h"

CMarioWalk::CMarioWalk()
{	
	nextImage = 1;
	curImage = 0;
	numImages = 5;
	startTitleIndex = 0;
}

CMarioWalk::~CMarioWalk()
{
}

void CMarioWalk::update(SpriteEntry *se) {
	
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

	se->tileIdx = curImage * 128;

}

void CMarioWalk::load() {

	// Load the sprite palette.
	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_idleBitmap, SPRITE_GFX, mario_idleBitmapLength);

}
