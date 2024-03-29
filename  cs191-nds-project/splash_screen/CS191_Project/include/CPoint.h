#ifndef CPOINT_H_
#define CPOINT_H_
#pragma once

#include "ProjectLib.h"

/* class Point
 * A simple point class for storing x and y coordinates.
 * */
class CPoint
{
public:
	s16 x;
	s16 y;
	
	CPoint(s16 x=0, s16 y=0)
	{ 
		this->x = x;
		this->y = y;
	}
};

class CPoint3D
{
public:
	s16 x;
	s16 y;
	s16 z;
	
	CPoint3D(s16 x=0, s16 y=0, s16 z=0)
	{ 
		this->x = x;
		this->y = y;
	}
};

#endif /*CPOINT_H_*/
