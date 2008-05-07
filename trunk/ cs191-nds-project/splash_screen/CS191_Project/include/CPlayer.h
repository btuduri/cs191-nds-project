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
	virtual ~CPlayer() {};
	
	float getPlayerX() { return playerX; }
	float getPlayerY() { return playerY; }
	
	bool toRightOfCenterScreen()	{ if(playerSprite->getRelationToCenter() == 1 )	return true; else return false; }
	bool toLeftOfCenterScreen() 	{ if(playerSprite->getRelationToCenter() == -1 )return true; else return false; }
	bool isCenteredOnScreen()		{ if(playerSprite->getRelationToCenter() == 0) 	return true; else return false; } 
	
	virtual void leftKey() {}
	virtual void rightKey() {}
	virtual void upKey() {}
	virtual void downKey(){}
	
	
	
private:
	
	float playerX, playerY;
	
	PlayerType ptype;
	CMovableSprite * playerSprite;
	
};


#endif /*CPLAYER_H_*/
