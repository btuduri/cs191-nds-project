#include "cTitleMenuScreen.h"


//Sprites
#include "../graphics/mario.h"
#include "cMarioSprite.h"

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


void cTitleMenuScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	//Sub screen
	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
}

void cTitleMenuScreen::loadBackground()
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

int cTitleMenuScreen::run()
{
	loadVideo();
	loadBackground();

	touchPosition touchXY;
	int bg = 0;
	// Copy the data from program memory to VRAM.
	dmaCopy(menu0Bitmap, (u16*)BG_BMP_RAM(0), menu0BitmapLen);
	
	irqEnable(IRQ_VBLANK);
	irqEnable(IRQ_TIMER3);

	MenuButton * firstButton = new MenuButton();
	MenuButton * secondButton = new MenuButton();
	MenuButton * thirdButton = new MenuButton();
	
	firstButton->setRange(BUTTON1_STARTX, BUTTON1_STARTY,
			BUTTON1_ENDX, BUTTON1_ENDY);
	secondButton->setRange(BUTTON2_STARTX, BUTTON2_STARTY,
			BUTTON2_ENDX, BUTTON2_ENDY);
	thirdButton->setRange(BUTTON3_STARTX, BUTTON3_STARTY,
				BUTTON3_ENDX, BUTTON3_ENDY);
	
	// Setup Timer 3 to generate pulses every 1/4 second.
	TIMER3_DATA = TIMER_FREQ_1024(12);
	TIMER3_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	
	irqSet(IRQ_TIMER3, AnimateMario);

    //turn off the sprites
    initSprites();

    // Setup VRAM_B for Sprite Binary data
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);
	cMarioSprite mario;
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
		
	
	bool key_changed = false;
	while (1) {
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
		
		if (firstButton->wasClicked(touchXY.px, touchXY.py)) {
					dmaCopy(menu1Bitmap, (u16*)BG_BMP_RAM(0), menu1BitmapLen);
		}
		else if (secondButton->wasClicked(touchXY.px, touchXY.py)) {
					dmaCopy(menu2Bitmap, (u16*)BG_BMP_RAM(0), menu2BitmapLen);
		}
		else if (thirdButton->wasClicked(touchXY.px, touchXY.py)) {
			dmaCopy(menu3Bitmap, (u16*)BG_BMP_RAM(0), menu3BitmapLen);
		}
		
		swiWaitForVBlank();
		updateOAM();
		swiDelay(1500000);

	}
	
	return 0;
}

