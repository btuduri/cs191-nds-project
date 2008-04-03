#include "CMarioPAttack.h"

CMarioPAttack::CMarioPAttack()
{
}

CMarioPAttack::~CMarioPAttack()
{
}

void CMarioPAttack::update(SpriteEntry *se) {
	
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
			if(nextAttack)
				switch(attack)
				{
					case attack1: loadB();
					case attack2: loadC();
					default: loadA();
				}
		else
			nextImage--;
	}	

	se->tileIdx = curImage * 128;

}

void CMarioPAttack::load() {
	loadA();	
}

void CMarioPAttack::loadA() {
	attack = attack1;
	nextImage = 1;
	curImage = 0;
	startTitleIndex = 0;
	numImages = 7;
	nextAttack = false;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack1Palette, SPRITE_PALETTE, mario_pattack1PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack1Bitmap, SPRITE_GFX, mario_pattack1BitmapLength);
}

void CMarioPAttack::loadB() {
	attack = attack2;
	nextImage = 1;
	curImage = 0;
	startTitleIndex = 0;
	numImages = 8;
	nextAttack = false;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack2Palette, SPRITE_PALETTE, mario_pattack2PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack2Bitmap, SPRITE_GFX, mario_pattack2BitmapLength);
}

void CMarioPAttack::loadC() {
	attack = attack3;
	nextImage = 1;
	curImage = 0;
	startTitleIndex = 0;
	numImages = 11;
	nextAttack = false;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack3Palette, SPRITE_PALETTE, mario_pattack3PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack3Bitmap, SPRITE_GFX, mario_pattack3BitmapLength);
}


