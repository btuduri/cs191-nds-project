#ifndef CMARIOJUMP_H_
#define CMARIOJUMP_H_
#pragma once

#include "ProjectLib.h"
#include "CAnimation.h"

// jump animation, is basically crouch + jump
#include "../graphics/mario_crouch.h"
#include "../graphics/mario_jump.h"

class CMarioJump : public CAnimation
{
public:
	CMarioJump();
	virtual ~CMarioJump();
	
	void update(SpriteEntry *se);
	void load(SpriteEntry *se);
	
private:
	void loadJump();

	bool jump;
	SpriteEntry * se;
	u16 curImage;
};

#endif /*CMARIOJUMP_H_*/
