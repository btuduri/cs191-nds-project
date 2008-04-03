#ifndef CMARIOPATTACK_H_
#define CMARIOPATTACK_H_

//Primary attack
#include "../ProjectLib.h"
#include "../gfx/mario_pattack1.h"
#include "../gfx/mario_pattack2.h"
#include "../gfx/mario_pattack3.h"

class CMarioPAttack : public CAnimation
{
public:
	CMarioPAttack();
	virtual ~CMarioPAttack();

	void update(SpriteEntry *se);
	void load();
	
	void continueAttack();
	
private:
	void loadA();		// first punch
	void loadB();		// second punch
	void loadC();		// kick
	
	u16 nextImage;
	u16 curImage;
	
	enum attack_type{
		attack1,
		attack2,
		attack3
	};
	
	u8 attack;
	
	bool nextAttack;
	
};

#endif /*CMARIOPATTACK_H_*/
