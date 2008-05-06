#include "CMovableSprite.h"

CMovableSprite::CMovableSprite() {
	setVelocity(0,0);	
}

CMovableSprite::CMovableSprite(SpriteEntry *se) {
	spriteEntry = se;
	isAnimated = false;
	angle = 0;
	rotIndex = 0;
	angularVelocity = 0;

	setVelocity(0,0);
}

void CMovableSprite::updatePosition(float xOffset, float yOffset) {
	if( xMobility )
	{
		setX(getX()+ getXVelocity());
		float x = getX() - xOffset;
		spriteEntry->posX = (u16)x;
	}
	
	if( yMobility )
	{
		setY(getY()+ getYVelocity());
		float y = getY() - yOffset;
		spriteEntry->posY = (u16)y;
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
	int center = (SCREEN_WIDTH/2) - curAnimation->getXOffset();
	if( cPosition.x > center )
		return 1;
	else if( cPosition.x < center )
		return -1;
	else return 0;
}

