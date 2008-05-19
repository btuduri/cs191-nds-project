#include "CMarioIdle.h"

CMarioIdle::CMarioIdle()
{
	xoffset = 0;
	yoffset = 0;
	nextImage = 1;
	curImage = 0;
	numImages = 4;
	imageSize = 32;
	spriteOffset = 0;
}

CMarioIdle::~CMarioIdle()
{
}


void CMarioIdle::update(CSprite *sprite) {

/*	if( se->tileIdx <= 0 )
	{
		se->objSize = OBJSIZE_64;
	
		iprintf("\x1b[17;0Hoffset: %d  tIdx: %d  oPal: %d", OFFSET_MULTIPLIER, se->tileIdx, se->objPal);
	dmaCopy(	(void*)&mario_spritesBitmap[21 * IMAGE_SIZE_64x64H],
    			(void*)&SPRITE_GFX[0],
    			IMAGE_SIZE_64x64);

	}
	else	{
		se->objSize = OBJSIZE_32;

		iprintf("\x1b[19;0Hoffset: %d  tIdx: %d  oPal: %d", OFFSET_MULTIPLIER, se->tileIdx, se->objPal);
		dmaCopy(	(void*)&mario_spritesBitmap[5 * IMAGE_SIZE_32x32H],
	    			SPRITE_GFX+4096,	//0x06400800
	    			IMAGE_SIZE_32x32);

	}
	*/
	
//works
//	dmaCopy(	(void*)&mario_spritesBitmap[5 * IMAGE_SIZE_32x32H],
//    			SPRITE_GFX+1024,//0x06400800/*
//    			IMAGE_SIZE_32x32);

	
	
	//	iprintf("\x1b[16;0Hmap_x: %d\nmap_y: %d", (int)map->getX(), (int)map->getY());
	
//	dmaCopy(	mario_idleBitmap,
//    			SPRITE_GFX,
//    			IMAGE_SIZE_32x32);
	sprite->setObjSize(OBJSIZE_32);

	dmaCopy(	(void*)&mario_spritesBitmap[(spriteOffset+curImage) * IMAGE_SIZE_32x32H],
				SPRITE_GFX+(4096*sprite->getSpriteIndex()),
    			IMAGE_SIZE_32x32);

	if(nextImage > curImage)	//increasing
	{
		curImage++;
		if(nextImage == (numImages - 1))
			nextImage--;
		else
			nextImage++;
	}
	else						//decreasing
	{
		curImage--;
		
		if(nextImage == 0)
			nextImage++;
		else
			nextImage--;
	}

}

void CMarioIdle::load(CSprite *sprite) {

	sprite->setObjSize(OBJSIZE_32);
	
	nextImage = 1;
	curImage = 0;

//	dmaCopy(mario_spritesPalette, SPRITE_PALETTE, mario_spritesPaletteLength);

//	if( se->tileIdx == 0 )
//	{
//		se->attribute[2] = ATTR2_PALETTE(0);
//		dmaCopy(mario_spritesPalette, &SPRITE_PALETTE[0], 160);//mario_idlePaletteLength);
//		update(se);
//	}
//	else {
//		se->tileIdx = 1;
//		se->attribute[2] = ATTR2_PALETTE(8);
//		dmaCopy(mario_spritesPalette, &SPRITE_PALETTE[96], 160);//mario_idlePaletteLength);
//		update(se);
////		se->tileIdx = 0;
//	}
//	se->attribute[2] = ATTR2_PALETTE(0);
//	update(se);
	
//	dmaCopy(mario_idlePalette, SPRITE_PALETTE, mario_idlePaletteLength);
	update(sprite);
	
//	update(se);
}

