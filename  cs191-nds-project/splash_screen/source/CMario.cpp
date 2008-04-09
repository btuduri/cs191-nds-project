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
	spriteEntry->rsMatrixIdx = ATTR1_ROTDATA(0);
	spriteEntry->tileIdx = 0;	
	spriteEntry->isRotoscale = false;//true;
	spriteEntry->isHidden = false;
	setPosition(10, 120);
    //spriteEntry->hFlip = true;
	
	// Default the animation lock to false
	locked = false;
	isAnimated = true;
	isLookingRight = true;
//	curAnimation = &aniPAttack;
	curAnimation = &aniIdle;
	angle = 0;

	curAnimation->load();
//	curAnimation->load();
//	curAnimation->load();

//	xoffset = 0;
//	yoffset = 0;

}

void CMario::update() {
	spriteEntry->posX =  posX + curAnimation->getXOffset();
	spriteEntry->posY = posY + curAnimation->getYOffset();

	curAnimation->update(spriteEntry);
	
}

void CMario::updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ) {
	// A toggles freezing the system state.
//	if( curAnimation->isLocked() )
//		return;		//don't do anything

	//TODO: fix error where if you press something while running, it doesnt return to idle after releasing the run button..
	
	if( !key_pressed && !(curAnimation->isLocked()) )
	{
		if( curAnimation != &aniIdle )
		{
			curAnimation = &aniIdle;
			curAnimation->load();
			curAnimation->update(spriteEntry);
		}
		return;
	}

	if( /*key_pressed &&*/ (keys_up & KEY_A) )
	{
		if( (curAnimation != &aniPAttack) )
			curAnimation = &aniPAttack;
		curAnimation->load();
		curAnimation->update(spriteEntry);
	}

	if(keys_up & KEY_A)
	{
	}
	
	if(keys_up & KEY_X)
	{
	}
	
	// B make the system stop on collisions.
	if(keys_up & KEY_B)
	{
//	iprintf("\x1b[7;6HTrap Collisions: test...");
	}
	
	if(keys_up & KEY_L)
	{
	}
	
	if(keys_up & KEY_R)
	{		
	}
	
	
	if( !(curAnimation->isLocked()) )
	{
		if(keys_held & KEY_LEFT)
		{
			if(getDirection()!=FACING_LEFT)
				setDirection(FACING_LEFT);
			
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load();
			}
			posX -= 3;
		}
		
		if(keys_held & KEY_RIGHT)
		{
			if(getDirection()!=FACING_RIGHT)
				setDirection(FACING_RIGHT);
		
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load();
			}
			//update position?
			posX += 3;
	//		curAnimation->update(spriteEntry);
		}
	}
}

