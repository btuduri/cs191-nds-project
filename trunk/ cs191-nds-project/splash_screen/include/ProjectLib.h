#pragma once

#ifndef PROJECTLIB_H_
#define PROJECTLIB_H_

#define DEBUG 1

//NDS includes
#include <nds.h>

//C++ includes
#include <stdio.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <cassert>

//class CApp;
class CColor;
class CSprite;
//class CSpriteManager;
class CSpriteRotationScreen;
class CPlaygroundScreen;

//extern void Error(u16 r, u16 g, u16 b);
extern CColor errColor;
extern void Error();
extern void Error(u16 r, u16 g, u16 b);

//Project includes
#include "CPoint.h"
#include "CColor.h"
#include "CBasicObject.h"
#include "CMath.h"
#include "CDraw.h"
#include "ScreenType.h"
#include "SpriteType.h"
#include "CApp.h"
#include "CScreen.h"
#include "CScreenManager.h"
#include "CSprite.h"
#include "CSpriteManager.h"
#include "AnimationTypes.h"
#include "CAnimation.h"

#include "CSpriteRotationScreen.h"
#include "CPlaygroundScreen.h"


#endif /*PROJECTLIB_H_*/
