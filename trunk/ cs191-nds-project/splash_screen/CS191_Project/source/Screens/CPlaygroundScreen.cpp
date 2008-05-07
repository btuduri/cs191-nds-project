
#include "CPlaygroundScreen.h"
//#include "CMario.h"
//#include "CKirbyMap.h"

CSpriteManager *csm;
CMap *map;
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

	// Setup VRAM_B for Sprite Binary data
	vramSetBankB(VRAM_B_MAIN_SPRITE_0x06400000);

	//Sub screen
//	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE );
//	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	vramSetBankC(VRAM_C_SUB_BG);
	BG_PALETTE_SUB[255] = RGB15(31,31,31);	//by default font will be rendered with color 255

}

/* loadBackground
 * loads all the backgrounds and sets they'yre properities needed for this specific screen.
 * */
void CPlaygroundScreen::loadBackground()
{
	
	map->loadMap();
//	// Main screen background
//	BG2_CR = BG_COLOR_256 | BG_RS_32x32 | BG_PRIORITY_0 | BG_BMP_BASE(0);//  | BG_MAP_BASE(0) | BG_TILE_BASE(1);// | BG_WRAP_OFF;
////	BG2_CR = BG_COLOR_256 | BG_RS_64x64 | BG_PRIORITY_0 | BG_MAP_BASE(0) | BG_TILE_BASE(2); // | BG_WRAP_OFF;
////	BG0_CR = BG_BMP8_512x512 | BG_PRIORITY_0 | BG_MAP_BASE(0) | BG_TILE_BASE(2); // | BG_WRAP_OFF;
//
//	BG2_XDX = 1 << 7;
//	BG2_XDY = 0;
//	BG2_YDX = 0;
//	BG2_YDY = 1 << 7;
//    BG2_CX = 0;
//	BG2_CY = 0;
	
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
//	scanKeys();
//	
//	u32 keys_down = keysDown();
//	u32 keys_up = keysUp();
//	u32 keys_held = keysHeld();
//
//	iprintf("\x1b[9;0Hkeys_down: %d\nkeys_up: %d\nkeys_held: %d", keys_down, keys_up, keys_held);
//	iprintf("\x1b[12;0Hmap_x: %d\nmap_y: %d", (int)map->getX(), (int)map->getY());
//	
//
//	if( keys_down | keys_up | keys_held )
//	{
//		key_pressed = true;
////		errColor.blue();
////		Error();
//	}
//	else key_pressed = false;
//	
//	//process start/select here
//	
//	if( player1->allowedMobile() && key_pressed )
//	{
//		if( (keys_held & KEY_UP) || (keys_down & KEY_UP) )
//		{
//		}
//		if( (keys_held & KEY_DOWN) || (keys_down & KEY_DOWN) )
//		{
//			
//		}
//		if( (keys_held & KEY_LEFT) || (keys_down & KEY_LEFT) )
//		{
//			if( player1->getRelationToCenter() == 1 )	// if player is to the right of the center
//			{
//				
//				
//			}
//			if( map->scrollLeft(1) )
//				player1->lockXMobility();
//			else 
//				player1->unlockXMobility();
//		}
//		if( (keys_held & KEY_RIGHT) || (keys_down & KEY_RIGHT) )
//		{
//			if( map->scrollRight(1) )
//				player1->lockXMobility();
//			else 
//				player1->unlockXMobility();			
//		}
//	}	
//	
//	player1->updateAnimation( key_pressed, keys_down, keys_up, keys_held );
//	
}

int CPlaygroundScreen::run()
{
	powerON(POWER_ALL);
	irqEnable(IRQ_VBLANK);
	
	CSpriteManager *sm = new CSpriteManager();
	csm = sm;

	//assert(false);
//	CMario * mario = new CMario();
//	sm->registerSprite(mario);
//	player1 = mario;

	CKirbyMap * kirbyMap = new CKirbyMap();
	map = kirbyMap;
//	CMario * mario1 = new CMario();
//	sm->registerSprite(mario1);
//	player2 = mario1;
//	player2->setPosition(150,50);

	
//	CControls * controls = new CControls(map, player1);
	
	loadVideo();
	loadBackground();	
	//console
	SUB_BG0_CR = BG_MAP_BASE(31); 	// Set up the console.
	// consoleInit() is a lot more flexible but this gets you up and running quick
	consoleInitDefault((u16*)SCREEN_BASE_BLOCK_SUB(31), (u16*)CHAR_BASE_BLOCK_SUB(0), 16);
	

	
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
//	dmaCopy(level01Pal, BG_PALETTE, level01PalLen);
//
//	dmaCopy(level01Bitmap, (void*)BG_BMP_RAM(0), level01BitmapLen);
	

	// Load the map.
//	dmaCopy(level2Pal, BG_PALETTE, level2PalLen);	
//	dmaCopy(level2Map, (u16*)SCREEN_BASE_BLOCK(0), level2MapLen);    
	// Load the tile graphics.
//	dmaCopy(level2Tiles, (u16*)BG_TILE_RAM(2), level2TilesLen); 
	
//	swiDecompressLZSSVram((void*)level01Bitmap, BG_GFX, 0, &level01_decomp);
	// Copy the data from program memory to VRAM.
	//dmaCopy(titleBitmap, (u16*)BG_BMP_RAM_SUB(0), titleBitmapLen);
	// Load the palette (thanks WinGrit)
//	dmaCopy(levelPal, BG_PALETTE, levelPalLen);	
//	dmaCopy(levelBitmap, (void*)BG_BMP_RAM(0), levelBitmapLen);
 
	bool showing = true;
	while (showing) {

//		processInput();
//		controls->processInput();
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

