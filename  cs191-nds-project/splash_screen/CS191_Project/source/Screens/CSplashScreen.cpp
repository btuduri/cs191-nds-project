#include "CSplashScreen.h"

/* loadVideo
 * This function loads the video type needed for this screen
 * */
void CSplashScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE_5_2D | DISPLAY_BG2_ACTIVE );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	//Sub screen
	videoSetModeSub( MODE_5_2D | DISPLAY_BG2_ACTIVE );
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
}

/* loadBackground
 * loads all the backgrounds and sets they'yre properities needed for this specific screen.
 * */
void CSplashScreen::loadBackground()
{
	// Main screen background
	BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;
	BG2_XDX = 1 << 8;
	BG2_XDY = 0;
	BG2_YDX = 0;
	BG2_YDY = 1 << 8;
	BG2_CX = 0;
	BG2_CY = 0;

	// Sub screen background
	SUB_BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;
	SUB_BG2_XDX = 1 << 8;
	SUB_BG2_XDY = 0;
	SUB_BG2_YDX = 0;
	SUB_BG2_YDY = 1 << 8;
	SUB_BG2_CX = 0;
	SUB_BG2_CY = 0;	
}

int CSplashScreen::run()
{
	loadVideo();
	loadBackground();

	// Copy the data from program memory to VRAM.
	dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);

	touchPosition touchXY;
	bool tapped = false;
	int clicked = 0;
	
	running = true;
	while (running) {
		touchXY = touchReadXY();
		
		if( (touchXY.px!=0) && (touchXY.py!=0) )
		{
			if( !tapped )
			{
				clicked++;
				tapped = true;
			}
		}
		else tapped = false;
		
		
		if ( !(REG_KEYINPUT & KEY_START))
			running = false;
		
		swiWaitForVBlank();
		
		if(clicked >= 2)
			running = false;
	}	
	
	return TitleMenuScreen;
}

