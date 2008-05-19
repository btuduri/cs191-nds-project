#ifndef CSPRITEMANAGER_H_
#define CSPRITEMANAGER_H_
#pragma once

#include "ProjectLib.h"
#include "CSprite.h"

#define MAX_SPRITE_SIZE 64

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
	CSpriteManager(bool sub=false);
	virtual ~CSpriteManager();

	void initOAM(bool sub=false);
	void updateOAM(bool sub=false);
	void updateSubOAM();
	
	void registerSprite(CSprite *sprite, bool isRotatable=true, s16 rotationIndex=-1);
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

	/* Keep track of the available tiles */
	int nextAvailableTileIdx;
};

#endif /*CSPRITEMANAGER_H_*/
