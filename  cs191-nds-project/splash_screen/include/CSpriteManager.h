#pragma once

#ifndef CSPRITEMANAGER_H_
#define CSPRITEMANAGER_H_

#include "ProjectLib.h"

/**
 * CSpriteManager
 * 		- init ALL sprites ( zero them out )
 * 		- updateOAM
 * 		- registerSprite (returns an unused index)
 * 		- unregisterSprite ( recieves a sprite * )
 */

class CSpriteManager
{
public:
	CSpriteManager();
	virtual ~CSpriteManager();

	void initOAM();
	void updateOAM();

	void registerSprite(CSprite *sprite, bool isRotatable=true);
	void destorySprite(CSprite *sprite);
	void clearSprite( int index );
	void clearMatrix( int index );

	//void updateSprites();
	
private:
	int getNextSpriteIndex();
	int getNextRotationIndex();
	void unregisterSprite( int index );	
	
	
	tOAM oam;
	CSprite* sprites[SPRITE_COUNT];
	u8 rotations[MATRIX_COUNT];
	u8 numSprites;
	u8 nextAvailable;
	u8 nextRotationIndex;
};

#endif /*CSPRITEMANAGER_H_*/
