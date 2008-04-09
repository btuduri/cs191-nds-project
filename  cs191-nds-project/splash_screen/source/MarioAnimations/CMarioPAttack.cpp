#include "CMarioPAttack.h"

CMarioPAttack::CMarioPAttack()
{
	xoffset = 0;
	yoffset = 0;
	imageSize = 32;
	attack = 0;
	numAttacks = 0;
	locked = false;
}

CMarioPAttack::~CMarioPAttack()
{
}

void CMarioPAttack::update(SpriteEntry *se) {

	se->tileIdx = curImage * 128;	
	
	//animation is always increasing (i.e. its a one-way animation)	
	if( curImage < (numImages-1) )
		curImage++;
	else 
	{
		if( numAttacks > 0)
			numAttacks--;
		
		if(numAttacks > 0)		//if there are more attacks, then grab the next animation and continue
		{
//			iprintf("\x1b[14;0h numAttack: %d", numAttacks);
			attack++;
			if(attack > 2) attack = 0;
			switch(attack)
			{
//				case 0: loadA(); errColor.cyan(); Error(); break;
				case 1: loadB(); break;
				case 2: loadC(); break;
//				default: loadA(); errColor.magenta(); Error();	//this shouldn't happen
			}
		}
		else { 				//otherwise, unlock the animation so a different animation can play
			locked = false;
		}
	}
}

void CMarioPAttack::load() {
	if( !locked )
		loadA();
	
	if( (numAttacks < MAX_ATTACKS) && (attack < (MAX_ATTACKS-1)) )
	{
		numAttacks++;
	}
	
}

void CMarioPAttack::loadA() {
//	nextImage = 1;
	curImage = 0;
	numImages = 6;
//	nextAttack = false;
	locked = true;
	attack = 0;
	xoffset = 0;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack1Palette, SPRITE_PALETTE, mario_pattack1PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack1Bitmap, SPRITE_GFX, mario_pattack1BitmapLength);
}

void CMarioPAttack::loadB() {
//	nextImage = 1;
	curImage = 0;
	numImages = 6;
//	nextAttack = false;
	locked = true;
	attack = 1;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack2Palette, SPRITE_PALETTE, mario_pattack2PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack2Bitmap, SPRITE_GFX, mario_pattack2BitmapLength);
}

void CMarioPAttack::loadC() {
//	nextImage = 1;
	curImage = 0;
	numImages = 6;
//	nextAttack = false;
	locked = true;
	attack = 2;
	xoffset = 10;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack3Palette, SPRITE_PALETTE, mario_pattack3PaletteLength);
	
	// Load the sprite binary data into the VRAM
	dmaCopy(mario_pattack3Bitmap, SPRITE_GFX, mario_pattack3BitmapLength);
}


