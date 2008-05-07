#ifndef CCONTROLS_H_
#define CCONTROLS_H_
#pragma once

#include "ProjectLib.h"
#include "CMap.h"
#include "CPlayer.h"


class CControls {
public:
	
	CControls( CMap *m, CPlayer *p ) {};
	~CControls(){};
	
	void processInput();
	
private:
	CMap *map;
	CPlayer *player;

	u32 keys_down;
	u32 keys_up;
	u32 keys_held;
	bool key_pressed;

};

#endif /*CCONTROLS_H_*/
