#ifndef CMAP_H_
#define CMAP_H_
#pragma once

#include "ProjectLib.h"
#include "CBasicObject.h"

class CMap : public CBasicObject {
	
public:

	virtual ~CMap(){};
	
	virtual void initalizeMap()=0;
	virtual void loadMap()=0;
	virtual void updateMap()=0;
	virtual bool scrollLeft( u16 units )=0;
	virtual bool scrollRight( u16 units )=0;
	virtual bool scrollUp( u16 units )=0;
	virtual bool scrollDown( u16 units )=0;
	
	
	void setScale(u16 s) { scale = s; }
	float getScale() { return scale; }
	
protected:

	int scale;
	
};

#endif /*CMAP_H_*/
