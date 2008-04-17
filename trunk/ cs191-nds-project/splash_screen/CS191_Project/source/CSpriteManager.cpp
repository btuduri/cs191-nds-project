
#include "CSpriteManager.h"

CSpriteManager::CSpriteManager(bool sub) {
	numSprites = 0;
	nextAvailable = 0;
	nextRotationIndex = 0;
	
	if(sub)
		initOAM(sub);
	else
		initOAM();
	
	for(int i=0; i<SPRITE_COUNT; i++)
	{
		sprites[i] = NULL;
	}
}

CSpriteManager::~CSpriteManager() {
}

void CSpriteManager::updateOAM(bool sub) {

	//DC_FlushRange(sprites,128*sizeof(SpriteEntry));
	DC_FlushRange(oam.spriteBuffer, SPRITE_COUNT * sizeof(SpriteEntry));

	//dmaCopy(sprites, OAM, 128 * sizeof(SpriteEntry));
	if(sub)
		dmaCopy(oam.spriteBuffer, OAM_SUB, SPRITE_COUNT * sizeof(SpriteEntry));		
	else
		dmaCopy(oam.spriteBuffer, OAM, SPRITE_COUNT * sizeof(SpriteEntry));

}

// just calls the above.. but a more visually pleasing name
void CSpriteManager::updateSubOAM() {
	updateOAM(true);
}

void CSpriteManager::initOAM(bool sub) {
	
	// Clear all 128 sprites so no artifacts appear.
	for (int i = 0; i < SPRITE_COUNT; i++) {
    	oam.spriteBuffer[i].attribute[0] = ATTR0_DISABLED;
        oam.spriteBuffer[i].attribute[1] = 0;
        oam.spriteBuffer[i].attribute[2] = 0;
        sprites[i] = 0;
	}
    
	for (int i = 0; i < MATRIX_COUNT; i++) {
     // Initalize all the rotation buffers to the identity matrix
		oam.matrixBuffer[i].hdx = 1 << 8;
        oam.matrixBuffer[i].hdy = 0;
        oam.matrixBuffer[i].vdx = 0;
        oam.matrixBuffer[i].vdy = 1 << 8;
	}
    
    /* Wait for vblank before we update the OAM. */
	swiWaitForVBlank();
	updateOAM(sub);
}

void CSpriteManager::registerSprite(CSprite *sprite, bool isRotatable, s16 rotationIndex) {
	
	int index;
	
	// Set up the sprite and give it an index within the oam
	index = getNextSpriteIndex();
//	sprite->setIndex( index );
	sprite->setSpriteEntry(&oam.spriteBuffer[index]);
	sprite->initSprite();
	
	// If the sprite can rotate, we'll assign it a rotation matrix.
	// TODO: fix this code to accommodate more than 32 rotations
	if(isRotatable==true)
	{
		int rotIndex;
		
//		if( (index >= 0) && (rotations[index] == 0 ) )
//		{
//			sprite->setSpriteRotationIndex(index);
//			sprite->setSpriteRotation(&oam.matrixBuffer[0]);
//		}
//		else
		if ( rotationIndex > -1 )
		{
			rotations[rotationIndex] = 0;
			sprite->setSpriteRotationIndex(rotationIndex);
			sprite->setSpriteRotation(&oam.matrixBuffer[rotationIndex]);
		}
		else 
		{
			rotIndex = getNextRotationIndex();
			rotations[rotIndex] = 0;
			sprite->setSpriteRotationIndex(rotIndex);
			sprite->setSpriteRotation(&oam.matrixBuffer[rotIndex]);
		}
	}
	
	sprites[index] = sprite;
	numSprites++;

}

/*return the nextAvailable sprite index and set nextAvailable var to the "last available" spot*/
int CSpriteManager::getNextSpriteIndex() {

	int index = nextAvailable;
	
	do {
		nextAvailable++;
#if DEBUG
		if(nextAvailable >= SPRITE_COUNT) break;
#endif
		if( sprites[nextAvailable] == NULL )
			break;
	} while(nextAvailable < SPRITE_COUNT);
	
#if DEBUG
	if( nextAvailable >= SPRITE_COUNT )			//This should NEVER be false.  If it is, it's a bug
		Error();
#endif		
	
	return index;
}

/*return the next rotation index*/
int CSpriteManager::getNextRotationIndex() {

	int index = nextRotationIndex;
	
	do {
		nextRotationIndex++;
#if DEBUG
		if(nextRotationIndex >= MATRIX_COUNT) break;
#endif
		if( rotations[nextRotationIndex] == 0 )
			break;
	} while(nextRotationIndex < MATRIX_COUNT);
	
#if DEBUG
	if( nextRotationIndex >= MATRIX_COUNT )			//This should NEVER be false.  If it is, it's a bug
		Error();
#endif		
	
	return index;										//Give the sprite access to the 
}

void CSpriteManager::destorySprite( CSprite *sprite )
{
//	int index = sprite->getIndex();
//	unregisterSprite( index );
//	clearSprite(index);
	clearMatrix(sprite->getRotIndex());
	delete sprite;
}

void CSpriteManager::unregisterSprite( int index ) {

#if DEBUG
	if( index >= SPRITE_COUNT );						//This should NEVER be false.  If it is, it's a bug
		Error();
	if( sprites[index] == NULL );						//Again, this is something that should never be false.
		Error();
#endif
		
	// Unregister the rotation index if it was being used
	int rotIndex = sprites[index]->getRotIndex();
	if( rotIndex != 0 )
	{
		if( rotIndex < nextRotationIndex)
			nextRotationIndex = rotIndex;
	}
		
    // if the array index isn't lower than the nextAvailable, then don't update the var
    if( index < nextAvailable )
    	nextAvailable = index;
    
    numSprites--;
}

void CSpriteManager::clearSprite( int index ) {

	oam.spriteBuffer[index].attribute[0] = ATTR0_DISABLED;
    oam.spriteBuffer[index].attribute[1] = 0;
    oam.spriteBuffer[index].attribute[2] = 0;
    oam.spriteBuffer[index].tileIdx = 0;	

}

void CSpriteManager::clearMatrix( int index ) {
    // Initalize the rotation buffer to the identity matrix
	oam.matrixBuffer[index].hdx = 1 << 8;
    oam.matrixBuffer[index].hdy = 0;
    oam.matrixBuffer[index].vdx = 0;
    oam.matrixBuffer[index].vdy = 1 << 8;
}

/*void CSpriteManager::updateSprites() {
	int i = 0;
	
	while( i < numSprites )
	{
		if(sprites[i] != NULL)
			sprites[i]->update();
		i++;
	}
}*/

