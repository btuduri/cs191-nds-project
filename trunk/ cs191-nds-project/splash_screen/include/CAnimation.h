#ifndef CANIMATION_H_
#define CANIMATION_H_

class CAnimation
{
public:
	CAnimation();
	virtual ~CAnimation();
	virtual void updateAnimation(int key) = 0;
	bool isLocked() { return animationLock; }
	void lockAnimation() { animationLock = true; }
	void clearLock() { animationLock = false; }
private:
	bool animationLock;
};

#endif /*CANIMATION_H_*/
