#include "CMario.h"

CMario::~CMario()
{
}

void CMario::initSprite() {
	
	//Initalize the spriteEntry info.  Most of this isn't changed after we've set this.
	//Possible vars to change are: tileIdx, X and Y pos, and isHidden.
	spriteEntry->colMode = OBJCOLOR_256;
	spriteEntry->objMode = OBJMODE_NORMAL;
	spriteEntry->objShape = OBJSHAPE_SQUARE;
	spriteEntry->objSize = OBJSIZE_64;
	spriteEntry->objPriority = OBJPRIORITY_0;
	spriteEntry->tileIdx = 0;
	spriteEntry->isRotoscale = true;
//	spriteEntry->isMosaic = false;
	spriteEntry->rsMatrixIdx = ATTR1_ROTDATA(0);
	//spriteEntry->attribute[0] = ATTR0_COLOR_256 | ATTR0_ROTSCALE_DOUBLE | 75;
	//	spriteEntry->rsMatrixIdx = ATTR1_ROTDATA(1);
	setPosition(10, 120);
	spriteEntry->isHidden = false;
    //spriteEntry->hFlip = true;

	// Default the animation lock to false
	locked = false;
	isAnimated = true;
	curAnimation = &aniPAttack;
	angle = 0;

	//rotateSprite(30);
	curAnimation->load();

}

void CMario::update() {
	
	curAnimation->update(spriteEntry);
	
}
