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
	isJumping = false;
	isAnimated = true;
	isLookingRight = true;
	curAnimation = &aniIdle;
	angle = 0;

	curAnimation->load();
	
}

void CMario::update() {
	spriteEntry->posX =  (u16)(posX + curAnimation->getXOffset());
	spriteEntry->posY = (u16)(posY + curAnimation->getYOffset());

	curAnimation->update(tileIndex);
}

void CMario::updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ) {
	
	if(keys_up & KEY_DOWN && !isJumping )
	{
		if( curAnimation != &aniCrouch )
			assert(false);
		curAnimation->forceUnlock();
		curAnimation->update(tileIndex);
		return;
	}
	
	// All animations below require the animation to be UNLOCKED before they can run...
	if( curAnimation->isLocked() )
		return;		//don't do anything

	//TODO: fix error where if you press something while running, it doesnt return to idle after releasing the run button..
	
	if( !key_pressed && !(curAnimation->isLocked()) )
	{
		if( curAnimation != &aniIdle )
		{
			curAnimation = &aniIdle;
			curAnimation->load();
			curAnimation->update(tileIndex);
		}
		return;
	}
	
//UP
	if( keys_held & KEY_UP )
	{
		if( keys_up & KEY_A )
		{
			//TODO: write this
		}
		else if( keys_up & KEY_B )
		{
			//TODO: write this
		}
		//TODO: add others here...
		else {
			//jump
		}
		return;
	}
	
//DOWN
	if( keys_held & KEY_DOWN )
	{
		if( keys_up & KEY_A )
		{
			//TODO: write this
		}
		else if( keys_up & KEY_B )
		{
			//TODO: write this
		}
		//TODO: add others here...
		else {		//crouch
			if( curAnimation != &aniCrouch )
			{
				curAnimation = &aniCrouch;
				curAnimation->load();
				curAnimation->update(tileIndex);
			}
			return;
		}
		return;
	}
	
//Key A
	if( keys_up & KEY_A )
	{
		if( (curAnimation != &aniPAttack) )
			curAnimation = &aniPAttack;
		curAnimation->load();
		curAnimation->update(tileIndex);
		return;
	}
	
// Key B	
	if(keys_up & KEY_B)
	{
		//TODO: write this
		return;
	}

//Key X
	if(keys_up & KEY_X)
	{
		//TODO: write this
		return;
	}
	
//Key L
	if(keys_up & KEY_L)
	{
		//TODO: write this
		return;
	}
	
//Key R
	if(keys_up & KEY_R)
	{		
		//TODO: write this
		return;
	}	
	
	if( !(curAnimation->isLocked()) )
	{
		if(keys_held & KEY_LEFT)
		{
			if(getFacingDirection()!=FACING_LEFT)
				setFacingDirection(FACING_LEFT);
			
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load();
				curAnimation->update(tileIndex);
			}
			posX -= 3;
			return;
		}
		
		if(keys_held & KEY_RIGHT)
		{
			if(getFacingDirection()!=FACING_RIGHT)
				setFacingDirection(FACING_RIGHT);
		
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load();
				curAnimation->update(tileIndex);
			}
			//update position?
			posX += 3;
			return;
		}
	}
}

