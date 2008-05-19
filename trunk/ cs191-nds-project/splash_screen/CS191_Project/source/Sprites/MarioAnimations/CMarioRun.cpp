#include "CMarioRun.h"

CMarioRun::CMarioRun()
{	
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 8;
	imageSize = 32;
	spriteOffset = 5;
}

CMarioRun::~CMarioRun()
{
}

void CMarioRun::update(CSprite *sprite) {
	
	dmaCopy(	(void*)&mario_spritesBitmap[(spriteOffset+curImage) * IMAGE_SIZE_32x32H],
				SPRITE_GFX+(4096*sprite->getSpriteIndex()),
    			IMAGE_SIZE_32x32);
	
	curImage++;
	
	if(curImage == numImages)
		curImage = 0;
}

void CMarioRun::load(CSprite *sprite) {

	sprite->setObjSize(OBJSIZE_32);
	curImage = 0;
	update(sprite);
	// Load the sprite palette.
//	dmaCopy(mario_runPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_runPaletteLength);

//	update(se);
}

