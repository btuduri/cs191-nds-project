
#include "ProjectLib.h"
#include "CSpriteRotationScreen.h"
#include "Projects/CSpriteRotations.h"

#include "graphics/projects/rotate_screen.h"
//#include "../gfx/projects/sprite_rotation.h"

CMovableSprite *sprite1;
CMovableSprite *sprite2;
CMovableSprite *sprite3;

u16* screen_buffer;
u8 rotSelection;
bool show1;
bool show2;
bool show3;


void spritesUpdate()
{

	if(show1) {
		sprite1->setSpriteVisibility(false);
		if( (sprite1->getX()+16 + sprite1->getXVelocity() < 0) || (sprite1->getX()+42 + sprite1->getXVelocity() > SCREEN_WIDTH) )
			sprite1->toggleXVelocity();
		if( (sprite1->getY()+16 + sprite1->getYVelocity() < 0) || (sprite1->getY()+42 + sprite1->getYVelocity() > SCREEN_HEIGHT) )
			sprite1->toggleYVelocity();
		sprite1->update();
	}
	else sprite1->setSpriteVisibility(true);
	
	
	if(show2) {
		sprite2->setSpriteVisibility(false);
		if( (sprite2->getX()+16 + sprite2->getXVelocity() < 0) || (sprite2->getX()+42 + sprite2->getXVelocity() > SCREEN_WIDTH) )
			sprite2->toggleXVelocity();
		if( (sprite2->getY()+16 + sprite2->getYVelocity() < 0) || (sprite2->getY()+42 + sprite2->getYVelocity() > SCREEN_HEIGHT) )
			sprite2->toggleYVelocity();
		sprite2->update();
	}
	else sprite2->setSpriteVisibility(true);

	if(show3) {
		sprite3->setSpriteVisibility(false);
		if( (sprite3->getX()+16 + sprite3->getXVelocity() < 0) || (sprite3->getX()+42 + sprite3->getXVelocity() > SCREEN_WIDTH) )
			sprite3->toggleXVelocity();
		if( (sprite3->getY()+16 + sprite3->getYVelocity() < 0) || (sprite3->getY()+42 + sprite3->getYVelocity() > SCREEN_HEIGHT) )
			sprite3->toggleYVelocity();
		sprite3->update();
	}
	else sprite3->setSpriteVisibility(true);
	
}

/* loadVideo
 * This function loads the video type needed for this screen
 * */
void CSpriteRotationScreen::loadVideo()
{
	//Main screen
	videoSetMode(  MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);
	vramSetBankB(VRAM_B_MAIN_BG_0x06020000);
	// Setup VRAM_B for Sprite Binary data
	
	//Sub screen
	videoSetModeSub( MODE5 | DISPLAY_BG2_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankC(VRAM_C_SUB_BG_0x06200000);
	vramSetBankD(VRAM_D_SUB_SPRITE);
	//vramSetBankI(VRAM_I_SUB_SPRITE_EXT_PALETTE);
//	BG_PALETTE_SUB[255] = RGB15(31,31,31);	//by default font will be rendered with color 255

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
	
	BG3_CR = BG_BMP16_256x256 | BG_BMP_BASE(8) | BG_PRIORITY_1;
	BG3_XDX = 1 << 8;
	BG3_XDY = 0;
	BG3_YDX = 0;
	BG3_YDY = 1 << 8;
	BG3_CX = 0;
	BG3_CY = 0;
			
	// Sub screen background
	SUB_BG2_CR = BG_BMP16_256x256 | BG_BMP_BASE(0) | BG_PRIORITY_1;
	SUB_BG2_XDX = 1 << 8;
	SUB_BG2_XDY = 0;
	SUB_BG2_YDX = 0;
	SUB_BG2_YDY = 1 << 8;
	SUB_BG2_CX = 0;
	SUB_BG2_CY = 0;

}

void CSpriteRotationScreen::processInput()
{	
	scanKeys();
	
	u32 keys_down = keysDown();
	u32 keys_up = keysUp();
	u32 keys_held = keysHeld();

	iprintf("\x1b[9;0Hkeys_down: %d\nkeys_up: %d\nkeys_held: %d", keys_down, keys_up, keys_held);
	
	if( keys_down | keys_up | keys_held)
	{
		key_pressed = true;
//		errColor.blue();
//		Error();
	}
	else key_pressed = false;
	
	//process start/select here
//	player1->updateAnimation( key_pressed, keys_down, keys_up, keys_held );
	
}




int CSpriteRotationScreen::run()
{
	powerON(POWER_ALL);
	loadVideo();
	loadBackground();
	irqSet(IRQ_VBLANK, 0); 

	
	CDraw canvas;
	CSpriteManager *sm = new CSpriteManager();	

	CSpriteRotations * s1 = new CSpriteRotations();
	sm->registerSprite(s1, true, 0);
	sprite1 = s1;	
	
	CSpriteRotations * s2 = new CSpriteRotations();
	sm->registerSprite(s2, true, 1);
	s2->setTileIndex(128);
	sprite2 = s2;	
	
	CSpriteRotations * s3 = new CSpriteRotations();
	sm->registerSprite(s3, true);
	s3->setTileIndex(256);
	sprite3 = s3;	
	
	// sprite info
	s1-> setXVelocity(4);
	s1-> setYVelocity(4);
	s2->setPosition(100, 78);
	s2-> setXVelocity(6);
	s2-> setYVelocity(-6);
	s3->setPosition(150, 50);
	s3-> setXVelocity(-2);
	s3-> setYVelocity(-2);
	
	// Bottom screen
	dmaCopy(rotate_screenBitmap, (u16*)BG_BMP_RAM(0), rotate_screenBitmapLen);
	screen_buffer = (u16*)0x06020000;//BG_BMP_RAM_SUB(1);
	
	// Setup Timer 2 for player 1
	TIMER2_DATA = TIMER_FREQ_1024(8);
	TIMER2_CR = TIMER_DIV_1024 | TIMER_IRQ_REQ | TIMER_ENABLE;
	irqSet(IRQ_TIMER2, 	spritesUpdate);
		
	touchPosition touchXY;
	
	CButton * rotateLeft = new CButton(21,32,21,32,21+63,32+77);
	CButton * rotateRight = new CButton(97,33,97,33,97+61,33+77);
	CButton * rotateRandom = new CButton(170,33,170,33,170+61,33+77);
	
	CButton * showSprite1 = new CButton(28,153,28,153,28+65,153+30);
	CButton * showSprite2 = new CButton(98,153,98,153,98+65,153+30);
	CButton * showSprite3 = new CButton(168,153,168,153,168+65,153+30);
	
	running = true;
	
	show1 = false;
	show2 = false;
	show3 = false;
	
	bool tapped = false;
	bool update = true;
	
	rotSelection = 10;

	int hours, seconds, minutes; 	
	//The below grabs the time based off the DS, which we use to seed our random
	//generator.  This allows the application to be difference each time its ran.
	time_t unixTime;
	struct tm* timeStruct;
	do{													//When first doing this, I found that it ran so fast that the
		unixTime = time(NULL);							// time returned was actually 0:0:0.  I put this in a do/while
		timeStruct = gmtime((const time_t *)&unixTime);	// loop so it gives the DS a chance to return a valid time.
		hours = timeStruct->tm_hour;
		minutes = timeStruct->tm_min;
		seconds = timeStruct->tm_sec;
	}while((hours == minutes)&&(minutes==seconds)&&(seconds==0));			

	srand(hours+minutes+seconds);		

	while (running) {

		touchXY = touchReadXY();

		if( tapped && (touchXY.px==0) && (touchXY.py==0) )
		{
			tapped = false;
		}
		
		if( !tapped && (touchXY.px!=0) && (touchXY.py!=0) )
		{
			if( !tapped )
				update = true;
			tapped = true;
		}
	
		swiWaitForVBlank();

		if( update )
		{
			canvas.drawRectangle(screen_buffer, CPoint(0,0), CPoint(256,192), CColor(0,0,31), true);
	
			if( rotateLeft->wasClicked(touchXY.px, touchXY.py) )
			{
				rotateLeft->setButtonPressed();
				rotateRight->setButtonReleased();
				rotateRandom->setButtonReleased();
				rotSelection = 0;
			}
			
			if( rotateRight->wasClicked(touchXY.px, touchXY.py) )
			{
				rotateLeft->setButtonReleased();
				rotateRight->setButtonPressed();
				rotateRandom->setButtonReleased();			
				rotSelection = 1;		
			}
			
			if( rotateRandom->wasClicked(touchXY.px, touchXY.py) )
			{			
				rotateLeft->setButtonReleased();
				rotateRight->setButtonReleased();
				rotateRandom->setButtonPressed();
				rotSelection = 2;		
			}
						
			if( showSprite1->wasClicked(touchXY.px, touchXY.py) )
			{
				showSprite1->toggleButton();
				show1 = !show1;
			}
			
			if( showSprite2->wasClicked(touchXY.px, touchXY.py) )
			{
				showSprite2->toggleButton();
				show2 = !show2;
			}
			
			if( showSprite3->wasClicked(touchXY.px, touchXY.py) )
			{
				showSprite3->toggleButton();
				show3 = !show3;
			}

			switch(rotSelection)
			{
				case 0:
					canvas.drawRectangle(screen_buffer, CPoint(21,32), CPoint(21+63,32+77), CColor(31,0,0), true);
					sprite1->setAngularVelocity(.3);
					sprite2->setAngularVelocity(.3);
					sprite3->setAngularVelocity(.3);
					break;
				case 1:
					canvas.drawRectangle(screen_buffer, CPoint(97,33), CPoint(97+61,33+77), CColor(31,0,0), true);
					sprite1->setAngularVelocity(-.3);
					sprite2->setAngularVelocity(-.3);
					sprite3->setAngularVelocity(-.3);
					break;
				case 2:
					canvas.drawRectangle(screen_buffer, CPoint(170,33), CPoint(170+61,33+77), CColor(31,0,0), true);
					int choice = rand()%2;
					if( choice )
						sprite1->setAngularVelocity(.3);
					else
						sprite1->setAngularVelocity(-.3);
										
					choice = rand()%2;
					if( choice )
						sprite2->setAngularVelocity(.3);
					else
						sprite2->setAngularVelocity(-.3);

					choice = rand()%2;
					if( choice )
						sprite3->setAngularVelocity(.3);
					else
						sprite3->setAngularVelocity(-.3);
					break;
			};
			
			if(show1)
				canvas.drawRectangle(screen_buffer, CPoint(28,153), CPoint(28+65,153+30), CColor(0,31,0), true);		
			if(show2)
				canvas.drawRectangle(screen_buffer, CPoint(98,153), CPoint(98+65,153+30), CColor(0,31,0), true);		
			if(show3)
				canvas.drawRectangle(screen_buffer, CPoint(168,153), CPoint(168+65,153+30), CColor(0,31,0), true);	
			
			update = false;
		}
//		processInput();		
		sm->updateSubOAM();

	}	
	
	return 0;
}

