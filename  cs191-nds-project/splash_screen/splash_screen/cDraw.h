#ifndef CDRAW_H_
#define CDRAW_H_

#include <math.h>

#include "cMath.h"
#include "cColor.h"
#include "cScreenManager.h"

class cDraw
{
public:
	void drawPixel(u16* buffer, Point p, Color c);
	
	void drawDot(u16* buffer, Point p, Color c, u16 size=1);
	
	void drawLine(u16* buffer, Point a, Point b, Color c, s16 weight=0);
	void drawRectangle(u16* buffer, Point a, Point b, Color c, bool filled=0);
	void drawCircle(u16* buffer, Point a, int r, Color c, bool filled = 0);

	void swap_points(Point* a, Point* b, int by_xy=0);
	
};



#endif /*CDRAW_H_*/
