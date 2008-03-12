#ifndef CTITLEMENUSCREEN_
#define CTITLEMENUSCREEN_

#include "projectlib.h"

// Background graphics
#include "../graphics/title.h"
#include "../graphics/splash.h"
#include "../graphics/menu0.h"
#include "../graphics/menu1.h"
#include "../graphics/menu2.h"
#include "../graphics/menu3.h"

#define BUTTON1_STARTX (int16)(SCREEN_WIDTH/3)
#define BUTTON1_ENDX (int16)((SCREEN_WIDTH/3) * 2)
#define BUTTON1_STARTY (int16)(int16) 0
#define BUTTON1_ENDY (int16)(SCREEN_HEIGHT/3)

#define BUTTON2_STARTX (int16)(SCREEN_WIDTH/3)
#define BUTTON2_ENDX (int16)((SCREEN_WIDTH/3) * 2)
#define BUTTON2_STARTY (int16)((SCREEN_HEIGHT/3) + 1)
#define BUTTON2_ENDY (int16)((SCREEN_HEIGHT/3) * 2)

#define BUTTON3_STARTX (int16)(SCREEN_WIDTH/3)
#define BUTTON3_ENDX (int16)((SCREEN_WIDTH/3) * 2)
#define BUTTON3_STARTY (int16) (2 * (SCREEN_HEIGHT/3) + 1)
#define BUTTON3_ENDY (int16)(SCREEN_HEIGHT)

class cTitleMenuScreen : public cScreen {

public:
	cTitleMenuScreen(){}
	~cTitleMenuScreen(){}
	int run(); // run() returns the int of the next screen after run is over

private:
	void loadVideo();
	void loadBackground();	
};

#endif /*CTITLEMENUSCREEN_*/
