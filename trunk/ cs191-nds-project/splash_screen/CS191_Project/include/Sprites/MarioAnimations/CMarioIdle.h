#ifndef CMARIOIDLE_H_
#define CMARIOIDLE_H_
#pragma once

#include "ProjectLib.h"
#include "CAnimation.h"
#include "../graphics/mario_idle.h"

class CMarioIdle : public CAnimation
{
public:
	CMarioIdle();
	virtual ~CMarioIdle();
	
	void update(SpriteEntry *se);
	void load(SpriteEntry *se);
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOIDLE_H_*/
