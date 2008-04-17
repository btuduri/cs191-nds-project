#ifndef CMARIOIDLE_H_
#define CMARIOIDLE_H_

#include "ProjectLib.h"
#include "graphics/mario_idle.h"

class CMarioIdle : public CAnimation
{
public:
	CMarioIdle();
	virtual ~CMarioIdle();
	
	void update(u16 index);
	void load();
	
private:
	u16 nextImage;
	u16 curImage;
};

#endif /*CMARIOIDLE_H_*/
