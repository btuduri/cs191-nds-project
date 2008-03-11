#include <nds.h>
#include <stdio.h>

#include "cScreenManager.h"
#include "menuButton.h"

//Backgrounds
#include "graphics/title.h"
#include "graphics/splash.h"
#include "graphics/menu0.h"
#include "graphics/menu1.h"
#include "graphics/menu2.h"
#include "graphics/menu3.h"

//Sprites
#include "graphics/mario.h"

tOAM sprites;

//turn off all the sprites
void initSprites(void)
{
	for(int i = 0; i < 128; i++)
	{
		sprites.spriteBuffer[i].attribute[0] = ATTR0_DISABLED;
		sprites.spriteBuffer[i].attribute[1] = 0;
		sprites.spriteBuffer[i].attribute[2] = 0;
		sprites.spriteBuffer[i].attribute[3] = 0;
	}
}

//copy our sprite to object attribute memory
void updateOAM(void)
{
	//DC_FlushRange(sprites,128*sizeof(SpriteEntry));
	DC_FlushRange(sprites.spriteBuffer, SPRITE_COUNT * sizeof(SpriteEntry));

	//dmaCopy(sprites, OAM, 128 * sizeof(SpriteEntry));
	dmaCopy(sprites.spriteBuffer, OAM, SPRITE_COUNT * sizeof(SpriteEntry));
}



void initVideo(cScreenManager *sm) {

	sm->setScreenMode(MAIN, MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D, false);

	sm->setScreenMode(SUB, MODE5 | DISPLAY_BG2_ACTIVE, false);

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

}


bool inc = true;
int adder = 64*64;
void AnimateMario(void)
{
	
	
	if(inc)
	{
		sprites.spriteBuffer[0].tileIdx = sprites.spriteBuffer[0].tileIdx + 128;
		if(sprites.spriteBuffer[0].tileIdx == (128*5))
			inc = false;
	}
	else
	{
		sprites.spriteBuffer[0].tileIdx = sprites.spriteBuffer[0].tileIdx - 128;
		if(sprites.spriteBuffer[0].tileIdx == 0)
			inc = true;
	}
}


int main(void) {

	touchPosition touchXY;
	cScreenManager *sm = new cScreenManager();

	MenuButton * firstButton = new MenuButton();
	MenuButton * secondButton = new MenuButton();
	firstButton->setRange((int16)(SCREEN_WIDTH/3), (int16) 0,
			(int16)(SCREEN_WIDTH/3 * 2), (int16)(SCREEN_HEIGHT/3));
	firstButton->attachBG(menu1Bitmap);
	powerON(POWER_ALL);
	irqInit();
	irqSet(IRQ_VBLANK, 0);

	// Setup Timer 3 to generate pulses every 1/4 second.
	TIMER3_DATA = TIMER_FREQ_1024(12);
	TIMER3_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	
	irqSet(IRQ_TIMER3, AnimateMario);
	
	
	initVideo(sm);
	initBackground();

	// Copy the data from program memory to VRAM.
	dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);

	bool quit = false;
	while (quit == false) {
		if ( !(REG_KEYINPUT & KEY_START))
			quit = true;
		swiWaitForVBlank();
	}

    //turn off the sprites
    initSprites();

    // Setup VRAM_B for Sprite Binary data
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	
	// Numbered square sprite
	sprites.spriteBuffer[0].colMode = OBJCOLOR_256;
	sprites.spriteBuffer[0].objMode = OBJMODE_NORMAL;
	sprites.spriteBuffer[0].objShape = OBJSHAPE_SQUARE;
	sprites.spriteBuffer[0].objSize = OBJSIZE_64;
	sprites.spriteBuffer[0].objPriority = OBJPRIORITY_0;
	sprites.spriteBuffer[0].tileIdx = 0;
	sprites.spriteBuffer[0].posX = 10;
	sprites.spriteBuffer[0].posY = 120;
	sprites.spriteBuffer[0].isHidden = false;

	// Load the sprite palette.
	dmaCopy(marioPalette, SPRITE_PALETTE, marioPaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(marioBitmap, SPRITE_GFX, marioBitmapLength);
	
	sprites.matrixBuffer[0].hdx=256;
	sprites.matrixBuffer[0].hdy=0;
	sprites.matrixBuffer[0].vdx=0;
	sprites.matrixBuffer[0].vdy=256;
	
	
	int bg = 0;
	// Copy the data from program memory to VRAM.
	dmaCopy(menu0Bitmap, (u16*)BG_BMP_RAM(0), menu0BitmapLen);
	
	irqEnable(IRQ_VBLANK);
	irqEnable(IRQ_TIMER3);

	
	bool key_changed = false;
	while ( 1) {
		touchXY = touchReadXY();
		if ( !(REG_KEYINPUT & KEY_DOWN)) {
			++bg;
			key_changed = true;
		}

		if ( !(REG_KEYINPUT & KEY_UP)) {
			--bg;
			key_changed = true;
		}

		if (key_changed) {
			if (bg > 3)
				bg = 1;
			if (bg < 1)
				bg = 3;

			switch (bg) {
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
		if (firstButton->isCurrentBG(menu1Bitmap)){
			if (firstButton->wasClicked(touchXY.px, touchXY.py)) {
						dmaCopy(menu1Bitmap, (u16*)BG_BMP_RAM(0), menu1BitmapLen);
			}
		}
		swiWaitForVBlank();
		updateOAM();
		swiDelay(1500000);

	}
}
