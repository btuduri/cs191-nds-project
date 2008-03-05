#ifndef CPOINT_
#define CPOINT_

#include "cScreenManager.h"

/* class Point
 * A simple point class for storing x and y coordinates.
 * */
class Point
{
public:
	s16 x;
	s16 y;
	
	Point(s16 x=0, s16 y=0)
	{ 
		this->x = x;
		this->y = y;
	}
};

class Point3D
{
public:
	s16 x;
	s16 y;
	s16 z;
	
	Point3D(s16 x=0, s16 y=0, s16 z=0)
	{ 
		this->x = x;
		this->y = y;
	}
};


#endif /*CPOINT_*/
