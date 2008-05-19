#ifndef CCOLLISIONMANAGER_H_
#define CCOLLISIONMANAGER_H_

#include "ProjectLib.h"
#include "CMovableSprite.h"
#include "CBasicObject.h"
#include "CSprite.h"


class CCollisionManager {
public:
	CCollisionManager(){numSprites=0; numObjects=0;}
	~CCollisionManager(){}
	
	void registerSprite(CMovableSprite *sprite);
	bool removeSprite(CMovableSprite *sprite);
	
	void registerObject(CBasicObject *obj);
	bool removeObject(CBasicObject *obj);

	void moveAllSpritesAlongX( float units );
	void moveAllSpritesAlongY( float units );

	void moveAllObjectsAlongX( float units );
	void moveAllObjectsAlongY( float units );

	bool checkObjectCollisions(CBasicObject *cbo, float toX, float toY);
	bool checkSpriteCollisions(CMovableSprite *sprite, float toX, float toY);
	
	CBasicObject *getLastObjectTouched(){return lastObjectTouched;}
	
private:
	
	CBasicObject *lastObjectTouched;
	
	vector<CMovableSprite*> sprites;
	vector<CBasicObject*> objects;
	u32 numSprites;
	u32 numObjects;

	
};


#endif /*CCOLLISIONMANAGER_H_*/
