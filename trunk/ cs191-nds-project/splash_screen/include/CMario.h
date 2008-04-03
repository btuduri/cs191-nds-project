#pragma once

#ifndef CMARIO_H_
#define CMARIO_H_

#include "ProjectLib.h"
//#include "gfx/smmario.h"


#include "MarioAnimations/CMarioCrouch.h"
#include "MarioAnimations/CMarioIdle.h"
#include "MarioAnimations/CMarioPAttack.h"
#include "MarioAnimations/CMarioWalk.h"


class CMario : public CSprite
{
public:
	virtual ~CMario();

	void initSprite();
	
	bool isLocked(){ return locked; }
	void forceLock() { locked = true; }
	void forceUnlock() { locked = false; }

	void update();
	
private:
	bool locked;
	CAnimation * curAnimation;
	
	CMarioCrouch aniCrouch;
	CMarioIdle aniIdle;
	CMarioPAttack aniPAttack;
	CMarioWalk aniWalk;
};

#endif /*CMARIO_H_*/
