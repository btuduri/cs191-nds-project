#include "ProjectLib.h"

CMovableSprite::CMovableSprite() : CSprite() {
	setVelocity(0,0);	
}

CMovableSprite::CMovableSprite(SpriteEntry *se) : CSprite(se) {
	setVelocity(0,0);
//	xAcceleration = 0;
//	yAcceleration = 0;	
}

void CMovableSprite::updatePosition(float xOffset, float yOffset) {
	
	setX(getX()+ getXVelocity());
	setY(getY()+ getYVelocity());
	
	float x = getX() - xOffset;
	float y = getY() - yOffset;
	
	spriteEntry->posX = (u16)x;
	spriteEntry->posY = (u16)y;	

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
