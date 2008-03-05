#ifndef BASICOBJECT_H_
#define BASICOBJECT_H_

#define DEFAULT_CLICK_RANGE 20
#include <nds/jtypes.h>
/**
 * Basic object definitions, to be overridden/inherited
 */
class basicObject{
	
private:
	typedef struct position{
		int16 x;
		int16 y;
	} Position;
	
	typedef struct clickRange{
		int16 startX;
		int16 endX;
		int16 startY;
		int16 endY;
	} ClickRange;
public:
	bool isClickable;
	Position curPos;
	ClickRange range;
	//TODO: ADD sprites to objects if needed

	basicObject(){
			
		}
		
	// basic constructor, if it is clickable Default offSets are used
	basicObject(int16 x, int16 y, bool click = false){
		curPos.x = x;
		curPos.y = y;
		isClickable = click;
		range.startX = x - DEFAULT_CLICK_RANGE;
		range.startY = y - DEFAULT_CLICK_RANGE;
		range.endX = x + DEFAULT_CLICK_RANGE;
		range.endY = y + DEFAULT_CLICK_RANGE;		
	}
	
	basicObject(int16 x, int16 y, int16 startX, int16 startY, int16 endX, int16 endY){
		curPos.x = x;
		curPos.y = y;
		range.startX = startX;
		range.startY = startY;
		range.endX = endX;
		range.endY = endY;
		isClickable = true;
	}
	//virtual void onClick() {};
	
	virtual ~basicObject(){
		
	}
	void setRange(int16 startX, int16 startY, int16 endX, int16 endY);
	void setStartPos(int16 x, int16 y);
	bool canBeClicked();
	bool wasClicked(int16 x, int16 y); 
	
	
};
#endif /*BASICOBJECT_H_*/
