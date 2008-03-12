
//#include "cScreen.h"

/*cScreen::cScreen() {	
}


cScreen::cScreen(int type) {
	
	showing = true;
	screenType = type;
	//loadScreen(screenType);
	
}

void cScreen::loadVideo() {
	
	//videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D, false);
	
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );

	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );

	//Main screen
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	//Sub screen
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
}


void cScreen::loadScreen(int type) {

	switch(type)
	{
	case SplashScreen:
		break;
	case TitleMenuScreen:
		break;
	case GamePlayScreen:
		break;
	}
	
}

 int cScreen::setScreenMode(uint32 screen=MAIN, uint32 mode=OFF, bool is3d=false) {
	uint32 m;
	
	if(is3d)
	{
		m = mode | ENABLE_3D;
	}
	else	// the mode is 2d
		m = mode | ENABLE_3D;
		
	if( screen == MAIN )
	{
		for(int i=0; i < 4; i++)
		{
			if( mainBG[i] != NULL )
			{
				switch(i)
				{
					case 0: m |= DISPLAY_BG0_ACTIVE;
					case 1: m |= DISPLAY_BG1_ACTIVE;
					case 2: m |= DISPLAY_BG2_ACTIVE;
					case 3: m |= DISPLAY_BG3_ACTIVE;
					default: assert(false);					//this should NEVER hit...
				}
			}
		}
		
		videoSetMode(m);
	}
	else if( screen == SUB )
	{
		for(int i=0; i < 4; i++)
		{
			if( mainBG[i] != NULL )
			{
				switch(i)
				{
					case 0: m |= DISPLAY_BG0_ACTIVE;
					case 1: m |= DISPLAY_BG1_ACTIVE;
					case 2: m |= DISPLAY_BG2_ACTIVE;
					case 3: m |= DISPLAY_BG3_ACTIVE;
					default: assert(false);					//this should NEVER hit...
				}
			}
		}
		
		videoSetModeSub(m);
	}
	else
		assert(false);		//error ... this shouldn't happen

	return 0;
}*/

