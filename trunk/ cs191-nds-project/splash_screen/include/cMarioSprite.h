#ifndef CMARIOSPRITE_H_
#define CMARIOSPRITE_H_

#include "cSprite.h"
#include "CAnimation.h"
class cMarioSprite : public cSprite
{
public:
	cMarioSprite();
	virtual ~cMarioSprite();
	void updateSprite(int keys);
	/*CAnimation duckAnimation;
	CAnimation idleAnimation;
	CAnimation walkAnimation;
	CAnimation runAnimation;
	CAnimation jumpAnimation;
	CAnimation punchAnimation;
	CAnimation ability1Animation;
	CAnimation ability2Animation;
	CAnimation ability3Animation;
	CAnimation blockAnimation;*/

};

#endif /*CMARIOSPRITE_H_*/
