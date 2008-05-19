#ifndef CCONTROLS_H_
#define CCONTROLS_H_
#pragma once

#include "ProjectLib.h"
#include "CMap.h"
#include "CPlayer.h"
#include "CMovableSprite.h"
#include "CBasicObject.h"
#include "CCollisionManager.h"

class CControls {
public:
	
	CControls( CMap *m, CPlayer *p, CCollisionManager *cs ) { map = m; player = p; collisionManager = cs; }
	~CControls(){};
	
	void processInput();	
	
	void registerSprite(CMovableSprite *sprite){collisionManager->registerSprite(sprite);}
	bool removeSprite(CMovableSprite *sprite){return collisionManager->removeSprite(sprite);}
	
	void registerObject(CBasicObject *obj){collisionManager->registerObject(obj);}
	bool removeObject(CBasicObject *obj){return collisionManager->removeObject(obj);}

private:
	
	CMap *map;
	CPlayer *player;
	CCollisionManager *collisionManager;
	
	u32 keys_down;
	u32 keys_up;
	u32 keys_held;
	bool key_pressed;

};

#endif /*CCONTROLS_H_*/
