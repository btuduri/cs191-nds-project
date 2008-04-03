#ifndef CMARIOWALK_H_
#define CMARIOWALK_H_

//TODO: change this to the walk animation...

#include "../ProjectLib.h"
#include "../gfx/mario_idle.h"

class CMarioWalk : public CAnimation
{
public:
	CMarioWalk();
	virtual ~CMarioWalk();
	
	void update(SpriteEntry *se);
	void load();
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOWALK_H_*/