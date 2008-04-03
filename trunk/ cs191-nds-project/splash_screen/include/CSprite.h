#pragma once

#ifndef CSPRITE_H_
#define CSPRITE_H_

#include "ProjectLib.h"

#define SPRITE_ANGLE_MASK 0x01FF
#define PI (3.14159265358979323846264338327)

//usage:  MathVector2D<var_type> var_name;
template <class T>
struct MathVector2D {
    T x;
    T y;
};

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
	
	// Handle sprite variable code here (getters/setters)
	u8 getIndex(){ return index; }
	u8 getRotIndex() { return rotIndex; }
	void setIndex( int index ){ this->index = index; }
	void setRotIndex( int index ) { rotIndex = index; }
	void setSpriteEntry(SpriteEntry *se) { spriteEntry = se; }
	void setSpriteRotation(SpriteRotation *sr) { spriteRotation = sr; }
	void setSpriteRotationIndex( u8 index ) { rotIndex = index; }
	float getAngleRad(){ return angle; }
	u16 getAngleDeg512(){ return radToDeg512(angle); }
	void setAngleRad(float angle) {this->angle = angle; }
	
protected:
	bool locked;
	u8 index;
	u8 rotIndex;
	bool affine;				//the image is affected by affine matrices
	bool doubleBound;			//used to increase the boundry limit of the image (if the rotation becomes clipped)
	bool isAnimated;
	
	//MathVector2D<float> position;
	MathVector2D<float> velocity;
	float angle;				// in radians
	
	SpriteEntry *spriteEntry;
	SpriteRotation *spriteRotation;
	
};

#endif /*CSPRITE_H_*/
