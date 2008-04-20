#ifndef CMARIORUN_H_
#define CMARIORUN_H_

#include "ProjectLib.h"
#include "graphics/mario_run.h"

class CMarioRun : public CAnimation
{
public:
	CMarioRun();
	virtual ~CMarioRun();

	void update(SpriteEntry *se);
	void load(SpriteEntry *se);
	
private:
	u16 curImage;
};

#endif /*CMARIORUN_H_*/
