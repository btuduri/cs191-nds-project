#include "CPlatform.h"

bool CPlatform::checkForCollision(CBasicObject * obj, float toX, float toY) {
	
	float ax, ay, aw, ah;
	float bx, by, bw, bh;

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

	iprintf("\x1b[20;0                                                               ");
	iprintf("\x1b[21;0                                                               ");
	iprintf("\x1b[20;0Hax: %d ay: %d  aw: %d ah: %d", (int)ax,(int)ay,(int)aw,(int)ah);
	iprintf("\x1b[21;0Hbx: %d by: %d  bw: %d bh: %d", (int)bx,(int)by,(int)bw,(int)bh);

	collisionDirection = CDbottom;

	if( ((ax+aw)<bx) )
		return false;
	
	if( (ay+ah) < by )
		return false;
		
	if( (ax >(bx+bw)) )
		return false;
	
	if( ay > (by+bh) )
		return false;
	
	if( ax < bx )
	{
		collisionDirection = CDleft;
		if( (ay+ah)-2 > by )
			collisionDirection = CDbottomLeft;
	}
	
	if( (ax+aw) > (bx+bw) )
	{
		collisionDirection = CDright;
		if( (ay+ah)-2 > by )
			collisionDirection = CDbottomRight;
			 
	}
	
	if( ((ax+aw)>bx) && (ax < (bx+bw)) && ((collisionDirection != CDbottomLeft) && (collisionDirection != CDbottomRight) ))
		collisionDirection = CDtop;
	
	return true;
}
