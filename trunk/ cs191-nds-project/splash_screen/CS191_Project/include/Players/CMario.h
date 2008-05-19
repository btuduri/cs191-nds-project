#ifndef CMARIO_H_
#define CMARIO_H_

#include "ProjectLib.h"
#include "CPlayer.h"
#include "CMarioSprite.h"

class CMario : public CPlayer {
public:
	
	CMario();
	
	CMarioSprite * getSprite() { return &marioSprite; }
	
	void noKeysPressed() { return marioSprite.noKeysPressed(); }
	
	// directional
	void dPadKey(Direction d){ return marioSprite.dPadKey(d); }		

	// main buttons	
	void aKey(Direction d){ return marioSprite.aKey(d); }
	void bKey(Direction d){ return marioSprite.bKey(d); }
	void xKey(Direction d){ return marioSprite.xKey(d); }
	void yKey(Direction d){ return marioSprite.yKey(d); }

	// index buttons
	void leftKey(Direction d){ return marioSprite.leftKey(d); }
	void rightKey(Direction d){ return marioSprite.rightKey(d); }

	// operational
	void startKey(){ return marioSprite.startKey(); }
	void selectKey(){ return marioSprite.selectKey(); }
	
private:
	
	CMarioSprite marioSprite;
	
};


#endif /*CMARIO_H_*/
