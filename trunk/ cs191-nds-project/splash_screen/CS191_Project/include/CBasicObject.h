#ifndef CBASICOBJECT_H_
#define CBASICOBJECT_H_
#pragma once

#include "ProjectLib.h"

/**
 * Basic object definitions, to be overridden/inherited
 */
class CBasicObject {

public:
	CBasicObject() {
		collidable = false;
		rightCollidable = false;
		leftCollidable = false;
		topCollidable = false;
		bottomCollidable = false;
}
	virtual ~CBasicObject() {};
	
	// x vars
	float getX(){return cPosition.x;}
	void setX(float x){cPosition.x = x;}
	
	// y vars
	float getY(){return cPosition.y;}
	void setY(float y){ cPosition.y = y; }
	
	void setPosition(float x, float y) {
		cPosition.x = x;
		cPosition.y = y;
	}
	
	// width
	float getWidth(){return cDimension.width;}
	void setWidth(float width){cDimension.width = width;}
	
	// height
	float getHeight(){return cDimension.height;}
	void setHeight(float height){cDimension.height = height;}
	
	void setDimensions(float width, float height) {
		cDimension.width = width;
		cDimension.height = height;
	}
	
	virtual bool checkForCollision(CBasicObject * obj, float toX, float toY);

	void setCollidable( bool isCollidable ){ collidable = isCollidable; }
	bool isCollidable(){ return collidable; }
	
	typedef enum CollisionDirection {
		CDtop,
		CDright,
		CDleft,
		CDbottom,
		CDtopRight,
		CDtopLeft,
		CDbottomRight,
		CDbottomLeft
	};

	void setCollisionDirection(CollisionDirection direction){ collisionDirection = direction; }
	CollisionDirection getCollisionDirection(){ return collisionDirection; }

protected:

	typedef struct position {
		float x;
		float y;
	} Position;
	
	typedef struct dimensions {
		float width;
		float height;
	} Dimensions;
	
	Position cPosition;
	Dimensions cDimension;

	bool collidable;
	
	bool rightCollidable;
	bool leftCollidable;
	bool topCollidable;
	bool bottomCollidable;
	
	CollisionDirection collisionDirection;
	
};

#endif /*CBASICOBJECT_H_*/
