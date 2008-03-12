
#include "cScreenManager.h"


cScreenManager::cScreenManager() {
	
	//main_screen = BOTTOM;
	lcdMainOnBottom();
	
}


int cScreenManager::run(int screen)
{
	int ret;
	cScreen *sc;
	
	switch(screen)
	{
		case SplashScreen: 
			sc = new cSplashScreen;
			break;
		case TitleMenuScreen:
			sc = new cTitleMenuScreen();
			break;
		case GamePlayScreen: 
			//TODO: finish
		default: return 0;	
	}

	assert(sc != NULL);
	
	ret = sc->run();	
	delete sc;
	return ret;
}
