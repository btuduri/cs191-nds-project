#include "CMarioRun.h"
#include "graphics/mario_idle.h"

CMarioRun::CMarioRun()
{	
	xoffset = 0;
	yoffset = 0;
	curImage = 0;
	numImages = 8;
}

CMarioRun::~CMarioRun()
{
}

void CMarioRun::update(SpriteEntry *se) {
	
	dmaCopy(	(void*)&mario_runBitmap[curImage * IMAGE_SIZE_32x32H],
    			(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
    			IMAGE_SIZE_32x32);
	
	curImage++;
	
	if(curImage == numImages)
		curImage = 0;
}

void CMarioRun::load(SpriteEntry *se) {

	se->objSize = OBJSIZE_32;

	curImage = 0;
	
	// Load the sprite palette.
	dmaCopy(mario_runPalette, &SPRITE_PALETTE[se->tileIdx * MAX_PALETTE_SIZE], mario_runPaletteLength);

	update(se);
}

