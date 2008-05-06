#ifndef SCREENTYPE_H_
#define SCREENTYPE_H_
#pragma once

//Screens
#include "CSplashScreen.h"
#include "CTitleMenuScreen.h"
//#include "CSpriteRotationScreen.h"
#include "CPlaygroundScreen.h"

// change this to override the default screen (the first screen shown)
#define DEFAULT_SCREEN PlaygroundScreen //SplashScreen

#define NoScreen				0
#define SplashScreen			1
#define TitleMenuScreen			2
#define SpriteRotationScreen	3
#define PlaygroundScreen		4

#endif /*SCREENTYPE_H_*/
