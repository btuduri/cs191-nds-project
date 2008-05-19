#ifndef CMARIOJUMP_H_
#define CMARIOJUMP_H_
#pragma once

#include "ProjectLib.h"
#include "CAnimation.h"

// jump animation, is basically crouch + jump
//#include "../graphics/mario_crouch.h"
//#include "../graphics/mario_jump.h"
#include "../graphics/mario_sprites.h"


class CMarioJump : public CAnimation
{
public:
	CMarioJump();
	virtual ~CMarioJump();
	
	void update(CSprite *sprite);
	void load(CSprite *sprite);

	void loadJump();
	
private:

	bool jump;
	CSprite *sprite;
	u16 curImage;
};

#endif /*CMARIOJUMP_H_*/
