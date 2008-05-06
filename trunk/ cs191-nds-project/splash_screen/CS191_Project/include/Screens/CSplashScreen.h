#ifndef CSPLASHSCREEN_H_
#define CSPLASHSCREEN_H_

#include "ProjectLib.h"
#include "CScreen.h"
#include "ScreenType.h"
// Background graphics
#include "../graphics/title.h"
#include "../graphics/splash.h"

class CSplashScreen : public CScreen
{
public:
	CSplashScreen(){}
	
	int run(); // run() returns the int of the next screen after run is over

private:	
	void loadVideo();
	void loadBackground();

};

#endif /*CSPLASHSCREEN_H_*/
