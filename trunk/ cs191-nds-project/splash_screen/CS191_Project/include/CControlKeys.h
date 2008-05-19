#ifndef CCONTROLKEYS_H_
#define CCONTROLKEYS_H_

enum Direction {
	none,
	left,
	right,
	up,
	down,
	leftUp,
	leftDown,
	rightUp,
	rightDown
};

class CControlKeys {
public:
	
	virtual ~CControlKeys() {}
	
	virtual void noKeysPressed()=0;
	
	// directional
	virtual void dPadKey(Direction d)=0;	
	
	// main buttons	
	virtual void aKey(Direction d)=0;
	virtual void bKey(Direction d)=0;
	virtual void xKey(Direction d)=0;
	virtual void yKey(Direction d)=0;

	// index buttons
	virtual void leftKey(Direction d)=0;
	virtual void rightKey(Direction d)=0;

	// operational
	virtual void startKey()=0;
	virtual void selectKey()=0;
	
protected:
	
};

#endif /*CCONTROLKEYS_H_*/
