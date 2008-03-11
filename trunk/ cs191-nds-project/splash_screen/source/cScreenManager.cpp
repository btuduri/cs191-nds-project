
#include "cScreenManager.h"


cScreenManager::cScreenManager() {
	
	main_screen = BOTTOM;
	lcdMainOnBottom();
	
	
}

int cScreenManager::setScreenMode(uint32 screen=MAIN, uint32 mode=OFF, bool is3d=false)
{
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
}




