#include "basicObject.h"

	
	
bool basicObject::canBeClicked() {
	return isClickable;
}

bool basicObject::wasClicked(int16 x, int16 y) {
	if (!canBeClicked()){
		return false;
	}
	if (x > range.startX && x < range.endX) {
		if (y < range.endY && y > range.startY)
			return true;
	}
	return false;
}

void basicObject::setRange(int16 startX, int16 startY, int16 endX, int16 endY) {
	range.startX = startX;
	range.startY = startY;
	range.endX = endX;
	range.endY = endY;
	isClickable = true;
}

void basicObject::setStartPos(int16 x, int16 y) {
	curPos.x = x;
	curPos.y = y;
}


