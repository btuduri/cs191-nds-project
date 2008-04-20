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
	inAir = false;
	isAnimated = true;
	isLookingRight = true;
	curAnimation = &aniIdle;
	angle = 0;

	curAnimation->load(spriteEntry);
	
}

void CMario::update() {
//	spriteEntry->posX =  (u16)(posX + curAnimation->getXOffset());
//	spriteEntry->posY = (u16)(posY + curAnimation->getYOffset());

	if( inAir )
	{
//		gravity();
	}
		
	curAnimation->update(spriteEntry);

	updatePosition(curAnimation->getXOffset(), curAnimation->getYOffset());

}

void CMario::updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ) {
	
//	if( inAir && !(keys_held & KEY_UP) )
//	{
//		posY -= 3;
//		if( posY > SCREEN_WIDTH/3)
//			inAir = false;
//	}
		
//	if(keys_up & KEY_DOWN && !inAir )
//	{
//		if( curAnimation != &aniCrouch )
//			assert(false);
////		curAnimation->forceUnlock();
//		return;
//	}
	
	// All animations below require the animation to be UNLOCKED before they can run...
//	if( curAnimation->isLocked() )
//		return;		//don't do anything

	//TODO: fix error where if you press something while running, it doesnt return to idle after releasing the run button..
	
	if( !key_pressed && !curAnimation->isLocked())
	{
		if( curAnimation != &aniIdle )
		{
			curAnimation = &aniIdle;
			curAnimation->load(spriteEntry);
			update();
		}
//		return;
	}
	
//UP
	if( (keys_held & KEY_UP) || (keys_down & KEY_UP) )
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
			if( curAnimation != &aniJump )
			{
				inAir = true;
				curAnimation = &aniJump;
				curAnimation->load(spriteEntry);
				setYVelocity(-JUMP_VELOCITY);
				update();
			}
//			errColor.green();
//			Error();
		}
//		return;
	}
	
//DOWN

	if( ((keys_down & KEY_DOWN) || (keys_held & KEY_DOWN)) &&  (keys_up & KEY_A) )
	{
		errColor.cyan();
		Error();
		//TODO: write this
	}
	
	if( ((keys_down & KEY_DOWN) || (keys_held & KEY_DOWN)) &&  (keys_up & KEY_B) )
	{
		errColor.blue();
		Error();
		//TODO: write this
	}
	//TODO: add others here...
	
	//crouch
	if( (keys_down & KEY_DOWN) || (keys_up & KEY_DOWN) )
	{
		if( curAnimation != &aniCrouch )
		{
			curAnimation = &aniCrouch;
			setXVelocity(0);
		}
		curAnimation->load(spriteEntry);
		//		return;
	}
		
//Key A
	if( keys_up & KEY_A )
	{
		if( (curAnimation != &aniPAttack) )
		{
			curAnimation = &aniPAttack;
			update();
		}
		curAnimation->load(spriteEntry);
//		return;
	}
	
// Key B	
	if(keys_up & KEY_B)
	{
		//TODO: write this
//		return;
	}

//Key X
	if(keys_up & KEY_X)
	{
		//TODO: write this
//		return;
	}
	
//Key L
	if(keys_up & KEY_L)
	{
		//TODO: write this
//		return;
	}
	
//Key R
	if(keys_up & KEY_R)
	{		
		//TODO: write this
//		return;
	}	
	
	if( !(curAnimation->isLocked()) )
	{
		if( (keys_down & KEY_LEFT) || (keys_held & KEY_LEFT) )
		{
			if(getFacingDirection()!= FACING_LEFT)
				setFacingDirection(FACING_LEFT);
			
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load(spriteEntry);
				update();
			}
			setXVelocity(-RUN_VELOCITY);

//			errColor.yellow();
//			Error();
//			return;
		}
		
		if( keys_up & KEY_LEFT  &&  !(keys_held & KEY_RIGHT) )
		{
			setXVelocity(0);
		}
		
		if( (keys_down & KEY_RIGHT)  || (keys_held & KEY_RIGHT) )
		{
			if(getFacingDirection()!=FACING_RIGHT)
				setFacingDirection(FACING_RIGHT);
		
			if( (curAnimation != &aniRun) )
			{
				curAnimation = &aniRun;
				curAnimation->load(spriteEntry);
				update();
			}
			setXVelocity(RUN_VELOCITY);
//			errColor.cyan();
//			Error();
			return;
		}
		
		if( keys_up & KEY_RIGHT   &&  !(keys_held & KEY_LEFT) )
		{
			setXVelocity(0);
		}

	}
}

