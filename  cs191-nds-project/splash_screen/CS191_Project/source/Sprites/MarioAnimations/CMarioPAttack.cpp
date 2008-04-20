#include "CMarioPAttack.h"

CMarioPAttack::CMarioPAttack()
{
	xoffset = 16;
	yoffset = 16;
	imageSize = 64;
	attack = 0;
	numAttacks = 0;
	locked = false;
}

CMarioPAttack::~CMarioPAttack()
{
}

void CMarioPAttack::update(SpriteEntry *se) {

//	se->tileIdx = curImage * 128;	
	switch(attack)
	{
		case 0:
				dmaCopy(	(void*)&mario_pattack1Bitmap[curImage * IMAGE_SIZE_64x64H],
							(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
									IMAGE_SIZE_64x64);
				break;
		case 1:
				dmaCopy(	(void*)&mario_pattack2Bitmap[curImage * IMAGE_SIZE_64x64H],
							(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
									IMAGE_SIZE_64x64);
				break;
		case 2:
				dmaCopy(	(void*)&mario_pattack3Bitmap[curImage * IMAGE_SIZE_64x64H],
							(void*)&SPRITE_GFX[se->tileIdx * OFFSET_MULTIPLIER],
									IMAGE_SIZE_64x64);
				break;
		default:
			assert(false);
	};
	
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
				case 1: loadB(); update(se); break;
				case 2: loadC(); update(se); break;
//				default: loadA(); errColor.magenta(); Error();	//this shouldn't happen
			}
		}
		else { 				//otherwise, unlock the animation so a different animation can play
			locked = false;
		}
	}
}

void CMarioPAttack::load(SpriteEntry *se) {
	if( !locked )
	{
		tileIdx = se->tileIdx;
		se->objSize = OBJSIZE_64;
		loadA();
		update(se);
	}
	
	if( (numAttacks < MAX_ATTACKS) && (attack < (MAX_ATTACKS-1)) )
	{
		numAttacks++;
	}
	
}

// punch attack
void CMarioPAttack::loadA() {
	locked = true;
	curImage = 0;
	numImages = 6;
	attack = 0;
	xoffset = 16;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack1Palette, &SPRITE_PALETTE[tileIdx * MAX_PALETTE_SIZE], mario_pattack1PaletteLength);
	
}

// second punch attack
void CMarioPAttack::loadB() {
	curImage = 0;
	numImages = 6;
	attack = 1;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack2Palette, &SPRITE_PALETTE[tileIdx * MAX_PALETTE_SIZE], mario_pattack2PaletteLength);
	
}

// kick attack
void CMarioPAttack::loadC() {

	curImage = 0;
	numImages = 6;
	attack = 2;
	xoffset = 26;
	
	// Load the sprite palette.
	dmaCopy(mario_pattack3Palette, &SPRITE_PALETTE[tileIdx * MAX_PALETTE_SIZE], mario_pattack3PaletteLength);

	
}


