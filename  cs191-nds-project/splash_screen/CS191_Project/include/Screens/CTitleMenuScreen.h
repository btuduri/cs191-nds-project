#ifndef CTITLEMENUSCREEN_
#define CTITLEMENUSCREEN_

#include "ProjectLib.h"

// Background graphics
#include "graphics/title.h"
#include "graphics/splash.h"
#include "graphics/menu0.h"
#include "graphics/menu1.h"
#include "graphics/menu2.h"
#include "graphics/menu3.h"

#define BUTTON_STARTX 74
#define BUTTON_ENDX 170

#define BUTTON1_STARTY 10
#define BUTTON1_ENDY 62

#define BUTTON2_STARTY 73
#define BUTTON2_ENDY 125

#define BUTTON3_STARTY 135
#define BUTTON3_ENDY 187

class CTitleMenuScreen : public CScreen {

public:
	CTitleMenuScreen(){}
	~CTitleMenuScreen(){}
	int run(); // run() returns the int of the next screen after run is over

private:
	void loadVideo();
	void loadBackground();	
};

#endif /*CTITLEMENUSCREEN_*/
