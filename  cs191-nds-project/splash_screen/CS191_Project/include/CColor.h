#ifndef CCOLOR_H_
#define CCOLOR_H_

#include "ProjectLib.h"

/* class Color
 * A simple color class for storing the R G B values of a color.
 * */

class CColor {
public:
	
	CColor(int r=0, int g=0, int b=0)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	
	void setColor( u16 r, u16 g, u16 b)
	{
		this->r = r;
		this->g = g;
		this->b = b;
	}
	
	void setR(u16 r) { this->r = r; }
	void setG(u16 g) { this->g = g; }
	void setB(u16 b) { this->b = b; }
	
	void getColor(u16* r, u16* g, u16* b)
	{
		*r = this->r;
		*g = this->g;
		*b = this->b;
	}
	
	u16 getR() { return r; }
	u16 getG() { return g; }
	u16 getB() { return b; }
	
	
	void black() 	{ r = 0; g = 0; b = 0; }
	void white() 	{ r = 15; g = 15; b = 15; }
	void red() 		{ r = 15; g = 0; b = 0; }
	void green() 	{ r = 0; g = 15; b = 0; }
	void blue()		{ r = 0; g = 0; b = 15; }
	void yellow()	{ r = 15; g = 15; b = 0; }
	void magenta()	{ r = 15; g = 0; b = 15; }
	void cyan()		{ r = 0; g = 15; b = 15; }
	
private:
	u16 r;
	u16 g;
	u16 b;

};


class Color8bit {
	// TODO: write a 8-bit color class
};

#endif /*CCOLOR_H_*/
