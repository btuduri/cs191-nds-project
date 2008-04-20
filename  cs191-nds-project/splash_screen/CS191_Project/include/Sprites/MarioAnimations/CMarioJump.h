#ifndef CMARIOJUMP_H_
#define CMARIOJUMP_H_

#include "ProjectLib.h"
#include "graphics/mario_jump.h"

class CMarioJump : public CAnimation
{
public:
	CMarioJump();
	virtual ~CMarioJump();
	
	void update(SpriteEntry *se);
	void load(SpriteEntry *se);
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOJUMP_H_*/
