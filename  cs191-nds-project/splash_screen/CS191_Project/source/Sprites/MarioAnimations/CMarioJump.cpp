#include "CMarioJump.h"

CMarioJump::CMarioJump()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 3;
	animationLocked = false;
	imageSize = 32;
}

CMarioJump::~CMarioJump()
{
}

void CMarioJump::update(SpriteEntry *se) {

	if( jump ) {
	
		dmaCopy(	(void*)&mario_jumpBitmap[curImage * IMAGE_SIZE_32x32H],
	    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
	    			IMAGE_SIZE_32x32);

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

		dmaCopy(	(void*)&mario_crouchBitmap[curImage * IMAGE_SIZE_32x32H],
	    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
	    			IMAGE_SIZE_32x32);

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

void CMarioJump::load(SpriteEntry *se) {
	mobilityLocked = true;
	curImage = 0;
	numImages = 2;
	jump = false;
	this->se = se;
	
	se->objSize = OBJSIZE_32;
	
//	tileIdx = se->tileIdx;

	// Load the sprite palette.
	dmaCopy(mario_crouchPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_crouchPaletteLength);

	update(se);
}

void CMarioJump::loadJump() {
	curImage = 0;
	numImages = 3;
	jump = true;

	// Load the sprite palette.
	dmaCopy(mario_jumpPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_jumpPaletteLength);

	update(se);
	
}