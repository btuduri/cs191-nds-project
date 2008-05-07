#ifndef CPLAYGROUNDSCREEN_H_
#define CPLAYGROUNDSCREEN_H_
#pragma once

#include "ProjectLib.h"
#include "CScreen.h"
#include "CSpriteManager.h"
#include "CMap.h"
#include "CMovableSprite.h"
#include "CControls.h"


#include "CMario.h"
#include "CKirbyMap.h"

//#include "graphics/levels/level.h"
//#include "graphics/levels/level2.h"

class CPlaygroundScreen : public CScreen
{
public:
//	CPlaygroundScreen();
//	virtual ~CPlaygroundScreen();

	int run(); // run() returns the int of the next screen after run is over

private:	
	void loadVideo();
	void loadBackground();
	void processInput();
	
	bool key_pressed;
};


#endif /*CPLAYGROUNDSCREEN_H_*/
