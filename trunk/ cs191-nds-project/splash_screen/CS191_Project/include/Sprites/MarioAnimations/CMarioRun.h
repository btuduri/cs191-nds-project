#ifndef CMARIORUN_H_
#define CMARIORUN_H_
#pragma once

#include "ProjectLib.h"
#include "CAnimation.h"
//#include "../graphics/mario_run.h"
#include "../graphics/mario_sprites.h"

class CMarioRun : public CAnimation
{
public:
	CMarioRun();
	virtual ~CMarioRun();

	void update(CSprite *sprite);
	void load(CSprite *sprite);
	
private:
	u16 curImage;
};

#endif /*CMARIORUN_H_*/
