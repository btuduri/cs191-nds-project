#include "CMarioCrouch.h"

CMarioCrouch::CMarioCrouch()
{
	nextImage = 1;
	curImage = 0;
	numImages = 4;
	startTitleIndex = 0;
}

CMarioCrouch::~CMarioCrouch()
{
}

void CMarioCrouch::update(SpriteEntry *se) {
	
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

void CMarioCrouch::load() {
	
	// Load the sprite palette.
	dmaCopy(mario_crouchPalette, SPRITE_PALETTE, mario_crouchPaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_crouchBitmap, SPRITE_GFX, mario_crouchBitmapLength);

}

