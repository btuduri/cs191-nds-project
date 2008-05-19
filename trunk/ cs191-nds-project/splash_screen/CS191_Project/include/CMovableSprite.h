#ifndef CMOVABLESPRITE_
#define CMOVABLESPRITE_
#pragma once

#include "ProjectLib.h"
#include "CSprite.h"
#include "CPhysics.h"
#include "CAnimation.h"

class CMovableSprite : public CSprite, public CPhysics {

public:
	CMovableSprite();
	CMovableSprite(SpriteEntry *se);
	
	void updatePosition();
	void updateAngle();
	void rotateSprite();
	u16 getSpriteWidth() { return curAnimation->getImageSize(); }

	float getRunVelocity(){ return runVelocity; }
	float getJumpVelocity(){ return jumpVelocity; }
	
	// rotation and angle
	float getAngularVelocity(){return angularVelocity;}
	void setAngleRad(float angle) {this->angle = angle; }
	void setRotIndex( int index ) { rotIndex = index; }
	void setAngularVelocity(float v){angularVelocity = v;}
	
	void lockXMobility() { xMobility = false; }
	void unlockXMobility() { xMobility = true; }
	bool getXMobility(){ return xMobility; }
	
	void lockYMobility() { yMobility = false; }
	void unlockYMobility() { yMobility = true; }
	bool getYMobility(){ return yMobility; }
	
	bool allowedMobile(){ if( curAnimation != NULL ) return curAnimation->allowedMobile(); else return false; }
	
	int getRelationToCenter();
	bool toRightOfCenterScreen()	{ if(getRelationToCenter() == 1 )	return true; else return false; }
	bool toLeftOfCenterScreen() 	{ if(getRelationToCenter() == -1 )	return true; else return false; }
	bool isCenteredOnScreen()		{ if(getRelationToCenter() == 0) 	return true; else return false; } 


protected:
	
	CAnimation * curAnimation;

	bool xMobility;
	bool yMobility;
	
	float runVelocity;
	float jumpVelocity;
};

#endif /*CMOVABLESPRITE_*/
