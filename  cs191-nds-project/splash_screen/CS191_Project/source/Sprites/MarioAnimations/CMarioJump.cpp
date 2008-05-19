#include "CMarioJump.h"

CMarioJump::CMarioJump()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 3;
	animationLocked = false;
	imageSize = 32;
	spriteOffset = 15;

}

CMarioJump::~CMarioJump()
{
}

void CMarioJump::update(CSprite *sprite) {

	dmaCopy(	(void*)&mario_spritesBitmap[(spriteOffset+curImage) * IMAGE_SIZE_32x32H],
				SPRITE_GFX+(4096*sprite->getSpriteIndex()),
    			IMAGE_SIZE_32x32);

	if( jump ) {
	
		if( curImage < numImages )
		{
			curImage++;
		}
		else
		{
	//		animationLocked = false;
		}
	}
	else {	//crouching

		if( curImage < numImages )
		{
			curImage++;
		}
		else
		{
			mobilityLocked = false;
			loadJump();
		}
	}
}

void CMarioJump::load(CSprite *sprite) {
	mobilityLocked = true;
	curImage = 0;
	numImages = 2;
	spriteOffset = 13;
	jump = false;
	this->sprite = sprite;
	sprite->setObjSize(OBJSIZE_32);
	
	// Load the sprite palette.
//	dmaCopy(mario_crouchPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_crouchPaletteLength);

	update(sprite);
}

void CMarioJump::loadJump() {
	curImage = 0;
	numImages = 3;
	spriteOffset = 15;
	jump = true;
	

	// Load the sprite palette.
//	dmaCopy(mario_jumpPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_jumpPaletteLength);

	update(sprite);
	
}