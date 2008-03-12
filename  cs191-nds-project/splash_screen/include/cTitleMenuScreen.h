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
