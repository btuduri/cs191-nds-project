#include "CMarioSprite.h"

CMarioSprite::~CMarioSprite()
{
}

void CMarioSprite::initSprite() {
	
	//Initalize the spriteEntry info.  Most of this isn't changed after we've set this.
	//Possible vars to change are: tileIdx, X and Y pos, and isHidden.
	spriteEntry->colMode = OBJCOLOR_256;
	spriteEntry->objMode = OBJMODE_NORMAL;
	spriteEntry->objShape = OBJSHAPE_SQUARE;
	spriteEntry->objSize = OBJSIZE_32;
	spriteEntry->objPriority = OBJPRIORITY_0;	
	spriteEntry->rsMatrixIdx = ATTR1_ROTDATA(0);
	spriteEntry->tileIdx = 0;
	spriteEntry->isRotoscale = false;
	spriteEntry->isHidden = false;
	
	setPosition(SCREEN_WIDTH/2-32, 120);
	setDimensions(32,32);

	// Default the animation lock to false
	locked = false;
	xMobility = false;
	yMobility = false;
	inAir = false;
	goingUp = false;
	isAnimated = true;
	isLookingRight = true;
	curAnimation = &aniIdle;
	angle = 0;
	jumpAmount = 0;
	runVelocity = MARIO_RUN_VELOCITY;
	jumpVelocity = MARIO_JUMP_VELOCITY;
	
	offset64bit = 20;
	
	// copy over the palette.
	// In this case we only use 1 palette (all sprites on the same sheet, wooo!)
	dmaCopy(mario_spritesPalette, SPRITE_PALETTE, mario_spritesPaletteLength);
	
	curAnimation->load(this);
	
}

void CMarioSprite::update() {
	
	curAnimation->update(this);
	
//	if(curAnimation->allowedMobile()) {
		if( inAir )
		{
			if( !goingUp )
			{
				if( cm->checkObjectCollisions(this, getX(), getY()-MARIO_JUMP_VELOCITY-2) )
				{
					if( cm->getLastObjectTouched()->getCollisionDirection() == CBasicObject::CDtop )
					{
						setY((cm->getLastObjectTouched()->getY())-getHeight());
						inAir = false;
						setYVelocity(0);
					}
				}				
			}
			else
				falling();
//			gravity();
		}
		else
		{
			if( !cm->checkObjectCollisions(this, getX(), getY()-MARIO_JUMP_VELOCITY-2) ) //make sure we're on ground
			{
				inAir = true;
				falling();

				if( curAnimation != &aniJump )
				{
					unlockYMobility();
					curAnimation = &aniJump;
					aniJump.loadJump();
					setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
//					update();
				}
			}
		}
		
		updatePosition();
//	}
	
}

void CMarioSprite::falling() {

	jumpAmount--;
	if(jumpAmount <= 0)
	{
		goingUp = false;
		unlockYMobility();
		setYVelocity((-MARIO_JUMP_VELOCITY)-2);
	}
		
}

void CMarioSprite::jumping() {
	
	jumpAmount = MARIO_JUMP_AMOUNT;
	goingUp = true;
}

/*
void CMarioSprite::updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ) {
	
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
	
	if( !key_pressed && !curAnimation->isAnimationLocked() && !inAir )
	{
		if( curAnimation != &aniIdle )
		{
			curAnimation = &aniIdle;
			curAnimation->load(spriteEntry);
			update();
		}
//		return;
	}
	
	if( !key_pressed )	// no need to update anthing else if nothing was pressed
		return;
	
//UP
	if( (keys_held & KEY_UP) || (keys_down & KEY_UP) )
	{
		if( keys_up & KEY_A )
		{
		}
		else if( keys_up & KEY_B )
		{
		}
		else {
			//jump
			if( curAnimation != &aniJump )
			{
				inAir = true;
				curAnimation = &aniJump;
				curAnimation->load(spriteEntry);
				setYVelocity(-MARIO_JUMP_VELOCITY);
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
//		errColor.cyan();
//		Error();
	}
	
	if( ((keys_down & KEY_DOWN) || (keys_held & KEY_DOWN)) &&  (keys_up & KEY_B) )
	{
//		errColor.blue();
//		Error();
	}
	
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
//		return;
	}

//Key X
	if(keys_up & KEY_X)
	{
//		return;
	}
	
//Key L
	if(keys_up & KEY_L)
	{
//		return;
	}
	
//Key R
	if(keys_up & KEY_R)
	{		
//		return;
	}	
	
//	if( !(curAnimation->isAnimationLocked()) )
//	{
//		if( (keys_down & KEY_LEFT) || (keys_held & KEY_LEFT) )
//		{
//			setXVelocity(-RUN_VELOCITY);

//			errColor.yellow();
//			Error();
//			return;
//		}
		
//		if( keys_up & KEY_LEFT  &&  !(keys_held & KEY_RIGHT) )
//		{
//			setXVelocity(0);
//		}
		
//		if( (keys_down & KEY_RIGHT)  || (keys_held & KEY_RIGHT) )
//		{
//			if(getFacingDirection()!=FACING_RIGHT)
//				setFacingDirection(FACING_RIGHT);
//		
//			if( (curAnimation != &aniRun) )
//			{
//				curAnimation = &aniRun;
//				curAnimation->load(spriteEntry);
//				update();
//			}
//			setXVelocity(RUN_VELOCITY);
//			errColor.cyan();
//			Error();
//			return;
//		}
		

//	}
}*/

void CMarioSprite::noKeysPressed() {
	// Make sure the animation isn't locked
	if( curAnimation->isAnimationLocked() )
		return;
	
	if( inAir )
	{
		setXVelocity(0);
		return;
	}
	
	setXVelocity(0);
	setYVelocity(0);
	
	if( curAnimation != &aniIdle )
	{
		setObjSize(OBJSIZE_32);
//		spriteEntry->objSize = OBJSIZE_32;
		curAnimation = &aniIdle;
		setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
		curAnimation->load(this);
		update();
	}
}

void CMarioSprite::dPadKey(Direction d){

	switch(d) {
	
		case none: break;
	
		case left:		//run left
			if( curAnimation->isAnimationLocked() )
				return;
	
			if( (curAnimation != &aniRun) && !inAir  )
			{
				curAnimation = &aniRun;
				curAnimation->load(this);
				setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
				update();
			}
	
			if(getFacingDirection()!= FACING_LEFT)
				setFacingDirection(FACING_LEFT);
	
			setXVelocity(-getRunVelocity());
			break;
			
		case right:		//run right
			if( curAnimation->isAnimationLocked() )
				return;

			if(getFacingDirection()!= FACING_RIGHT)
				setFacingDirection(FACING_RIGHT);

			if( (curAnimation != &aniRun) && !inAir )
			{
				curAnimation = &aniRun;
				curAnimation->load(this);
				setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
				update();
			}
			
			setXVelocity(getRunVelocity());
			break;
			
		case up:		//jump

			if( curAnimation->isAnimationLocked() )
				return;

			if( curAnimation != &aniJump )
			{
				inAir = true;
				unlockYMobility();
				curAnimation = &aniJump;
				curAnimation->load(this);
				setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
				setYVelocity(MARIO_JUMP_VELOCITY);
				jumping();
				update();
			}
			break;

		case down:		// crouch
			if(inAir)
				return;
			
			if( curAnimation != &aniCrouch )
			{
				curAnimation = &aniCrouch;
				setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
				setXVelocity(0);
			}
			curAnimation->load(this);
			break;

		case leftUp:
			break;
		case leftDown:
			break;
		case rightUp:
			break;
		case rightDown:
			break;
	};
	
}


void CMarioSprite::aKey(Direction d) {
		switch(d) {
			
			case none:
				if( curAnimation != &aniPAttack )
				{
					curAnimation = &aniPAttack;
					setDimensions(curAnimation->getImageSize(), curAnimation->getImageSize());
					curAnimation->load(this);			
					update();
				}
				else 
					curAnimation->load(this);			

				break;
				
			case left:
				break;
			case right:
				break;
			case up:
				break;
			case down:
				break;
			case leftUp:
				break;
			case leftDown:
				break;
			case rightUp:
				break;
			case rightDown:
				break;
		};
}

void CMarioSprite::bKey(Direction d){}
void CMarioSprite::xKey(Direction d){}
void CMarioSprite::yKey(Direction d){}
void CMarioSprite::leftKey(Direction d){}
void CMarioSprite::rightKey(Direction d){}
void CMarioSprite::startKey(){}
void CMarioSprite::selectKey(){}
