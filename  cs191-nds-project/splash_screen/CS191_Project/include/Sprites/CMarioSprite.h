#pragma once

#ifndef CMARIOSPRITE_H_
#define CMARIOSPRITE_H_

#include "ProjectLib.h"
#include "CMovableSprite.h"
#include "CControlKeys.h"
#include "CCollisionManager.h"

#include "../graphics/mario_sprites.h"

#include "MarioAnimations/CMarioCrouch.h"
#include "MarioAnimations/CMarioIdle.h"
#include "MarioAnimations/CMarioJump.h"
#include "MarioAnimations/CMarioPAttack.h"
#include "MarioAnimations/CMarioRun.h"
#include "MarioAnimations/CMarioWalk.h"

//definitions
#define MARIO_JUMP_VELOCITY -12.0
#define MARIO_RUN_VELOCITY 10.0
#define MARIO_JUMP_AMOUNT 10

class CMarioSprite : public CMovableSprite, public CControlKeys {

public:
	virtual ~CMarioSprite();

	void initSprite();
	
	void update();
//	void updateAnimation( bool key_pressed, u32 keys_down, u32 keys_up, u32 keys_held ) {};
	
	void noKeysPressed();
	void dPadKey(Direction d);	
	void aKey(Direction d);
	void bKey(Direction d);
	void xKey(Direction d);
	void yKey(Direction d);
	void leftKey(Direction d);
	void rightKey(Direction d);
	void startKey();
	void selectKey();
	
	void setCollisionManager(CCollisionManager * ccm){ cm = ccm; }
	
private:
	
	void jumping();
	void falling();
	
	CMarioIdle aniIdle;

//	CMarioIdle aniJump;
//	CMarioIdle aniPAttack;
//	CMarioIdle aniRun;
//	CMarioIdle aniWalk;
//	CMarioIdle aniCrouch;

	
	CMarioJump aniJump;
	CMarioPAttack aniPAttack;
	CMarioRun aniRun;
	CMarioWalk aniWalk;
	CMarioCrouch aniCrouch;
	
	CCollisionManager *cm;
	bool goingUp;
	int jumpAmount;
//	u32 xoffset;
//	u32 yoffset;
	
};

#endif /*CMARIOSPRITE_H_*/
