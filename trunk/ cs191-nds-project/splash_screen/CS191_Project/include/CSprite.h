#pragma once

#ifndef CSPRITE_H_
#define CSPRITE_H_

#include "ProjectLib.h"

#define SPRITE_ANGLE_MASK 0x01FF
#define FACING_LEFT false
#define FACING_RIGHT true

class CSprite
{
public:
	CSprite(){ locked = true; }
	CSprite( SpriteEntry * se );
	virtual ~CSprite();

	// Handle sprite specific code here.  Ie. Rotation, Hidden, etc	
	void setSpriteVisibility(bool hidden);
	void setPosition(float x, float y);
	void rotateSprite();
	int radToDeg512(float rad);
	u16 getAngleDeg512(){ return radToDeg512(angle); }
	
	virtual void initSprite() = 0;
	virtual void update(){}				// only sprites with animations need to implement the update() funtion
	virtual void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ){}

	
	// Handle sprite variable code here (getters/setters)
	u8 getIndex(){ return index; }
	void setIndex( int index ){ this->index = index; }
	void setTileIndex(int index){ spriteEntry->tileIdx = index; }
	void setSpriteEntry(SpriteEntry *se) { spriteEntry = se; }
	bool isSpriteHidden(){return spriteEntry->isHidden;}

	// rotation and angle
	void setSpriteRotation(SpriteRotation *sr) { spriteRotation = sr; }
	void setSpriteRotationIndex( u8 index ) { rotIndex = index; spriteEntry->rsMatrixIdx = index;/*ATTR1_ROTDATA(index);*/ }
	float getAngleRad(){ return angle; }
	u8 getRotIndex() { return rotIndex; }
	float getAngularVelocity(){return angularVelocity;}
	void setAngleRad(float angle) {this->angle = angle; }
	void setRotIndex( int index ) { rotIndex = index; }
	void setAngularVelocity(float v){angularVelocity = v;}
	
	// direction
	void setFacingDirection(bool isRight);
	void toggleFacingDirection();
	bool getFacingDirection(){ return isLookingRight; }

	// x vars
	float getX(){return posX;}
	void setX(float x){posX = x;}
	float getXVelocity(){return xVelocity;}
	void setXVelocity(float vx){xVelocity = vx;}
	void toggleXVelocity(){xVelocity = -xVelocity;}

	// y vars
	float getY(){return posY;}
	void setY(float y){posY = y;}
	float getYVelocity(){return yVelocity;}
	void setYVelocity(float vy){yVelocity = vy;}
	void toggleYVelocity(){yVelocity = -yVelocity;}	
	
	void updatePosition();
	void updateAngle();
	
protected:
	bool locked;
	u8 index;
	u8 rotIndex;
	bool affine;				//the image is affected by affine matrices
	bool doubleBound;			//used to increase the boundry limit of the image (if the rotation becomes clipped)
	bool isAnimated;
	bool isLookingRight;				//used to keep track of which way the sprite is facing (true for right, false for left)
	
	float posX;
	float posY;
	
	float xVelocity;
	float yVelocity;
	float angularVelocity;
	float angle;				// in radians
	u16 spriteSize;
	
	SpriteEntry *spriteEntry;
	SpriteRotation *spriteRotation;
	
};

#endif /*CSPRITE_H_*/
