#include "CApp.h"
/*run()
 * 
 * Initalizes the DS and sets the default starting screen.
 * (if you want to start on a different screen, change it in CScreenTypes 
 * 
 * */
void CApp::run() {
	
	powerON(POWER_ALL);	
	irqInit();
	irqSet(IRQ_VBLANK, Vblank);

	bool quit = false;
	CScreenManager * sm = new CScreenManager();
	
	int screen = DEFAULT_SCREEN;
	
	while(!quit)
	{
		screen = sm->run(screen);
		
		if(screen == 0)
			quit = true;
	}
	
}


