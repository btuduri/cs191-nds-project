#include "CMovableSprite.h"

CMovableSprite::CMovableSprite() {
	setVelocity(0,0);	
}

CMovableSprite::CMovableSprite(SpriteEntry *se) : CSprite(se) {
	spriteEntry = se;
	isAnimated = false;
	angle = 0;
	rotIndex = 0;
	angularVelocity = 0;

	setVelocity(0,0);
}

void CMovableSprite::updatePosition() {
	
	bool onScreen = checkIfOnScreen();

	if( xMobility )
	{
		setX(getX()+ getXVelocity());
	}
	
	
	if( yMobility )
	{
		setY(getY()+ getYVelocity());
	}

	if( onScreen )
	{
		float x = getX() - curAnimation->getXOffset();//xOffset;
		spriteEntry->posX = (u16)(x+512);
	
		float y = getY() - curAnimation->getYOffset();
		spriteEntry->posY = (u16)(y+512);
	}
}

void CMovableSprite::updateAngle() {
	
	angle += angularVelocity;
	
	rotateSprite();
}

void CMovableSprite::rotateSprite() {
	
	u16 angle = getAngleDeg512();
	
    s16 s = SIN[angle & SPRITE_ANGLE_MASK] >> 4;
    s16 c = COS[angle & SPRITE_ANGLE_MASK] >> 4;
    
    spriteRotation->hdx = c;
    spriteRotation->hdy = s;
    spriteRotation->vdx = -s;
    spriteRotation->vdy = c;
       
}

/*getRelationToCenter()
 * 
 * returns 1 if sprite is to the right of the center
 * returns -1 if sprite is to the left of the center
 * returns 0 if the sprite is centered
 * 
 * */
int CMovableSprite::getRelationToCenter() {
	float center = (SCREEN_WIDTH/2);// - curAnimation->getXOffset();
	float spriteCenter = (cPosition.x - curAnimation->getXOffset()) + cDimension.width/2;
	if( spriteCenter > center )
		return 1;
	else if( spriteCenter < center )
		return -1;
	else return 0;
}

