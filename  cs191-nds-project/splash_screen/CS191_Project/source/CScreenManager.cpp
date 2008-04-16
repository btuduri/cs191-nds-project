
#include "CScreenManager.h"


CScreenManager::CScreenManager() {
	
	//main_screen = BOTTOM;
	lcdMainOnBottom();
	
}


int CScreenManager::run(int screen)
{
	int ret;
	CScreen *sc = NULL;
	
	switch(screen)
	{
//		case SplashScreen: 
//			sc = new CSplashScreen();
//			break;
//		case TitleMenuScreen:
//			sc = new CTitleMenuScreen();
//			break;
//		case SpriteRotationScreen: 
//			sc = new CSpriteRotationScreen();
//			break;
		case PlaygroundScreen:
			sc = new CPlaygroundScreen();
			break;
		default: return 0;	
	}

	//assert(sc != NULL);
	
	ret = sc->run();	
	delete sc;
	return ret;
}
