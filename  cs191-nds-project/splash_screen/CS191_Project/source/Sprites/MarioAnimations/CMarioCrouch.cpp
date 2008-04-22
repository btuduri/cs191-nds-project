#include "CMarioCrouch.h"

CMarioCrouch::CMarioCrouch()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 2;
	animationLocked = false;
	imageSize = 32;
}

CMarioCrouch::~CMarioCrouch()
{
}

void CMarioCrouch::update(SpriteEntry *se) {

	dmaCopy(	(void*)&mario_crouchBitmap[curImage * IMAGE_SIZE_32x32H],
    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_32x32);

	if(isCrouching)	//crouching
	{
		if( curImage < (numImages - 1) )
		{
			curImage++;
		}
	}
	else
	{
		if( curImage > 0 )
		{
			curImage--;
		}
		else animationLocked = false;
	}	

}

void CMarioCrouch::load(SpriteEntry *se) {

	if( isCrouching )
	{
		isCrouching = false;
		// the animation should still be locked at this point
	}
	else {
		se->objSize = OBJSIZE_32;
		animationLocked = true;
		curImage = 0;
		isCrouching = true;

		// Load the sprite palette.
		dmaCopy(mario_crouchPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_crouchPaletteLength);
	}
	
	update(se);
}
