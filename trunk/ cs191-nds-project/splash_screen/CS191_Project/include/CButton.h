#ifndef CBUTTON_H_
#define CBUTTON_H_

#include "ProjectLib.h"

#define DEFAULT_CLICK_RANGE 20

class CButton : public CBasicObject {
	
public:
	CButton() {};
	CButton(int16 x, int16 y, bool click=false);
	CButton(int16 x, int16 y, int16 startX, int16 startY, int16 endX, int16 endY, bool click=false, bool pressed=false);		
	void setButtonPressed(){isPressed=true;}
	void setButtonReleased(){isPressed=false;}
	bool isButtonPressed(){return isPressed;}
	void toggleButton(){isPressed = !isPressed;}
//	bool wasClicked(touchXY.px, touchXY.py);
	
	bool wasClicked(int16 x, int16 y);
	void setRange(int16 startX, int16 startY, int16 endX, int16 endY);
	void setStartPos(int16 x, int16 y);
	bool canBeClicked();

	
private:

	typedef struct clickRange{
		int16 startX;
		int16 endX;
		int16 startY;
		int16 endY;
	} ClickRange;

	bool isClickable;
	ClickRange range;

	bool isPressed;
};



#endif /*CBUTTON_H_*/
