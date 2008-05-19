#ifndef CMARIOCROUCH_H_
#define CMARIOCROUCH_H_
#pragma once

#include "ProjectLib.h"
#include "CAnimation.h"
//#include "../graphics/mario_crouch.h"
#include "../graphics/mario_sprites.h"

class CMarioCrouch : public CAnimation
{
public:
	CMarioCrouch();
	virtual ~CMarioCrouch();

	void update(CSprite *sprite);
	void load(CSprite *sprite);
	//overloaded
	void forceUnlock();
	
	void setIsCrouching(bool crouch) { isCrouching = crouch; }
		
private:
	bool isCrouching;
	u16 curImage;
};

#endif /*CMARIOCROUCH_H_*/
