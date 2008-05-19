#include "CCollisionManager.h"

void CCollisionManager::registerSprite(CMovableSprite *sprite) {
	sprites.push_back(sprite);
	numSprites++;
}

bool CCollisionManager::removeSprite(CMovableSprite *sprite) {
	
	vector<CMovableSprite*>::iterator delItr;
	
	delItr = find( sprites.begin(), sprites.end(), sprite );
		
	if(delItr != sprites.end())
	{
		sprites.erase(delItr);
		numSprites--;
		return true;
	}
	
	return false;	// the sprite to be 'removed' wasnt found
}

void CCollisionManager::moveAllSpritesAlongX( float units ) {
	vector<CMovableSprite*>::iterator itr;
	CMovableSprite *sprite = NULL;
	
	for( itr = sprites.begin(); itr != sprites.end(); itr++ )
	{
		sprite = (CMovableSprite*) *itr;
		sprite->setX(sprite->getX()+units);
		sprite->updatePosition();
	}	
}

void CCollisionManager::moveAllSpritesAlongY( float units ) {
	vector<CMovableSprite*>::iterator itr;
	CMovableSprite *sprite = NULL;
	
	for( itr = sprites.begin(); itr != sprites.end(); itr++ )
	{
		
		sprite = (CMovableSprite*) *itr;
		sprite->setY(sprite->getY()+units);
	}
	
	if(sprite)
		sprite->updatePosition();
}

void CCollisionManager::registerObject(CBasicObject *obj) {
	objects.push_back(obj);
	numObjects++;
}

bool CCollisionManager::removeObject(CBasicObject *obj) {
	
	vector<CBasicObject*>::iterator delItr;
	
	delItr = find( objects.begin(), objects.end(), obj );
		
	if(delItr != objects.end())
	{
		objects.erase(delItr);
		numObjects--;
		return true;
	}
	
	return false;	// the sprite to be 'removed' wasnt found
}

void CCollisionManager::moveAllObjectsAlongX( float units ) {
	vector<CBasicObject*>::iterator itr;
	CBasicObject *obj;
	
	for( itr = objects.begin(); itr != objects.end(); itr++ )
	{
		
		obj = (CBasicObject*) *itr;
		obj->setX(obj->getX()+units);
	}
}

void CCollisionManager::moveAllObjectsAlongY( float units ) {
	vector<CBasicObject*>::iterator itr;
	CBasicObject *obj;
	
	for( itr = objects.begin(); itr != objects.end(); itr++ )
	{
		
		obj = (CBasicObject*) *itr;
		obj->setY(obj->getY()+units);
	}
}

bool CCollisionManager::checkObjectCollisions(CBasicObject *cbo, float toX, float toY) {
	vector<CBasicObject*>::iterator oitr;
	CBasicObject *obj;
	bool collide = false;

	for( oitr = objects.begin(); oitr != objects.end(); oitr++ )
	{
		obj = (CBasicObject*) *oitr;
		collide = obj->checkForCollision(cbo, toX, toY);
		if(collide)
		{
			lastObjectTouched = obj;
			return true;
		}
	}
	
	return false;
}

bool CCollisionManager::checkSpriteCollisions(CMovableSprite *sprite, float toX, float toY) {
	vector<CMovableSprite*>::iterator oitr;
	CMovableSprite *obj;
	bool collide = false;
	
	for( oitr = sprites.begin(); oitr != sprites.end(); oitr++ )
	{
		obj = (CMovableSprite*) *oitr;
		collide = obj->checkForCollision(sprite, toX, toY);
		if(collide) {
			lastObjectTouched = (CBasicObject*)obj;
			return true;
		}
	}
	
	return false;
}



