
#include "CSpriteRotationScreen.h"
#include "CMario.h"

CSprite *player1;
CSprite *player2;

void player1Update()
{
	player1->update();
}

void player2Update()
{
	player2->setAngleRad(player2->getAngleRad() + .5);
//	player2->rotateSprite();
//	errColor.cyan();
//	Error();
	player2->update();
}


/* loadVideo
 * This function loads the video type needed for this screen
 * */
void CSpriteRotationScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	// Setup VRAM_B for Sprite Binary data
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);

	//Sub screen
	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
}

/* loadBackground
 * loads all the backgrounds and sets they'yre properities needed for this specific screen.
 * */
void CSpriteRotationScreen::loadBackground()
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

int CSpriteRotationScreen::run()
{
	loadVideo();
	loadBackground();

	CSpriteManager *sm = new CSpriteManager();
	
	//assert(false);
	CMario * mario = new CMario();
	sm->registerSprite(mario);
	player1 = mario;
	
	CMario * mario1 = new CMario();
	sm->registerSprite(mario1);
	player2 = mario1;
	player2->setPosition(150,50);
		
	// Setup Timer 2 for player 1
	TIMER2_DATA = TIMER_FREQ_1024(4);
	TIMER2_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER2, 	player1Update);
	
	// Setup Timer 3 for player 2
	TIMER3_DATA = TIMER_FREQ_1024(16);
	TIMER3_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER3, 	player2Update);
	
	// Copy the data from program memory to VRAM.
	//dmaCopy(splashBitmap, (u16*)BG_BMP_RAM(0), splashBitmapLen);

	// Copy the data from program memory to VRAM.
	//dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);
 
	bool showing = true;
	while (showing) {
//		if ( !(REG_KEYINPUT & KEY_START))
//			showing = false;
//		mario->update();
//		mario1->update();
		swiWaitForVBlank();
		sm->updateOAM();
	}	
	
	return 0;
}

