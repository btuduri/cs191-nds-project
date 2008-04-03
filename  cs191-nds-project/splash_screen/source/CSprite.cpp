
#include "CSprite.h"

CSprite::CSprite( SpriteEntry * se )
{
	spriteEntry = se;
	isAnimated = false;
	angle = 0;
	rotIndex = 0;
}

CSprite::~CSprite()
{
}

void CSprite::rotateSprite() {
	
	u16 angle = getAngleDeg512();
	
    s16 s = SIN[angle & SPRITE_ANGLE_MASK] >> 4;
    s16 c = COS[angle & SPRITE_ANGLE_MASK] >> 4;
    
    spriteRotation->hdx = c;
    spriteRotation->hdy = s;
    spriteRotation->vdx = -s;
    spriteRotation->vdy = c;
       
}

void CSprite::rotateSprite(u16 angle) {
	
    s16 s = SIN[angle & SPRITE_ANGLE_MASK] >> 4;
    s16 c = COS[angle & SPRITE_ANGLE_MASK] >> 4;
    
    spriteRotation->hdx = c;
    spriteRotation->hdy = s;
    spriteRotation->vdx = -s;
    spriteRotation->vdy = c;
       
}


// TODO:: fix this to be mine!  This is a copy of the tutorial code...
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

void CSprite::setPosition(u16 x, u16 y) {
	spriteEntry->posX = x;
	spriteEntry->posY = y;
}


int CSprite::radToDeg512(float rad) {
	return (int)(rad * (256/PI));
}


