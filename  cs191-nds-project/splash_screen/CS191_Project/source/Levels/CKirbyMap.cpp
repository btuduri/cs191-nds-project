
#include "CKirbyMap.h"

CKirbyMap::CKirbyMap() {
	
	initalizeMap();
	
}

void CKirbyMap::initalizeMap() {
	
//	cPosition.x = 0;//100.0;
//	cPosition.y = 0;//100.0;
	
}
	
void CKirbyMap::loadMap() {

	setX(100);
	setY(100);

	//Main screen
	videoSetMode(  MODE_5_2D | DISPLAY_BG2_ACTIVE | DISPLAY_BG3_ACTIVE | DISPLAY_SPR_ACTIVE | DISPLAY_SPR_1D );
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	// Main screen background
	BG2_CR = BG_COLOR_256 | BG_RS_32x32 | BG_PRIORITY_1 | BG_BMP_BASE(0) | BG_WRAP_OFF;

	BG2_XDX = 1 << 7; //scale is twice the size of the images width
	BG2_XDY = 0;
	BG2_YDX = 0;
	BG2_YDY = 1 << 7;
    BG2_CX = (int)(cPosition.x) << 8;
	BG2_CY = (int)(cPosition.y) << 8;

	//debugging
	vramSetBankD(VRAM_D_MAIN_BG_0x06040000);
	BG3_CR = BG_BMP16_256x256 | BG_BMP_BASE(16) | BG_PRIORITY_0;
	BG3_XDX = 1 << 8;
	BG3_XDY = 0;
	BG3_YDX = 0;
	BG3_YDY = 1 << 8;
	BG3_CX = 0;
	BG3_CY = 0;
	
//	 Load map image into memory
	dmaCopy(kirbylevelPal, BG_PALETTE, kirbylevelPalLen);	
	dmaCopy(kirbylevelBitmap, (void*)BG_BMP_RAM(0), kirbylevelBitmapLen);
	
}

void CKirbyMap::updateMap() {
	
}

bool CKirbyMap::scrollLeft( u16 units ) {
	
	float x = cPosition.x - (float)units;
	iprintf("\x1b[0;0H                                           ");
	iprintf("\x1b[0;0HgetX(): %d  x: %d", (int)getX(), (int)x);

	// check if we can scroll the amount of units specified
	if( (int)x < CKL_XMINSCROLL )
	{
		//if not, check if we can still move to the MAXSCROLL position.
		if( cPosition.x != CKL_XMINSCROLL  )
		{
			cPosition.x = (float)CKL_XMINSCROLL ;
		    BG2_CX = (int)(cPosition.x) << 8;
		    return true;
		}
		else 		//otherwise, return false.. we cannot scroll
			return false;
	}
	else 	//scroll the amount and return true
	{
		cPosition.x = x;
		BG2_CX = (int)(cPosition.x) << 8;
		return true;
	}
	
	//if we reach here.. false. it shouldn't happen
    return false;

}

bool CKirbyMap::scrollRight( u16 units )
{

	float x = cPosition.x + (float)units;
	iprintf("\x1b[0;0H                                             ");
	iprintf("\x1b[0;0HgetX(): %d  x: %d",  (int)getX(), (int)x);

	// check if we can scroll the amount of units specified
	if( (int)x > CKL_XMAXSCROLL )
	{
		//if not, check if we can still move to the MAXSCROLL position.
		if( cPosition.x != CKL_XMAXSCROLL )
		{
			cPosition.x = (float)CKL_XMAXSCROLL;
		    BG2_CX = (int)cPosition.x << 8;
		    return true;
		}
		//otherwise, return false.. we cannot scroll
		else 
			return false;
	}
	//scroll the amount and return true
	else 
	{
		cPosition.x = x;
	    BG2_CX = (int)cPosition.x << 8;
	    return true;
	}
	
	//if we reach here.. false. it shouldn't happen
    return false;	
}

bool CKirbyMap::scrollUp( u16 units ) 
{
	int y = (int)cPosition.y + units;
	iprintf("\x1b[4;0H                                            ");
	iprintf("\x1b[4;0HgetY(): %d\ny: %d", (int)getY(), (int)y);
	// check if we can scroll the amount of units specified
	if( y > CKL_YMAXSCROLL )
	{
		//if not, check if we can still move to the MAXSCROLL position.
		if( cPosition.y != CKL_YMAXSCROLL )
		{
			cPosition.y = CKL_YMAXSCROLL;
		    BG2_CY = (int)cPosition.y << 8;
		    return true;
		}
		//otherwise, return false.. we cannot scroll
		else 
			return false;
	}
	else 	//scroll the amount and return true
	{
		cPosition.y = y;
	    BG2_CY = (int)cPosition.y << 8;
	    return true;
	}
	
	//if we reach here.. false. it shouldn't happen
    return false;	
}

bool CKirbyMap::scrollDown( u16 units )
{
	int y = (int)cPosition.y - units;
	iprintf("\x1b[4;0H                                         ");
	iprintf("\x1b[4;0HgetY(): %d\ny: %d", (int)getY(), (int)y);

	// check if we can scroll the amount of units specified
	if( y < CKL_YMINSCROLL )
	{
		//if not, check if we can still move to the MAXSCROLL position.
		if( cPosition.y != CKL_YMINSCROLL )
		{
			cPosition.y = CKL_YMINSCROLL;
		    BG2_CY = (int)cPosition.y << 8;
		    return true;
		}
		//otherwise, return false.. we cannot scroll
		else 
			return false;
	}
	//scroll the amount and return true
	else 
	{
		cPosition.y = y;
	    BG2_CY = (int)cPosition.y << 8;
	    return true;
	}
	
	//if we reach here.. false. it shouldn't happen
    return false;	
}
