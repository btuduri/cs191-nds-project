#include <nds.h>
#include <stdio.h>

#include "cScreenManager.h"

#include "graphics/title.h"
#include "graphics/splash.h"
#include "graphics/menu0.h"
#include "graphics/menu1.h"
#include "graphics/menu2.h"
#include "graphics/menu3.h"



void initVideo(	cScreenManager *sm ) {
	
	sm->setScreenMode(MAIN, MODE5 | DISPLAY_BG2_ACTIVE, false);

	sm->setScreenMode(SUB, MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE, false);
	
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);	
	//vramSetBankB(VRAM_B_MAIN_BG_0x06020000);
	//vramSetBankD(VRAM_D_MAIN_BG_0x06020000);
	//vramSetBankE(VRAM_E_MAIN_BG_0x06000000);	

	//Sub screen
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);			
	vramSetBankD(VRAM_D_LCD);	
	
}

void initBackground() {
	
	BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;	
	BG2_XDX = 1 << 8;
	BG2_XDY = 0;
	BG2_YDX = 0;
	BG2_YDY = 1 << 8;

	// Move the image
	BG2_CX = 0;
	BG2_CY = 0;
		
	SUB_BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;	
	SUB_BG2_XDX = 1 << 8;
	SUB_BG2_XDY = 0;
	SUB_BG2_YDX = 0;
	SUB_BG2_YDY = 1 << 8;

	// Move the image
	SUB_BG2_CX = 0;
	SUB_BG2_CY = 0;

	SUB_BG3_CR = BG_BMP16_256x256 | BG_BMP_BASE(8) | BG_PRIORITY_2;
	
//	SUB_BG3_CR = BG_BMP16_256x256 | BG_BMP_BASE(8) | BG_PRIORITY_2;	
//	SUB_BG3_XDX = 1 << 8;
//	SUB_BG3_XDY = 0;
//	SUB_BG3_YDX = 0;
//	SUB_BG3_YDY = 1 << 8;
//
//	// Move the image
//	SUB_BG3_CX = 0;
//	SUB_BG3_CY = 0;
//
//		
	
/*	
	BG3_CR = BG_BMP16_256x256 | BG_BMP_BASE(8) | BG_PRIORITY_2;

	// Affine matrix
	//        | 1.0 0.0 |
	// BG3 =  | 0.0 1.0 |
	BG3_XDX = 1 << 8;
	BG3_XDY = 0;
	BG3_YDX = 0;
	BG3_YDY = 1 << 8;
	
	// Move the image
	BG3_CX = 0;
	BG3_CY = 0;
	// The bottom layer is Mt. Fuji
	BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(16) | BG_PRIORITY_3;

	// Affine matrix
	//        | 1.0 0.0 |
	// BG1 =  | 0.0 1.0 |
	BG2_XDX = 1 << 8;
	BG2_XDY = 0;
	BG2_YDX = 0;
	BG2_YDY = 1 << 8;
	
	// Move the image
	BG2_CX = 0;
	BG2_CY = 0;
*/
}


int main(void) {
	

	cScreenManager *sm = new cScreenManager();
	
	powerON(POWER_ALL);
	irqInit();
	irqSet(IRQ_VBLANK, 0);
	
	initVideo(sm);
	initBackground();
	
	// Copy the data from program memory to VRAM.
	dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);

	bool quit = false;
	while( quit == false )
	{
		if( !(REG_KEYINPUT & KEY_START) )
			quit = true;
		swiWaitForVBlank();
	}

	int bg = 0;
	// Copy the data from program memory to VRAM.
	dmaCopy(menu0Bitmap, (u16*)BG_BMP_RAM(0), menu0BitmapLen);
	bool key_changed = false;
	while( 1 )	
	{
		if( !(REG_KEYINPUT & KEY_DOWN) )
		{
			++bg;
			key_changed = true;
		}
		if( !(REG_KEYINPUT & KEY_UP) )
		{
			--bg;
			key_changed = true;
		}
		
		if( key_changed) {
			if( bg > 3 ) bg = 1;
			if( bg < 1 ) bg = 3;
			
			switch(bg)
			{
				case 1:
					dmaCopy(menu1Bitmap, (u16*)BG_BMP_RAM(0), menu1BitmapLen);
					break;
				case 2:
					dmaCopy(menu2Bitmap, (u16*)BG_BMP_RAM(0), menu2BitmapLen);
					break;
				case 3:
					dmaCopy(menu3Bitmap, (u16*)BG_BMP_RAM(0), menu3BitmapLen);
					break;
			}
			
			key_changed = false;
		}
		
		swiWaitForVBlank();
		swiDelay(1500000);
	}
}
