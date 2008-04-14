#ifndef CBUTTON_H_
#define CBUTTON_H_

#include "ProjectLib.h"

class CButton : public CBasicObject {
	
public:
	CButton() : CBasicObject() {isPressed=false;}
	CButton(int16 x, int16 y, bool click) :
			CBasicObject(x, y, click) {isPressed=false;}
	CButton(int16 x, int16 y, int16 startX, int16 startY, int16 endX, int16 endY) :
			CBasicObject(x, y, startX, startY, endX, endY) {isPressed=false;}
		
	void setButtonPressed(){isPressed=true;}
	void setButtonReleased(){isPressed=false;}
	bool isButtonPressed(){return isPressed;}
	void toggleButton(){isPressed = !isPressed;}
//	bool wasClicked(touchXY.px, touchXY.py);
	
private:
	bool isPressed;
};



#endif /*CBUTTON_H_*/
