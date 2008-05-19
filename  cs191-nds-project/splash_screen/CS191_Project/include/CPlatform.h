#ifndef CPLATFORM_H_
#define CPLATFORM_H_

#include "ProjectLib.h"
#include "CBasicObject.h"

class CPlatform : public CBasicObject {
	
public:
	CPlatform() {
		collidable = true;
		rightCollidable = false;
		leftCollidable = false;
		topCollidable = true;
		bottomCollidable = false;
	}
	~CPlatform(){};
	
	bool checkForCollision(CBasicObject * obj, float toX, float toY);
	
};


#endif /*CPLATFORM_H_*/
