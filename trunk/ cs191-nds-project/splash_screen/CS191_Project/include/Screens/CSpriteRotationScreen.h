#ifndef CSPRITEROTATIONSCREEN_H_
#define CSPRITEROTATIONSCREEN_H_
#pragma once

#include "ProjectLib.h"
#include "CScreen.h"
#include "CButton.h"
#include "Projects/CSpriteRotations.h"
#include "CDraw.h"
#include "CSpriteManager.h"

class CSpriteRotationScreen : public CScreen
{
public:
//	CSpriteRotationScreen();
//	virtual ~CSpriteRotationScreen();

	int run(); // run() returns the int of the next screen after run is over

private:	
	void loadVideo();
	void loadBackground();
	void processInput();
	
	bool key_pressed;
};

#endif /*CSPRITEROTATIONSCREEN_H_*/
