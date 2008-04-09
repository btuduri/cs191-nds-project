#include "CDraw.h"

/* function swap_points
 * swaps the points based on the by_xy variable.
 * If 0, returns the points as-is.
 * If 1, swaps the points based on the X coordinate.
 * If 2, swaps the points by the Y coordinate.
 * */
void CDraw::swap_points(CPoint* a, CPoint* b, int by_xy=0)
{
	int x, y;
	switch(by_xy)
	{
		case 0:	return;
		case 1:
			if(a->x > b->x)
			{
				x = b->x;
				y = b->y;
				
				b->x = a->x;
				b->y = a->y;
				
				a->x = x;
				a->y = y;
			}
			return;
		case 2:
			if(a->y > b->y)
			{
				x = b->x;
				y = b->y;
				
				b->x = a->x;
				b->y = a->y;
				
				a->x = x;
				a->y = y;
			}
			return;
	}
}

void CDraw::drawPixel(u16* buffer, CPoint p, CColor c)
{
	buffer[SCREEN_WIDTH*p.y + p.x] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
}


//TODO: finish..  does using circles work here?
/*void CDraw::drawDot(u16* buffer, CPoint p, CColor c, u16 size=1, bool hallow=false)
{
	for(int i = 0; i < size; i++)
	{		
	}
}*/

/* function drawLine
 * Takes two points, a color, and a buffer and draws the line.
 * */
void CDraw::drawLine(u16* buffer, CPoint a, CPoint b, CColor c, s16 weight=0)
{
	int xdif = a.x - b.x;
	int ydif = a.y - b.y;
		
	int xd = abs(xdif);
	int yd = abs(ydif);
	
	// We don't want to div by 0 (if the lines a vertical or horizontal line, so default the xdiff (xd) or ydiff (yd) to 1.
	if( xd == 0 )
		xd = 1;
		
	double lm = ((double)ydif/(double)xd);	// slope of a line is the y-difference over the x-difference
	double lb = a.y - lm*a.x;				// Y intersection of a line

	if( xdif == 0 )  //vertical line
	{
		swap_points(&a, &b, 2);
		for( int i = a.y; i <= b.y; i++ )
		{
			buffer[SCREEN_WIDTH*i + a.x] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		}
	}
	else if( ydif == 0) //horizontal line
	{
		swap_points(&a, &b, 1);
		for( int i = a.x; i <= b.x; i++ )
		{
			buffer[SCREEN_WIDTH*a.y + i] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		}		
	}
	else if( yd > xd ) //if the yd is greater than xd, then we'll have to draw more pixels on the Y axis than the X.
	{
		int x;
		swap_points(&a, &b, 2);	// we want to draw from the "lower" CPoint to the higher.
								//(but remember, "lower" on the screen is actually drawn higher!)
		for( int i = a.y; i <= b.y; i++ )
		{
			x = (int)round((i-lb)/lm);
			buffer[SCREEN_WIDTH*i + x] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		}
	}
	else //if xd is greater, then we'll have to draw more pixels on the X axis. This also draws diagonals where DX=DY
	{
		int y;
		swap_points(&a, &b, 1);
		for( int i = a.x; i <= b.x; i++ )
		{
			y = (int)round((lm*i) + lb);
			buffer[SCREEN_WIDTH*y + i] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		}
	}
}



/* function drawRectangle
 * Given two points (the top-left and the bottom-right corners), draws a regular or solid rectangle based on them.
 * 
 * If the rectangle is *not* filled, then we simply use our draw_line function to draw 4 lines.
 * If the rectangle is filled, then we use the draw_line funtion to draw lines in a horizontal
 * fashion from the top-most line to the bottom-most.
 */
void CDraw::drawRectangle(u16* buffer, CPoint a, CPoint b, CColor c, bool filled=0)
{
	// Swap the points if b is above a	
	swap_points(&a, &b, 2);
	
	if( filled )
	{
		for(int i=a.y; i<b.y; i++)
		{
			drawLine(buffer, CPoint(a.x, i), CPoint(b.x, i), c);
		}
	}
	else
	{
		drawLine(buffer, a, CPoint(b.x, a.y), c);	// top side of rectangle
		drawLine(buffer, a, CPoint(a.x, b.y), c);	// left side of rectangle
		drawLine(buffer, CPoint(a.x, b.y), b, c);	// bottom side of rectangle
		drawLine(buffer, CPoint(b.x, a.y), b, c); 	// right side of rectangle
	}
}

/* function drawCircle
 * Draws a circle based off the circles center and radius.
 * 
 * This function makes two passes when drawing the circle, one on the X-axis and one on the Y-axis.
 * This covers any gaps in the circle when points share the same X or Y coordinate
 * (since the pixels stagger, this occurs often).
 * 
 * I use the equation of the circle (which gives a positive and negative value for each X - Y pair).
 * The equation is given below.
 * 
 * If the circle is to be filled, I just draw a line from the calculated positive and negative values.
 * */
void CDraw::drawCircle(u16* buffer, CPoint a, int r, CColor c, bool filled = 0)
{
	// CPoint a(h,k)
	/* (x-h)^2 + (y-k)^2 = r^2
	 * (y-k)^2 = r^2 - (x-h)^2
	 * y = sqrt(r^2 - (x-h)^2) + k
	 * 
	 * x = sqrt(r^2 - (y-k)^2) + h
	*/ 
	
	int p, q, i, j;
	int r2 = r*r;
	for( i = (a.x - r); i < (a.x + r); i++ )
	{
		p = abs((int)round(sqrt( r2 - (double)((i - a.x)*(i - a.x))) + a.y));
		buffer[SCREEN_WIDTH*p + i] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		q = abs((int)round(-sqrt( r2 - (double)((i - a.x)*(i - a.x))) + a.y));
		buffer[SCREEN_WIDTH*q + i] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		if( filled )
		{
			if( q < 0 ) //this is just a check to make sure we're actually drawing on the buffer.
				q = 0;
			
			for( j = q; (j < p); j++ )
			{
				buffer[SCREEN_WIDTH*j + i] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);				
			}
		}
	}
	// Repeat the above, but on the Y axis now.
	for( i = (a.y - r); i < (a.y + r); i++ )
	{
		p = abs((int)round(sqrt( r2 - (double)((i - a.y)*(i - a.y))) + a.x));
		buffer[SCREEN_WIDTH*i + p] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);
		q = abs((int)round(-sqrt( r2 - (double)((i - a.y)*(i - a.y))) + a.x));
		buffer[SCREEN_WIDTH*i + q] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);	
		if( filled )
		{
			if( q < 0 )
				q = 0;
			
			for( j = q; (j < p); j++ )
			{
				buffer[SCREEN_WIDTH*i + j] = RGB15(c.getR(), c.getB(), c.getG()) | BIT(15);				
			}
		}
	}
}
