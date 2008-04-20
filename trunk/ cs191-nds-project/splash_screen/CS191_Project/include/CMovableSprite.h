#ifndef CMOVABLESPRITE_
#define CMOVABLESPRITE_

#include "ProjectLib.h"

class CMovableSprite : public CSprite, public CPhysics {
	
public:
	CMovableSprite();
	CMovableSprite(SpriteEntry *se);
	
	void updatePosition(float xOffset, float yOffset);
	void updateAngle();
	void rotateSprite();

	// rotation and angle
	float getAngularVelocity(){return angularVelocity;}
	void setAngleRad(float angle) {this->angle = angle; }
	void setRotIndex( int index ) { rotIndex = index; }
	void setAngularVelocity(float v){angularVelocity = v;}
	
private:
	
	
};


#endif /*CMOVABLESPRITE_*/
