#ifndef CAPP_H_
#define CAPP_H_
#pragma once

#include "ProjectLib.h"
#include "ScreenType.h"
#include "CScreenManager.h"

extern void Vblank();

class CApp {
public:
	CApp(){};		//TODO: write this...
	~CApp(){}; 	//TODO: write this...
	
	void run();
	
private:
};

#endif /*CAPP_H_*/
