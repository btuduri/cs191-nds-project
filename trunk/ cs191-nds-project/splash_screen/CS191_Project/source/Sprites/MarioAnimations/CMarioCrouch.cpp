#include "CMarioCrouch.h"

CMarioCrouch::CMarioCrouch()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 2;
	animationLocked = false;
	imageSize = 32;
	spriteOffset = 13;
}

CMarioCrouch::~CMarioCrouch()
{
}

void CMarioCrouch::update(CSprite *sprite) {

	dmaCopy(	(void*)&mario_spritesBitmap[(spriteOffset+curImage) * IMAGE_SIZE_32x32H],
				SPRITE_GFX+(4096*sprite->getSpriteIndex()),
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

void CMarioCrouch::load(CSprite *sprite) {

	if( isCrouching )
	{
		isCrouching = false;
		// the animation should still be locked at this point
	}
	else {
		sprite->setObjSize(OBJSIZE_32);
		animationLocked = true;
		curImage = 0;
		isCrouching = true;

		// Load the sprite palette.
//		dmaCopy(mario_crouchPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_crouchPaletteLength);
	}
	
	update(sprite);
}
