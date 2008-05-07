#ifndef CKIRBYMAP_H_
#define CKIRBYMAP_H_
#pragma once

#include "ProjectLib.h"
#include "CMap.h"
#include "../graphics/levels/kirbylevel.h"

#define CKL_XMAXSCROLL 210
#define CKL_XMINSCROLL -85


/* CKirbyMap
 * 
 * This map is very basic: 3 platforms and a ground.
 * 
 * The image size is 256x256, but the ingame scale is twice, making it 512x512
 * 
 * Scrolling goes from (-768, 768) top and bottom.
 * 
 * 
 * */

class CKirbyMap : public CMap
{
	
public:
	CKirbyMap();
	
	void initalizeMap();
	void loadMap();
	void updateMap();
	
	bool scrollLeft( u16 units );
	bool scrollRight( u16 units );
	bool scrollUp( u16 units );
	bool scrollDown( u16 units );

private:
	
	
};

#endif /*CKIRBYMAP_H_*/
