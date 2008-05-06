#ifndef CANIMATION_H_
#define CANIMATION_H_
#pragma once

#include "ProjectLib.h"
#include "CSprite.h"

#define IMAGE_SIZE_32x32 1024
#define IMAGE_SIZE_32x32H 512	// the way images are outputted, the array size is 1/2 the size of the image
#define IMAGE_SIZE_64x64 4096
#define IMAGE_SIZE_64x64H 2048	// the way images are outputted, the array size is 1/2 the size of the image

#define MAX_PALETTE_SIZE 30


class CAnimation
{
public:
	CAnimation() {};
	virtual ~CAnimation() {}; 

	virtual void update(SpriteEntry *se)=0;
	virtual void load(SpriteEntry *se)=0;
	
	bool isAnimationLocked(){ return animationLocked; }
	void forceAnimationLock() { animationLocked = true; }
	void forceAnimationUnlock() { animationLocked = false; }
	
	bool allowedMobile(){ return !mobilityLocked; }
	void forceMobilityLock() { mobilityLocked = true; }
	void forceMobilityUnlock() { mobilityLocked = false; }
	
	
	u16 getXOffset(){ return xoffset; }
	u16 getYOffset(){ return yoffset; }
	
protected:

	u16 numImages;
	bool animationLocked;
	bool mobilityLocked;
	u16 xoffset;
	u16 yoffset;
	u16 imageSize;			// usually 32-bits

};

#endif /*CANIMATION_H_*/
