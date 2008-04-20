#include "CMarioJump.h"

CMarioJump::CMarioJump()
{
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 3;
	locked = false;
	imageSize = 32;
}

CMarioJump::~CMarioJump()
{
}

void CMarioJump::update(SpriteEntry *se) {

	dmaCopy(	(void*)&mario_jumpBitmap[curImage * IMAGE_SIZE_32x32H],
    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_32x32);

	if( curImage < numImages )
	{
		curImage++;
	}
	else
	{
//		locked = false;
	}
}

void CMarioJump::load(SpriteEntry *se) {

	se->objSize = OBJSIZE_32;

//	locked = true;
	curImage = 0;

	// Load the sprite palette.
	dmaCopy(mario_jumpPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_jumpPaletteLength);

	update(se);
}

