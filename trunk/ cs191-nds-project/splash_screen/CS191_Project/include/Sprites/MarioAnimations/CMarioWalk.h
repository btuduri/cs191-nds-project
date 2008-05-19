#ifndef CMARIOWALK_H_
#define CMARIOWALK_H_
#pragma once

//TODO: change this to the walk animation...

#include "ProjectLib.h"
#include "CAnimation.h"
//#include "../graphics/mario_idle.h"
#include "../graphics/mario_sprites.h"

class CMarioWalk : public CAnimation
{
public:
	CMarioWalk();
	virtual ~CMarioWalk();
	
	void update(CSprite *sprite);
	void load(CSprite *sprite);
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOWALK_H_*/
