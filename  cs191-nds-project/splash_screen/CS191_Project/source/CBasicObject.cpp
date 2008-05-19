#include "CBasicObject.h"

// the vary fact this this function is part of this class makes this a not-so-very-BasicObject IMO...
bool CBasicObject::checkForCollision(CBasicObject * obj, float toX, float toY) {
	float ax, ay, aw, ah;
	float bx, by, bw, bh;

	bool bright = false;
	bool bleft = false;
	bool btop = false;
	bool bbottom = false;
	
	//set moving object's vars
	ax = toX;
	ay = toY;
	aw = obj->getWidth();
	ah = obj->getHeight();
	
	//set stationary object's vars
	bx = getX();
	by = getY();
	bw = getWidth();
	bh = getHeight();

	iprintf("\x1b[20;0                                                         ");
	iprintf("\x1b[21;0                                                         ");
	iprintf("\x1b[20;0Hax: %d ay: %d  aw: %d ah: %d", (int)ax,(int)ay,(int)aw,(int)ah);
	iprintf("\x1b[21;0Hbx: %d by: %d  bw: %d bh: %d", (int)bx,(int)by,(int)bw,(int)bh);

	//check x-axis
	// if no collisions on the x-axis, so return false
	if( ((ax+aw) < bx) || ((bx+bw) < ax) )		 
		return false;
	
//	else {
//		bright = true;
//		collisionDirection = CDright;
//	}
//	else {
//		bleft = true;
//		collisionDirection = CDleft;
//	}

	//check y-axis
	// if no collision on the y-axis, so return false
	if( ((ay+ah) < by) || ((by+bh) < ay) )
		return false;

//	else {
//		bbottom = true;
//		collisionDirection = CDbottom;
//	}
	
//	if(  )
//		return false;
//	else {
//		btop = true;
//		collisionDirection = CDtop;
//	}
	//TODO: bit-level collision....
	
	if( bright && btop )
		obj->setCollisionDirection(obj->CDtopRight);
	if( bright && bbottom )
		obj->setCollisionDirection(obj->CDbottomRight);
	if( bleft && btop )
		obj->setCollisionDirection(obj->CDtopLeft);
	if( bleft && bbottom )
		obj->setCollisionDirection(obj->CDbottomLeft);
	
	return true;
}


