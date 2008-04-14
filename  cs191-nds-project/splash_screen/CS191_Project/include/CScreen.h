#pragma once

#ifndef CSCREEN_H_
#define CSCREEN_H_

#include "ProjectLib.h"

class CScreen {

public:
	virtual ~CScreen(){};
	
	virtual int run()=0; // run() returns the int of the next screen after run is over
	
protected:
	bool running;
	
private:
	virtual void loadVideo()=0;
	virtual void loadBackground()=0;
	//void loadScreen(int type){};
	//int setScreenMode(uint32 screen, uint32 mode, bool is3d);
	
	int screenType;
	bool mainOnTop;
};

#endif /*CSCREEN_H_*/

