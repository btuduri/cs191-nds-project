#include "CMarioCrouch.h"

CMarioCrouch::CMarioCrouch()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 4;
	locked = false;
	imageSize = 32;
}

CMarioCrouch::~CMarioCrouch()
{
}

void CMarioCrouch::update(SpriteEntry *se) {
	
	if(isCrouching)	//crouching
	{
		if( curImage < (numImages - 1) )
		{
			curImage++;
			se->tileIdx = curImage * 128;
		}
		else
			isCrouching = true;
	}
	else				//coming up
	{
		if( curImage > 0 )
		{
			curImage--;
			se->tileIdx = curImage * 128;			
		}
	}	

}

void CMarioCrouch::load() {
	
//	locked = true;
	isCrouching = true;
	
	// Load the sprite palette.
	dmaCopy(mario_crouchPalette, SPRITE_PALETTE, mario_crouchPaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_crouchBitmap, SPRITE_GFX, mario_crouchBitmapLength);

}

