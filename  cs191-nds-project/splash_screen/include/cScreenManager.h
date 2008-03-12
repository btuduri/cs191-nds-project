#ifndef CSCREENMANAGER_H_
#define CSCREENMANAGER_H_

#include "cSplashScreen.h"
#include "projectlib.h"

#define BG0	0
#define BG1	1
#define BG2	2
#define BG3	3

#define OFF	DISPLAY_SCREEN_OFF
#define MODE0 MODE_0_2D
#define MODE1 MODE_1_2D
#define MODE2 MODE_2_2D
#define MODE3 MODE_3_2D
#define MODE4 MODE_4_2D
#define MODE5 MODE_5_2D
#define MODE6 MODE_6_2D

#define MAIN	0
#define SUB		1

#define TOP		0
#define BOTTOM	1

class cScreenManager {
	
public:
	
	cScreenManager();
	~cScreenManager();
	
	//int setBG() {return 0;}
	//int drawBG(const void * image, uint32 size, int bg, int screen) {return 0;}
	int run(int screen);
	
private:
	
	//u16*	mainBG[4];	// screen backgrounds for main screen
	//u16*	subBG2[4];	// screen backgrounds for sub screen
	
	//u16	main_screen;	// this value is set to either TOP or BOTTOM.  the sub screen is the opposite of this value
	
	
};

#endif /*CSCREENMANAGER_H_*/
