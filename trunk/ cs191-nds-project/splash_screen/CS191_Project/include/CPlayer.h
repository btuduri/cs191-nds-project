#ifndef CPLAYER_H_
#define CPLAYER_H_
#pragma once

#include "ProjectLib.h"
#include "CControlKeys.h"
#include "CMovableSprite.h"
//#include "CMario.h"

class CPlayer : public CControlKeys {

public:
	
//	CPlayer();
	virtual ~CPlayer() {}
		
	float getPlayerX(){ return playerSprite->getX(); }
	float getPlayerY(){ return playerSprite->getY(); }
	float getPlayerWidth(){ return playerSprite->getWidth(); }
	float getPlayerHeight(){ return playerSprite->getHeight(); }

	void setPlayerX(float x){ playerSprite->setX(x); }
	void setPlayerY(float y){ playerSprite->setY(y); }
	void setPlayerWidth(float w){ playerSprite->setWidth(w); }
	void setPlayerHeight(float h){ playerSprite->setHeight(h); }
	
	void update(){
		if(playerSprite == NULL)
			return;
		playerSprite->update();
		
	}
	
	
	bool isPlayerAllowedMobile(){ return playerSprite->allowedMobile(); }
	bool isPlayerXMobile(){ return playerSprite->getXMobility();}
	bool isPlayerYMobile(){ return playerSprite->getYMobility();}
	bool isPlayerCollidable(){return playerSprite->isCollidable();}
	
	void setPlayerXMobility(bool mobile){ if(mobile) playerSprite->unlockXMobility(); else playerSprite->lockXMobility(); }
	void setPlayerYMobility(bool mobile){ if(mobile) playerSprite->unlockYMobility(); else playerSprite->lockYMobility(); }
	void setPlayerCollidable(bool collidable){ playerSprite->setCollidable(collidable);}
	
	
	bool toRightOfCenterScreen(){ return playerSprite->toRightOfCenterScreen(); }
	bool toLeftOfCenterScreen() { return playerSprite->toLeftOfCenterScreen(); }
	bool isCenteredOnScreen()	{ return playerSprite->isCenteredOnScreen(); } 

	
	
	CMovableSprite * getSprite(){ return playerSprite; }
	
	virtual void noKeysPressed() {}
	virtual void dPadKey(Direction d){};	
	virtual void aKey(Direction d){};
	virtual void bKey(Direction d){};
	virtual void xKey(Direction d){};
	virtual void yKey(Direction d){};
	virtual void leftKey(Direction d){};
	virtual void rightKey(Direction d){};
	virtual void startKey(){};
	virtual void selectKey(){};
	
protected:
	
	PlayerType ptype;
	CMovableSprite * playerSprite;
	
};


#endif /*CPLAYER_H_*/
