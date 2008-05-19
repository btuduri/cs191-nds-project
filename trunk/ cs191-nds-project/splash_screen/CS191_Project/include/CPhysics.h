#ifndef CPHYSICS_H_
#define CPHYSICS_H_
#pragma once

//#include "ProjectLib.h"

//definitions
#define GRAVITY	.5//9.8/SCREEN_HEIGHT

class CPhysics {

public:

	float getXVelocity(){return cVelocity.vx;}
	void setXVelocity(float vx){cVelocity.vx = vx;}
	void toggleXVelocity(){cVelocity.vx = -cVelocity.vx;}
//	float getXAcceleration(){return xAcceleration;}
//	void setXAcceleration(float ax){xAcceleration = ax;}

	float getYVelocity(){return cVelocity.vy;}
	void setYVelocity(float vy){cVelocity.vy = vy;}
	void toggleYVelocity(){cVelocity.vy = -cVelocity.vy;}	
//	float getYAcceleration(){return yAcceleration;}
//	void setYAcceleration(float ay){yAcceleration = ay;}

	void setVelocity( float vx, float vy ) { cVelocity.vx = vx; cVelocity.vy = vy; }
	
//	bool gravity();
	
protected:

	bool inAir;
	
	typedef struct velocity{
		float vx;
		float vy;
	} Velocity;
	
	Velocity cVelocity;

};


#endif /*CPHYSICS_H_*/
