#ifndef CSPRITE_H_
#define CSPRITE_H_

#include "projectlib.h"

class cSprite
{
public:
	cSprite();
	cSprite(SpriteEntry * ptr, SpriteRotation * rPtr, u16 newX, u16 newY) {
		spriteEntryPtr = ptr;
		spriteRotPtr = rPtr;
		curX = newX;
		curY = newY;
	}
	virtual ~cSprite();
	void setPosition(u16 newX, u16 newY) { curX = newX; curY = newY; }
	u16 getXPos() { return curX; }
	u16 getYPos() { return curY; }
	bool isAnimated() { return animated; }
	virtual void updateSprite(int keys) = 0;
	void setSpriteBuffer(SpriteEntry * ptr) { spriteEntryPtr = ptr; }
	void setSpriteRotation(SpriteRotation * ptr) { spriteRotPtr = ptr; }
private:
	u16 curX;
	u16 curY;
	SpriteEntry * spriteEntryPtr;
	SpriteRotation * spriteRotPtr;
	bool animated;
};

#endif /*CSPRITE_H_*/
