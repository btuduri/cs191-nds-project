
#include "CPlaygroundScreen.h"
//#include "CMario.h"
//#include "CKirbyMap.h"
#include "CDraw.h"
#include "CPoint.h"
#include "CColor.h"
#include "CBasicObject.h"
#include "CPlatform.h"


CSpriteManager *csm;
CMap *map;
CPlayer *player1;
CPlayer *player2;


void player1Update()
{
	player1->update();
//	csm->updateOAM();
}

void player2Update()
{
//	player2->update();
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

	vramSetBankC(VRAM_C_SUB_BG_0x06200000);

	videoSetModeSub(MODE_0_2D | DISPLAY_BG0_ACTIVE);
	vramSetBankC(VRAM_C_SUB_BG);
	BG_PALETTE_SUB[255] = RGB15(31,31,31);	//by default font will be rendered with color 255

	
}

/* loadBackground
 * loads all the backgrounds and sets they'yre properities needed for this specific screen.
 * */
void CPlaygroundScreen::loadBackground()
{
	
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
	
	// Sub screen background
	SUB_BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_0;
	SUB_BG2_XDX = 1 << 8;
	SUB_BG2_XDY = 0;
	SUB_BG2_YDX = 0;
	SUB_BG2_YDY = 1 << 8;
	SUB_BG2_CX = 0;
	SUB_BG2_CY = 0;	

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
	
	loadVideo();
	loadBackground();	

	CCollisionManager *cm = new CCollisionManager();
	
	CSpriteManager *sm = new CSpriteManager();
	csm = sm;

	CKirbyMap * kirbyMap = new CKirbyMap();
	map = kirbyMap;
	map->loadMap();
	
//	CMovableSprite * cms = (CMovableSprite*) mario1->getSprite();
//	cms->setTileIndex(5);

	//console
	SUB_BG0_CR = BG_MAP_BASE(31); 	// Set up the console.
//	 consoleInit() is a lot more flexible but this gets you up and running quick
	consoleInitDefault((u16*)SCREEN_BASE_BLOCK_SUB(31), (u16*)CHAR_BASE_BLOCK_SUB(0), 16);

	CMarioSprite *marioSprite;
	CMario * mario = new CMario();
	marioSprite = mario->getSprite();
	sm->registerSprite(mario->getSprite());
	marioSprite->setCollisionManager(cm);
	player1 = mario;
	
	CMario * mario1 = new CMario();
	marioSprite = mario1->getSprite();
	sm->registerSprite(marioSprite);
	marioSprite->setCollisionManager(cm);
	player2 = mario1;
	player2->setPlayerX(150);
	player2->setPlayerY(50);
		
	CControls * controls = new CControls(map, player1, cm);
	//register all none player sprites
//	controls->registerSprite(mario1->getSprite());
	
	// Setup Timer 2 for player 1
	TIMER2_DATA = TIMER_FREQ_1024(8);//8
	TIMER2_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER2, 	player1Update);

	// Setup Timer 3 for player 2
	TIMER3_DATA = TIMER_FREQ_1024(4);
	TIMER3_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER3, 	player2Update);
	
	// Copy the data from program memory to VRAM.	
//	dmaCopy(level01Pal, BG_PALETTE, level01PalLen);
//
//	dmaCopy(level01Bitmap, (void*)BG_BMP_RAM(0), level01BitmapLen);
	
	u16* screen_buffer = (u16*)0x06040000;
	CDraw * canvas = new CDraw();
	
	CPlatform *ground = new CPlatform();
	ground->setCollidable(true);
	ground->setX((15-100)*2);
	ground->setY((174-100)*2);
	ground->setWidth(452);
	ground->setHeight(72);
	controls->registerObject(ground);

	CPlatform *leftPlatform = new CPlatform();
	leftPlatform->setCollidable(true);
	leftPlatform->setX((40-100)*2);
	leftPlatform->setY((135-100)*2);
	leftPlatform->setWidth(84);
	leftPlatform->setHeight(1);
	controls->registerObject(leftPlatform);

	CPlatform *rightPlatform = new CPlatform();
	rightPlatform->setCollidable(true);
	rightPlatform->setX((174-100)*2);
	rightPlatform->setY((135-100)*2);
	rightPlatform->setWidth(88);
	rightPlatform->setHeight(1);
	controls->registerObject(rightPlatform);
	
	canvas->drawRectangle(screen_buffer, CPoint((int)ground->getX(),(int)ground->getY()), CPoint((int)ground->getX()+25,(int)ground->getY()+25),CColor(10,10,10), true);

	bool showing = true;
	
	while (true) {
		
		controls->processInput();
		csm->updateOAM();

		swiWaitForVBlank();
		
//		if ( !(REG_KEYINPUT & KEY_START))
//			showing = false;
//		mario->update();
//		mario1->update();


		player1->setPlayerCollidable(false);
		iprintf("\x1b[5;0H                                              ");
		iprintf("\x1b[5;0HisCollidable(): %d", player1->isPlayerCollidable());

		int x, y, x1,y1;
		x = (int)ground->getX();
		y = (int)ground->getY();
		x1 = (int)ground->getX()+(int)ground->getWidth();
		y1 = (int)ground->getY()+(int)ground->getHeight();
		if(x<0) x = 0;
		if(y<0) y = 0;
		if(x1>=SCREEN_WIDTH) x1 = SCREEN_WIDTH-1;
		if(y1>=SCREEN_HEIGHT) y1 = SCREEN_HEIGHT-1;
		
		if((x<SCREEN_WIDTH) && (x1>0) && (y<SCREEN_HEIGHT) && (y1>0))
		{
			for(int i=0; i<SCREEN_WIDTH*SCREEN_HEIGHT; i++)
				screen_buffer[i] = 0;

			canvas->drawRectangle(	screen_buffer,
								CPoint(x,y),
								CPoint(x1,y1),
								CColor(50,0,0), false);
		}
		
		if(player1->isPlayerCollidable())
		{
//			canvas->drawRectangle(screen_buffer, CPoint(0,0), CPoint(256,256), CColor(15,15,15), true);
	
			canvas->drawRectangle(	screen_buffer,
									CPoint((int)ground->getX(),(int)ground->getY()),
									CPoint((int)ground->getX()+ground->getWidth(),(int)ground->getY()+ground->getHeight()),
									CColor(0,15,0), true);
	
			
			canvas->drawRectangle(screen_buffer,
					CPoint((int)mario1->getPlayerX(), (int)mario1->getPlayerY()),
					CPoint((int)(mario1->getPlayerX()+mario1->getPlayerWidth()), (int)(mario1->getPlayerY()+mario1->getPlayerHeight())),
					CColor(0,15,0),
					false);
	
			canvas->drawRectangle(screen_buffer,
					CPoint((int)mario->getPlayerX(), (int)mario->getPlayerY()),
					CPoint((int)(mario->getPlayerX()+mario->getPlayerWidth()), (int)(mario->getPlayerY()+mario->getPlayerHeight())),
					CColor(15,0,0),
					false);
		}

	}	
	
	return 0;
}
	

