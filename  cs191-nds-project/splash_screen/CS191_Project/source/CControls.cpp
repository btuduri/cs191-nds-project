#include "CControls.h"

//	CMap *map;
//	CPlayer *player;
void CControls::processInput() {
	
	scanKeys();
	
	keys_down = keysDown();
	keys_up = keysUp();
	keys_held = keysHeld();
	
	iprintf("\x1b[9;0H                                                                ");
	iprintf("\x1b[9;0Hkeys_down: %d\nkeys_up: %d\nkeys_held: %d", keys_down, keys_up, keys_held);
	iprintf("\x1b[12;0H                                                               ");
	iprintf("\x1b[12;0Hmap_x: %d    map_y: %d", (int)map->getX(), (int)map->getY());
	
	if( keys_down | keys_up | keys_held )
	{
		key_pressed = true;
	}
	else
	{
		key_pressed = false;
		player->noKeysPressed();
		return;
	}
	
	//process start/select here
	if( player->isPlayerAllowedMobile() )
	{
		if( (keys_held & KEY_UP) || (keys_down & KEY_UP) )
		{
//			if( map->scrollDown(1) )
//			{
//				collisionManager->moveAllSpritesAlongY(2);
//				collisionManager->moveAllObjectsAlongY(2);
//			}
			player->dPadKey(up);
		}
		
		if( (keys_down & KEY_DOWN) || (keys_up & KEY_DOWN) )
		{
//			if( map->scrollUp(1) )
//			{
//				collisionManager->moveAllSpritesAlongY(-2);
//				collisionManager->moveAllObjectsAlongY(-2);
//			}
			player->dPadKey(down);
		}
		
		if( (keys_held & KEY_LEFT) || (keys_down & KEY_LEFT) )
		{
			if( player->toRightOfCenterScreen() )	// if player is to the right of the center
			{
				int pixelDistanceToCenter = (int)(player->getPlayerX() - ((float)SCREEN_WIDTH/2) + ((float)player->getPlayerWidth()/2));
				if( pixelDistanceToCenter <= 3 )
					player->setPlayerX(((float)SCREEN_WIDTH/2) - ((float)player->getPlayerWidth()/2));
				player->setPlayerXMobility(true);
			}
			else if( map->scrollLeft(1) )
			{
				collisionManager->moveAllSpritesAlongX(2);
				collisionManager->moveAllObjectsAlongX(2);
				if( collisionManager->checkSpriteCollisions(player->getSprite(), player->getPlayerX(), player->getPlayerY()) )
				{
					map->scrollRight(1);
					collisionManager->moveAllSpritesAlongX(-2);
					collisionManager->moveAllObjectsAlongX(-2);
					iprintf("\x1b[22;0Htrue...");
				}
				else if(collisionManager->checkObjectCollisions((CBasicObject*)player->getSprite(), player->getPlayerX(), player->getPlayerY()))
				{
					if( collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDtop 
						&& collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDleft
						&& collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDbottomLeft)
					{
						map->scrollRight(1);
						collisionManager->moveAllSpritesAlongX(-2);
						collisionManager->moveAllObjectsAlongX(-2);
						iprintf("\x1b[22;0Htrue...");
					}
				}
				else
					iprintf("\x1b[22;0Hfalse...");
				player->setPlayerXMobility(false);
			}
			else
				player->setPlayerXMobility(true);
			
			player->dPadKey(left);
		}

		if( keys_up & KEY_LEFT  &&  !(keys_held & KEY_RIGHT) )
		{
//			player->setXVelocity(0);
		}
		
		if( (keys_held & KEY_RIGHT) || (keys_down & KEY_RIGHT) )
		{
			if( player->toLeftOfCenterScreen() )	// if player is to the left of the center
			{
				int pixelDistanceToCenter = (int)(((float)SCREEN_WIDTH/2) - player->getPlayerX() + ((float)player->getPlayerWidth()/2));
				if( pixelDistanceToCenter <= 3 )
					player->setPlayerX(((float)SCREEN_WIDTH/2) - ((float)player->getPlayerWidth()/2));
				player->setPlayerXMobility(true);
			}
			else if( map->scrollRight(1) )
			{
				collisionManager->moveAllSpritesAlongX(-2);
				collisionManager->moveAllObjectsAlongX(-2);

				//collisionManager->checkObjectCollisions((CBasicObject*)player->getSprite(), player->getPlayerX(), player->getPlayerY())
				if( collisionManager->checkSpriteCollisions(player->getSprite(), player->getPlayerX(), player->getPlayerY()))
				{
					map->scrollLeft(1);
					collisionManager->moveAllSpritesAlongX(2);
					collisionManager->moveAllObjectsAlongX(2);
					iprintf("\x1b[22;0Htrue...   ");
				}
				else if(collisionManager->checkObjectCollisions((CBasicObject*)player->getSprite(), player->getPlayerX(), player->getPlayerY()))
				{
					if( collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDtop
						&& collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDright
						&& collisionManager->getLastObjectTouched()->getCollisionDirection() != CBasicObject::CDbottomRight)
					{
						map->scrollLeft(1);
						collisionManager->moveAllSpritesAlongX(2);
						collisionManager->moveAllObjectsAlongX(2);
						iprintf("\x1b[22;0Htrue...   ");
					}
				}
				else
					iprintf("\x1b[22;0Hfalse...   ");
				player->setPlayerXMobility(false);
			}
			else
				player->setPlayerXMobility(true);

			player->dPadKey(right);
		}
		
		if( keys_up & KEY_RIGHT  &&  !(keys_held & KEY_LEFT) )
		{
//			player->setXVelocity(0);
		}
	}	

	if( keys_up & KEY_A )
	{
		player->aKey(none);
	}

	
	if( keys_up & KEY_X )
	{
		player->setPlayerCollidable(!player->isPlayerCollidable());
	}

//	player->updateAnimation( key_pressed, keys_down, keys_up, keys_held );
	
}
