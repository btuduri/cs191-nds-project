#pragma once

#ifndef PROJECTLIB_H_
#define PROJECTLIB_H_

#define DEBUG 0

// Forward-Declarations
//class CBasicObject;
//class CColor;
//class CSprite;
//class CSpriteRotationScreen;
//class CPlaygroundScreen;
//class CAnimation;
//class CMap;
//class CPlayer;


//Project includes
//class CPoint;
//class CColor;
//class CBasicObject;
//class CMath;
//class CDraw;
//class CButton;

//
//// Application
//class CApp;
//class ScreenType;
//class CScreen;
//class CScreenManager;
//class CPhysics;
////class CControls;
//
//// Sprites
//class SpriteType;
//class CSprite;
//class AnimationTypes;
//class CAnimation;
//class CSpriteManager;
////class CMovableSprite;
//
////Maps
//class CMap;
//class CKirbyMap;
////Player
////class CMario;
////class CPlayer;
////Screens
//class CSplashScreen;
//class CTitleMenuScreen;
////class CSpriteRotationScreen;
//class CPlaygroundScreen;

//project definitions and enums
//extern void Error(u16 r, u16 g, u16 b);
//extern CColor errColor;
//extern void Error();
//extern void Error(u16 r, u16 g, u16 b);



enum PlayerType {
	PMario	
};

//NDS includes
#include <nds.h>

//C++ includes
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <vector.h>
#include <cassert>
#include <time.h>

//Project includes
#include "CPoint.h"
#include "CColor.h"
//#include "CBasicObject.h"
#include "CMath.h"
#include "CDraw.h"

//#include "ScreenType.h"
//#include "Error.h"
//#include "Extern.h"
//#include "SpriteType.h"

//
//// Application
//#include "CApp.h"
//#include "ScreenType.h"
//#include "CScreen.h"
//#include "CScreenManager.h"
//#include "CPhysics.h"
//
//// Sprites
//#include "SpriteType.h"
//#include "CSprite.h"
//#include "AnimationTypes.h"
//#include "CAnimation.h"
//#include "CMovableSprite.h"
//#include "CSpriteManager.h"
//
////Maps
//#include "CMap.h"
//#include "CKirbyMap.h"
//
////Player
//#include "CMario.h"
//#include "CPlayer.h"
//#include "CControls.h"
//
////Screens
//#include "CSplashScreen.h"
//#include "CTitleMenuScreen.h"
//#include "CSpriteRotationScreen.h"
//#include "CPlaygroundScreen.h"

#endif /*PROJECTLIB_H_*/
