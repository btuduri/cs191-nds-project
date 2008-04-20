
#include "CPlaygroundScreen.h"
#include "CMario.h"

CSpriteManager *csm;
CMovableSprite *player1;
CMovableSprite *player2;

void player1Update()
{
	player1->update();
}

void player2Update()
{
//	player2->setAngleRad(player2->getAngleRad() + .5);
//	player2->rotateSprite();
//	errColor.cyan();
//	Error();
	player2->update();
}


/* loadVideo
 * This function loads the video type needed for this screen
 * */
void CPlaygroundScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	// Setup VRAM_B for Sprite Binary data
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);

	//Sub screen
//	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );
//	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	vramSetBankC(VRAM_C_SUB_BG);
	BG_PALETTE_SUB[255] = RGB15(31,31,31);	//by default font will be rendered with color 255

}

/* loadBackground
 * loads all the backgrounds and sets they'yre properities needed for this specific screen.
 * */
void CPlaygroundScreen::loadBackground()
{
	// Main screen background
	BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;
	BG2_XDX = 1 << 8;
	BG2_XDY = 0;
	BG2_YDX = 0;
	BG2_YDY = 1 << 8;
	BG2_CX = 0;
	BG2_CY = 0;

	
	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);

/*	// Sub screen background
	SUB_BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;
	SUB_BG2_XDX = 1 << 8;
	SUB_BG2_XDY = 0;
	SUB_BG2_YDX = 0;
	SUB_BG2_YDY = 1 << 8;
	SUB_BG2_CX = 0;
	SUB_BG2_CY = 0;	*/
}

void CPlaygroundScreen::processInput()
{	
	scanKeys();
	
	u32 keys_down = keysDown();
	u32 keys_up = keysUp();
	u32 keys_held = keysHeld();

	iprintf("\x1b[9;0Hkeys_down: %d\nkeys_up: %d\nkeys_held: %d", keys_down, keys_up, keys_held);
	
	if( keys_down | keys_up | keys_held )
	{
		key_pressed = true;
		errColor.blue();
		Error();
	}
	else key_pressed = false;
	
	//process start/select here
	player1->updateAnimation( key_pressed, keys_down, keys_up, keys_held );
	
}




int CPlaygroundScreen::run()
{
	powerON(POWER_ALL);
	loadVideo();
	loadBackground();
	
	//console
	SUB_BG0_CR = BG_MAP_BASE(31); 	// Set up the console.
	// consoleInit() is a lot more flexible but this gets you up and running quick
	consoleInitDefault((u16*)SCREEN_BASE_BLOCK_SUB(31), (u16*)CHAR_BASE_BLOCK_SUB(0), 16);
	
	CSpriteManager *sm = new CSpriteManager();
	csm = sm;

	//assert(false);
	CMario * mario = new CMario();
	sm->registerSprite(mario);
	player1 = mario;

//	CMario * mario1 = new CMario();
//	sm->registerSprite(mario1);
//	player2 = mario1;
//	player2->setPosition(150,50);

	
	// Setup Timer 2 for player 1
	TIMER2_DATA = TIMER_FREQ_1024(8);
	TIMER2_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER2, 	player1Update);
	
	
	// Setup Timer 3 for player 2
//	TIMER3_DATA = TIMER_FREQ_1024(16);
//	TIMER3_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
//	irqSet(IRQ_TIMER3, 	player2Update);
//	
	// Copy the data from program memory to VRAM.
	//dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	//dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);
 
	bool showing = true;
	while (showing) {

		processInput();
		sm->updateOAM();
		
//		if ( !(REG_KEYINPUT & KEY_START))
//			showing = false;
//		mario->update();
//		mario1->update();
		swiWaitForVBlank();
		//sm->updateOAM();
	}	
	
	return 0;
}

