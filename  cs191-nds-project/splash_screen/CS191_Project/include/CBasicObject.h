#ifndef CBASICOBJECT_H_
#define CBASICOBJECT_H_
#pragma once

#include "ProjectLib.h"

/**
 * Basic object definitions, to be overridden/inherited
 */
class CBasicObject {

public:
	CBasicObject() {};
	virtual ~CBasicObject() {};
	
	// x vars
	float getX(){return cPosition.x;}
	void setX(float x){cPosition.x = x;}
	
	// y vars
	float getY(){return cPosition.y;}
	void setY(float y){cPosition.y = y;}
	
	void setPosition(float x, float y) {
		cPosition.x = x;
		cPosition.y = y;
	}
;
	
protected:
	
	typedef struct position{
		float x;
		float y;
	} Position;
	
	Position cPosition;
	
//	const unsigned short * activeBG;
//TODO: ADD sprites to objects if needed
	
};

#endif /*CBASICOBJECT_H_*/
