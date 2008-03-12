
#include "projectlib.h"
#include "cGameApp.h"


/*run()
 * 
 * Initalizes the DS and sets the default starting screen.
 * (if you want to start on a different screen, change it in CScreenTypes 
 * 
 * */
void cGameApp::run() {
	
	powerON(POWER_ALL);	
	irqInit();
	irqSet(IRQ_VBLANK, 0);

	bool quit = false;
	cScreenManager * sm = new cScreenManager();
	
	int screen = DEFAULT_SCREEN;
	
	while(!quit)
	{
		screen = sm->run(screen);
		
		if(screen == 0)
			quit = true;
	}
	
}


