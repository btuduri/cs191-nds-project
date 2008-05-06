#include "CButton.h"

// basic constructor, if it is clickable Default offSets are used
CButton::CButton(int16 x, int16 y, bool click){
	cPosition.x = x;
	cPosition.y = y;
	isClickable = click;
	range.startX = x - DEFAULT_CLICK_RANGE;
	range.startY = y - DEFAULT_CLICK_RANGE;
	range.endX = x + DEFAULT_CLICK_RANGE;
	range.endY = y + DEFAULT_CLICK_RANGE;		
	isPressed=false;
}

CButton::CButton(int16 x, int16 y, int16 startX, int16 startY, int16 endX, int16 endY, bool click, bool pressed){
	cPosition.x = x;
	cPosition.y = y;
	range.startX = startX;
	range.startY = startY;
	range.endX = endX;
	range.endY = endY;
	isClickable = click;
	isPressed = pressed;
}

bool CButton::canBeClicked() {
	return isClickable;
}

bool CButton::wasClicked(int16 x, int16 y) {
	if (!canBeClicked()){
		return false;
	}
	if (x > range.startX && x < range.endX) {
		if (y < range.endY && y > range.startY)
			return true;
	}
	return false;
}

void CButton::setRange(int16 startX, int16 startY, int16 endX, int16 endY) {
	range.startX = startX;
	range.startY = startY;
	range.endX = endX;
	range.endY = endY;
	isClickable = true;
}
