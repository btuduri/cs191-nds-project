#ifndef CMARIOCROUCH_H_
#define CMARIOCROUCH_H_

#include "../ProjectLib.h"
#include "../gfx/mario_crouch.h"

class CMarioCrouch : public CAnimation
{
public:
	CMarioCrouch();
	virtual ~CMarioCrouch();

	void update(SpriteEntry *se);
	void load();
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOCROUCH_H_*/