#ifndef CSPRITE_H_
#define CSPRITE_H_
#pragma once

#include "ProjectLib.h"
#include "CBasicObject.h"

#define SPRITE_ANGLE_MASK 0x01FF
#define FACING_LEFT false
#define FACING_RIGHT true

static const int BYTES_PER_16_COLOR_TILE = 32;
static const int COLORS_PER_PALETTE = 16;
static const int BOUNDARY_VALUE = 32; /* This is the default boundary value
                                           * (can be set in REG_DISPCNT) */
static const int OFFSET_MULTIPLIER = BOUNDARY_VALUE /
                                         sizeof(SPRITE_GFX[0]);

static const int SPRITE_DMA_CHANNEL = 3;


class CSprite : public CBasicObject {
public:
	CSprite(){ locked = true; }
	CSprite( SpriteEntry * se );
	virtual ~CSprite();

	// Handle sprite specific code here.  Ie. Rotation, Hidden, etc	
	void setSpriteVisibility(bool hidden);
	void setPosition(float x, float y);	
	
	int radToDeg512(float rad);
	u16 getAngleDeg512(){ return radToDeg512(angle); }
	
	virtual void initSprite() = 0;
	virtual void update(){}				// only sprites with animations need to implement the update() funtion
	virtual void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ){}

	//rotation
	void setSpriteRotation(SpriteRotation *sr) { spriteRotation = sr; }
	void setSpriteRotationIndex( u8 index ) { rotIndex = index; spriteEntry->rsMatrixIdx = index;/*ATTR1_ROTDATA(index);*/ }
	float getAngleRad(){ return angle; }
	u8 getRotIndex() { return rotIndex; }
	
	// Handle sprite variable code here (getters/setters)
	void setTileIndex(int index){ spriteEntry->tileIdx = index; }
	void setSpriteEntry(SpriteEntry *se) { spriteEntry = se; }
	bool isSpriteHidden(){return spriteEntry->isHidden;}
	
	// direction
	void setFacingDirection(bool isRight);
	void toggleFacingDirection();
	bool getFacingDirection(){ return isLookingRight; }
	
protected:
	bool locked;
	u32 tileIndex;
	
	u8 rotIndex;
	bool affine;				//the image is affected by affine matrices
	bool doubleBound;			//used to increase the boundry limit of the image (if the rotation becomes clipped)
	bool isAnimated;
	bool isLookingRight;				//used to keep track of which way the sprite is facing (true for right, false for left)
	
	float angularVelocity;
	float angle;				// in radians
	
	u16 spriteSize;
	
	SpriteEntry *spriteEntry;
	SpriteRotation *spriteRotation;
	
};

#endif /*CSPRITE_H_*/
