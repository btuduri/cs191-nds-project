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

void CMarioCrouch::update(u16 index) {

	dmaCopy(	(void*)&mario_crouchBitmap[curImage * IMAGE_SIZE_64x64H],
    			(void*)&SPRITE_GFX[index * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_64x64);//mario_idleBitmapLength);

//	if(isCrouching)	//crouching
//	{
		if( curImage < (numImages - 1) )
		{
			curImage++;
		}
		else
		{
//			isCrouching = true;
			locked = false;
		}
	}
//	else				//coming up
//	{
//		if( curImage > 0 )
//		{
//			curImage--;
//		}
//		else locked = false;
//	}	

}

void CMarioCrouch::load() {

	locked = true;
	curImage = 0;
	isCrouching = true;
	
	// Load the sprite palette.
	dmaCopy(mario_crouchPalette, SPRITE_PALETTE, mario_crouchPaletteLength);
	
	// Load the sprite binary data into the VRAM
//	dmaCopy(mario_crouchBitmap, SPRITE_GFX, mario_crouchBitmapLength);

}

void CMarioCrouch::forceUnlock() {
	setIsCrouching(false);
}

