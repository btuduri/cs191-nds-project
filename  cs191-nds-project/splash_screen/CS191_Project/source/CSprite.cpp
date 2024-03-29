#include "CSprite.h"

CSprite::CSprite( SpriteEntry * se )
{
	spriteEntry = se;
	isAnimated = false;
	angle = 0;
	rotIndex = 0;
	angularVelocity = 0;
}

CSprite::~CSprite()
{
}

void CSprite::setSpriteVisibility(bool hidden) {
    if (hidden) {
        /*
         * Make the sprite invisible.
         * 
         * An affine sprite cannot be hidden. We have to turn it into a
         * non-affine sprite before we can hide it. To hide any sprite, we must
         * set bit 8 and clear bit 9. For non-affine sprites, this is a bit
         * redundant, but it is faster than a branch to just set it regardless
         * of whether or not it is already set.
         */
        spriteEntry->isRotoscale = false; // Bit 9 off
        spriteEntry->isHidden = true; // Bit 8 on
    } else {
        /* Make the sprite visible.*/
        if (affine) {
            /* Again, keep in mind that affine sprites cannot be hidden, so
             * enabling affine is enough to show the sprite again. We also need
             * to allow the user to get the double bound flag in the sprite
             * attribute. If we did not, then our sprite hiding function would
             * not be able to properly hide and restore double bound sprites.
             * We enable bit 9 here because we want an affine sprite.
             */
            spriteEntry->isRotoscale = true;

            /* The double bound flag only acts as the double bound flag when
             * the sprite is an affine sprite. At all other times, it acts as
             * the sprite invisibility flag. We only enable bit 8 here if we want
             * a double bound sprite. */
            spriteEntry->rsDouble = doubleBound;
        } else {
            /* Bit 9 (the affine flag) will already be off here, so we don't
             * need to clear it. However, bit 8 (the sprite invisibility flag)
             * will need to be cleared. */
            spriteEntry->isHidden = false;
        }
    }
}

void CSprite::setPosition(float x, float y) {

	setX(x);
	setY(y);
	
	spriteEntry->posX = (u16)(x + 512);
	spriteEntry->posY = (u16)(y + 512);	
}


int CSprite::radToDeg512(float rad) {
	return (int)(rad * (256/PI));
}

void CSprite::toggleFacingDirection() {
	isLookingRight = !isLookingRight;
	spriteEntry->hFlip = (isLookingRight) ? false : true ;
}

void CSprite::setFacingDirection(bool isRight) {
	isLookingRight = isRight;
	spriteEntry->hFlip = (isLookingRight) ? false : true ;
}

bool CSprite::checkIfOnScreen() {
	float x = getX();
	float y = getY();
	float w = getWidth();
	float h = getHeight();
	
	bool offScreen = false;
	
	if( (x > SCREEN_WIDTH) || ( (x+w) < 0 ))
		offScreen = true;
	
	if( (y > SCREEN_HEIGHT) || ( (y+h) < 0 ))
		offScreen = true;
	
	isOffScreen = offScreen;
	return !isOffScreen;
}

