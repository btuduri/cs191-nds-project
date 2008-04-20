#pragma once

#ifndef CSPRITEROTATIONS_H_
#define CSPRITEROTATIONS_H_

#include "ProjectLib.h"

#include "graphics/projects/sprite_rotation.h"

class CSpriteRotations : public CMovableSprite
{
public:
	virtual ~CSpriteRotations();

	void initSprite();
	void update();
		
private:
	bool locked;	
};

#endif /*CSPRITEROTATIONS_H_*/
