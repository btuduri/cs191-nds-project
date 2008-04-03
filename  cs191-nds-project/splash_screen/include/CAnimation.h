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
	
protected:
	u16 startTitleIndex;
	u16 numImages;
};

#endif /*CANIMATION_H_*/
