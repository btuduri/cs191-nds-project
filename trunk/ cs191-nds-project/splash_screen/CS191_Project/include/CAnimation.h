#ifndef CANIMATION_H_
#define CANIMATION_H_

#include "ProjectLib.h"

#define IMAGE_SIZE_64x64 4096
#define IMAGE_SIZE_64x64H 2048	// the way images are outputted, the array size is 1/2 the size of the image

class CAnimation
{
public:
	CAnimation();
	virtual ~CAnimation();

	virtual void update(u16 index)=0;
	virtual void load()=0;
	
	bool isLocked() { return locked; }
	void forceUnlock() { locked = false; }
	void forceLock() { locked = true; }
	
	u16 getXOffset(){ return xoffset; }
	u16 getYOffset(){ return yoffset; }
	
protected:
//	u16 startTitleIndex;
	u16 numImages;
	bool locked;
	u16 xoffset;
	u16 yoffset;
	u16 imageSize;			// usually 32-bits
};

#endif /*CANIMATION_H_*/
