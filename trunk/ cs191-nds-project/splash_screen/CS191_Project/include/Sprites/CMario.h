#pragma once

#ifndef CMARIO_H_
#define CMARIO_H_

#include "ProjectLib.h"
//#include "gfx/smmario.h"


#include "MarioAnimations/CMarioCrouch.h"
#include "MarioAnimations/CMarioIdle.h"
#include "MarioAnimations/CMarioPAttack.h"
#include "MarioAnimations/CMarioRun.h"
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
	void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held );
	
	
private:
	
	CAnimation * curAnimation;
	
	CMarioCrouch aniCrouch;
	CMarioIdle aniIdle;
	CMarioPAttack aniPAttack;
	CMarioRun aniRun;
	CMarioWalk aniWalk;
	
//	u32 xoffset;
//	u32 yoffset;
	
};

#endif /*CMARIO_H_*/
