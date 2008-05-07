#include "CControls.h"

//	CMap *map;
//	CPlayer *player;
void CControls::processInput() {
	
	scanKeys();
	
	keys_down = keysDown();
	keys_up = keysUp();
	keys_held = keysHeld();
	
	iprintf("\x1b[9;0Hkeys_down: %d\nkeys_up: %d\nkeys_held: %d", keys_down, keys_up, keys_held);
	iprintf("\x1b[12;0Hmap_x: %d\nmap_y: %d", (int)map->getX(), (int)map->getY());
	
	if( keys_down | keys_up | keys_held )
	{
		key_pressed = true;
	}
	else
	{
		key_pressed = false;
		return;
	}
	
	//process start/select here
/*	
	if( player->allowedMobile() )
	{
		if( (keys_held & KEY_UP) || (keys_down & KEY_UP) )
		{
		}
		
		if( (keys_held & KEY_DOWN) || (keys_down & KEY_DOWN) )
		{	
		}
		
		if( (keys_held & KEY_LEFT) || (keys_down & KEY_LEFT) )
		{
			player->setXVelocity(-player->getRunVelocity());
			if( player->toRightOfCenterScreen() )	// if player is to the right of the center
			{
				int pixelDistanceToCenter = (int)(player->getX() - ((float)SCREEN_WIDTH/2) + ((float)player->getSpriteWidth()/2));
				if( pixelDistanceToCenter <= 2 )
					player->setX(((float)SCREEN_WIDTH/2) + ((float)player->getSpriteWidth()/2));
			}
			else if( map->scrollLeft(1) )
				player->lockXMobility();
			else
				player->unlockXMobility();
			
			player->leftKey();
		}

		if( keys_up & KEY_LEFT  &&  !(keys_held & KEY_RIGHT) )
		{
			player->setXVelocity(0);
		}
		
		if( (keys_held & KEY_RIGHT) || (keys_down & KEY_RIGHT) )
		{
			player->setXVelocity(player->getRunVelocity());
			if( player->toLeftOfCenterScreen() )	// if player is to the right of the center
			{
				int pixelDistanceToCenter = (int)(((float)SCREEN_WIDTH/2) - player->getX() + ((float)player->getSpriteWidth()/2));
				if( pixelDistanceToCenter <= 2 )
					player->setX(((float)SCREEN_WIDTH/2) + ((float)player->getSpriteWidth()/2));
			}
			else if( map->scrollRight(1) )
				player->lockXMobility();
			else 
				player->unlockXMobility();			

			player->rightKey();
		}
		
		if( keys_up & KEY_RIGHT  &&  !(keys_held & KEY_LEFT) )
		{
			player->setXVelocity(0);
		}

	}	
*/	
//	player->updateAnimation( key_pressed, keys_down, keys_up, keys_held );
	
}

