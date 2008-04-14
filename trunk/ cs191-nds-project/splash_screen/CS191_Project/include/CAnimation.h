#ifndef CANIMATION_H_
#define CANIMATION_H_

#include "ProjectLib.h"

class CAnimation
{
public:
	CAnimation();
	virtual ~CAnimation();

	virtual void update(SpriteEntry *se)=0;
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
