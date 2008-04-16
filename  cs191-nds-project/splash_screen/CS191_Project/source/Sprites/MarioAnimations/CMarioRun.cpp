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
	
	curImage++;
	
	if(curImage == numImages)
		curImage = 0;
	
	se->tileIdx = curImage * 128;

}

void CMarioRun::load() {

	// Load the sprite palette.
	dmaCopy(mario_runPalette, SPRITE_PALETTE, mario_runPaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_runBitmap, SPRITE_GFX, mario_runBitmapLength);

}

