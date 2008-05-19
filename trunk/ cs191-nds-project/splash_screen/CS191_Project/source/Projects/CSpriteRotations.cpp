#include "Projects/CSpriteRotations.h"

CSpriteRotations::~CSpriteRotations()
{
}

void CSpriteRotations::initSprite() {
	
	//Initalize the spriteEntry info.  Most of this isn't changed after we've set this.
	//Possible vars to change are: tileIdx, X and Y pos, and isHidden.
	spriteEntry->colMode = OBJCOLOR_256;
	spriteEntry->objMode = OBJMODE_NORMAL;
	spriteEntry->objShape = OBJSHAPE_SQUARE;
	spriteEntry->objSize = OBJSIZE_64;
	spriteEntry->objPriority = OBJPRIORITY_0;	
	spriteEntry->rsMatrixIdx = ATTR1_ROTDATA(0);
	spriteEntry->tileIdx = 0;	
	spriteEntry->isRotoscale = true;
	spriteEntry->isHidden = false;
	
	// Default the animations lock to false
	locked = false;
	isAnimated = false;
	affine = true;
	
	setPosition(50,50);
}

void CSpriteRotations::update() {
	
	updatePosition();
	updateAngle();
	
	// Load the sprite palette.
	dmaCopy(sprite_rotationPalette, SPRITE_PALETTE_SUB, sprite_rotationPaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(sprite_rotationBitmap, SPRITE_GFX_SUB, sprite_rotationBitmapLength);	
}
