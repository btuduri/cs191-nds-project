#pragma once

#ifndef CSPRITEROTATIONSCREEN_H_
#define CSPRITEROTATIONSCREEN_H_

#include "ProjectLib.h"

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
