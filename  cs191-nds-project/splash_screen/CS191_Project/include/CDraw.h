#ifndef CDRAW_H_
#define CDRAW_H_

#include "ProjectLib.h"

class CDraw
{
public:
	void drawPixel(u16* buffer, CPoint p, CColor c);
	
	//void drawDot(u16* buffer, CPoint p, CColor  c, u16 size);
	
	void drawLine(u16* buffer, CPoint a, CPoint b, CColor c, s16 weight);
	void drawRectangle(u16* buffer, CPoint a, CPoint b, CColor c, bool filled);
	void drawCircle(u16* buffer, CPoint a, int r, CColor c, bool filled);

	void swap_points(CPoint* a, CPoint* b, int by_xy);
	
};

#endif /*CDRAW_H_*/
