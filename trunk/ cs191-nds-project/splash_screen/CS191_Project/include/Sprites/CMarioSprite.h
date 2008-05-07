#pragma once

#ifndef CMARIOSPRITE_H_
#define CMARIOSPRITE_H_

#include "ProjectLib.h"
#include "CMovableSprite.h"
#include "CControlKeys.h"

#include "MarioAnimations/CMarioCrouch.h"
#include "MarioAnimations/CMarioIdle.h"
#include "MarioAnimations/CMarioJump.h"
#include "MarioAnimations/CMarioPAttack.h"
#include "MarioAnimations/CMarioRun.h"
#include "MarioAnimations/CMarioWalk.h"

//definitions
#define MARIO_JUMP_VELOCITY 10.0
#define MARIO_RUN_VELOCITY 10.0

class CMarioSprite : public CMovableSprite {

public:
	virtual ~CMarioSprite();

	void initSprite();
	
	void update();
	void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held );
	
	void leftKey();
	void rightKey();
	void upKey();
	void downKey();
	
private:
	
	CMarioIdle aniIdle;
	CMarioJump aniJump;
	CMarioPAttack aniPAttack;
	CMarioRun aniRun;
	CMarioWalk aniWalk;
	CMarioCrouch aniCrouch;
	
//	u32 xoffset;
//	u32 yoffset;
	
};

#endif /*CMARIOSPRITE_H_*/
