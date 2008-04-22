#pragma once

#ifndef CMARIO_H_
#define CMARIO_H_

#include "ProjectLib.h"
//#include "gfx/smmario.h"


#include "MarioAnimations/CMarioCrouch.h"
#include "MarioAnimations/CMarioIdle.h"
#include "MarioAnimations/CMarioJump.h"
#include "MarioAnimations/CMarioPAttack.h"
#include "MarioAnimations/CMarioRun.h"
#include "MarioAnimations/CMarioWalk.h"

//definitions
#define JUMP_VELOCITY 10.0
#define RUN_VELOCITY 10.0



class CMario : public CMovableSprite
{
public:
	virtual ~CMario();

	void initSprite();
	
	void update();
	void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held );
	
	
private:
	bool inAir;
	
	CAnimation * curAnimation;
	
	CMarioCrouch aniCrouch;
	CMarioIdle aniIdle;
	CMarioJump aniJump;
	CMarioPAttack aniPAttack;
	CMarioRun aniRun;
	CMarioWalk aniWalk;
	
//	u32 xoffset;
//	u32 yoffset;
	
};

#endif /*CMARIO_H_*/
