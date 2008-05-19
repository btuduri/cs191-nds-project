#ifndef CMARIOPATTACK_H_
#define CMARIOPATTACK_H_
#pragma once

//Primary attack
#include "ProjectLib.h"
#include "CAnimation.h"
//#include "../graphics/mario_pattack1.h"
//#include "../graphics/mario_pattack2.h"
//#include "../graphics/mario_pattack3.h"
#include "../graphics/mario_sprites.h"

#define MAX_ATTACKS 3

class CMarioPAttack : public CAnimation
{
public:
	CMarioPAttack();
	virtual ~CMarioPAttack();

	void update(CSprite *sprite);
	void load(CSprite *sprite);
			
private:
	void loadA();		// first punch
	void loadB();		// second punch
	void loadC();		// kick
	
//	u16 nextImage;
	u16 curImage;
	
/*	enum attack_type{
		attack1,
		attack2,
		attack3
	};*/
	u16 tileIdx;
	u8 attack;		// 0, 1, or 2
	u8 numAttacks;
	
//	bool nextAttack;
	
};

#endif /*CMARIOPATTACK_H_*/
