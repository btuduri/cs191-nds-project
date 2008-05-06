#pragma once

#ifndef ERROR_H_
#define ERROR_H_

#include "ProjectLib.h"
#include "CColor.h"

CColor errColor(0,0,0);

void Error()
{
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	BG3_CR = BG_BMP16_256x256;
	
	u16* screen_buffer = (u16*)(0x06000000);
	
	for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
	{
		screen_buffer[i] = RGB15(errColor.getR(),errColor.getG(),errColor.getB()) | BIT(15);
	}	
}


void Error(u16 r, u16 g, u16 b)
{
	vramSetBankA(VRAM_A_MAIN_BG_0x06000000);

	BG3_CR = BG_BMP16_256x256;
	
	u16* screen_buffer = (u16*)(0x06000000);
	
	for(int i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
	{
		screen_buffer[i] = RGB15(r,g,b) | BIT(15);
	}
}


#endif /*ERROR_H_*/
