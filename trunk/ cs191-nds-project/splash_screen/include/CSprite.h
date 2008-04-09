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
	void rotateSprite();
	void rotateSprite(u16 a);
	void setSpriteVisibility(bool hidden);
	void setPosition(u16 x, u16 y);
	int radToDeg512(float rad);
	
	virtual void initSprite() = 0;
	virtual void update(){}				// only sprites with animations need to implement the update() funtion
	virtual void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ){}

	
	// Handle sprite variable code here (getters/setters)
	u8 getIndex(){ return index; }
	u8 getRotIndex() { return rotIndex; }
	void setIndex( int index ){ this->index = index; }
	void setTileIndex(int index){ spriteEntry->tileIdx = index; }
	void setRotIndex( int index ) { rotIndex = index; }
	void setSpriteEntry(SpriteEntry *se) { spriteEntry = se; }
	void setSpriteRotation(SpriteRotation *sr) { spriteRotation = sr; }
	void setSpriteRotationIndex( u8 index ) { rotIndex = index; }
	float getAngleRad(){ return angle; }
	u16 getAngleDeg512(){ return radToDeg512(angle); }
	void setAngleRad(float angle) {this->angle = angle; }
	void setDirection(bool isRight);
	void toggleDirection();
	bool getDirection(){ return isLookingRight; }
	
protected:
	bool locked;
	u8 index;
	u8 rotIndex;
	bool affine;				//the image is affected by affine matrices
	bool doubleBound;			//used to increase the boundry limit of the image (if the rotation becomes clipped)
	bool isAnimated;
	bool isLookingRight;				//used to keep track of which way the sprite is facing (true for right, false for left)
	
	u16 posX;
	u16 posY;
	
	float velocityX;
	float velocityY;
	float angle;				// in radians
	u16 spriteSize;
	
	SpriteEntry *spriteEntry;
	SpriteRotation *spriteRotation;
	
};

#endif /*CSPRITE_H_*/
