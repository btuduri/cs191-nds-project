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
	
	void setIsCrouching(bool crouch) { isCrouching = crouch; }
	
private:
	bool isCrouching;
	u16 curImage;
};

#endif /*CMARIOCROUCH_H_*/
