#ifndef CMARIORUN_H_
#define CMARIORUN_H_

#include "../ProjectLib.h"
#include "../gfx/mario_run.h"

class CMarioRun : public CAnimation
{
public:
	CMarioRun();
	virtual ~CMarioRun();

	void update(SpriteEntry *se);
	void load();
	
private:
//	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIORUN_H_*/
