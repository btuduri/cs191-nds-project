#ifndef CBASICOBJECT_H_
#define CBASICOBJECT_H_

#define DEFAULT_CLICK_RANGE 20
/**
 * Basic object definitions, to be overridden/inherited
 */
class CBasicObject{
	
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

	bool isClickable;
	Position curPos;
	ClickRange range;
	const unsigned short * activeBG;
	//TODO: ADD sprites to objects if needed
public:
	CBasicObject();
	virtual ~CBasicObject();

	// basic constructor, if it is clickable Default offSets are used
	CBasicObject(int16 x, int16 y, bool click = false){
		curPos.x = x;
		curPos.y = y;
		isClickable = click;
		range.startX = x - DEFAULT_CLICK_RANGE;
		range.startY = y - DEFAULT_CLICK_RANGE;
		range.endX = x + DEFAULT_CLICK_RANGE;
		range.endY = y + DEFAULT_CLICK_RANGE;		
	}
	
	CBasicObject(int16 x, int16 y, int16 startX, int16 startY, int16 endX, int16 endY){
		curPos.x = x;
		curPos.y = y;
		range.startX = startX;
		range.startY = startY;
		range.endX = endX;
		range.endY = endY;
		isClickable = true;
	}
	//virtual void onClick() {};
	
	void setRange(int16 startX, int16 startY, int16 endX, int16 endY);
	void setStartPos(int16 x, int16 y);
	bool canBeClicked();
	bool wasClicked(int16 x, int16 y);
	
	
};

#endif /*CBASICOBJECT_H_*/
