#include "cSplashScreen.h"


void cSplashScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	//Sub screen
	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
}

void cSplashScreen::loadBackground()
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

int cSplashScreen::run()
{
	loadVideo();
	loadBackground();

	// Copy the data from program memory to VRAM.
	dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);
 
	bool showing = true;
	while (showing) {
		if ( !(REG_KEYINPUT & KEY_START))
			showing = false;
		swiWaitForVBlank();
	}	
	
	return TitleMenuScreen;
}

