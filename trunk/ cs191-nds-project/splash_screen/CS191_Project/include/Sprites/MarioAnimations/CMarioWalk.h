#ifndef CMARIOWALK_H_
#define CMARIOWALK_H_

//TODO: change this to the walk animation...

#include "ProjectLib.h"
#include "graphics/mario_idle.h"

class CMarioWalk : public CAnimation
{
public:
	CMarioWalk();
	virtual ~CMarioWalk();
	
	void update(SpriteEntry *se);
	void load(SpriteEntry *se);
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOWALK_H_*/
