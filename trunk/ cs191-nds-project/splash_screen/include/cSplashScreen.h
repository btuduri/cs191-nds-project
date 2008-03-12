#ifndef CSPLASHSCREEN_
#define CSPLASHSCREEN_

#include "projectlib.h"

// Background graphics
#include "../graphics/title.h"
#include "../graphics/splash.h"

class cSplashScreen : public cScreen
{
public:
	cSplashScreen(){}
	
	int run(); // run() returns the int of the next screen after run is over

private:	
	void loadVideo();
	void loadBackground();

};

#endif /*CSPLASHSCREEN_*/
