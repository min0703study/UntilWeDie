#pragma once
#include <SDKDDKver.h>

//#define WIN32_LEAN_AND_MEAN 

#include <Windows.h>

#include <stdlib.h>
#include <stdio.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>
#include <assert.h>
#include <mmsystem.h>
#include <iostream>
#include <random>

#include <bitset>
#include <vector>
#include <map>
#include <unordered_map>

#include <algorithm>
#include <functional>

#include <gdiplus.h>
#pragma comment(lib, "gdiplus")

using namespace std;

//==Singleton
#define RND RandomFunction::getSingleton()
#define KEYMANAGER KeyManager::getSingleton()
#define IMAGEMANAGER ImageManager::getSingleton()
#define TIMEMANAGER TimeManager::getSingleton()
#define TEMPSOUNDMANAGER TempSoundManager::getSingleton()
#define FONTMANAGER FontManager::getSingleton()
#define IMGCLASS ImageClass::getSingleton()
#define TEXTDATAMANAGER TextDataManager::getSingleton()
#define SCENEMANAGER SceneManager::getSingleton()
#define GDIPLUSMANAGER GdiPlusManager::getSingleton()
#define CAMERA Camera::getSingleton()
//Singleton==

// ��׸� 1���� ���� ��
#define DEG_TO_RAD		0.017453f
#define PI				3.141592653f
#define PI_2			6.283185308f

#define FLOAT_EPSILON		0.001f
#define FLOAT_TO_INT(f1)	static_cast<int>(f1 + FLOAT_EPSILON)
#define FLOAT_EQUAL(f1, f2) (fabs(f1 - f2) <= FLOAT_EPSILON)

#define GRAVITY			9.8f
#define RADIAN			57.296

#define FPS		20

#define USE_FULLSCREEN			FALSE

#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#if USE_FULLSCREEN
#define WINNAME			(LPSTR)(TEXT("WindowsAPI"))
#define WINSTYLE		WS_POPUPWINDOW | WS_MAXIMIZE
#define WINSTART_X		0
#define WINSTART_Y		0

#define WINSIZE_X		GetSystemMetrics(SM_CXSCREEN)
#define WINSIZE_Y		GetSystemMetrics(SM_CYSCREEN)

#define CAMERA_X		GetSystemMetrics(SM_CXSCREEN)
#define CAMERA_Y		GetSystemMetrics(SM_CYSCREEN)
#else
#define WINNAME			(LPSTR)(TEXT("WindowsAPI"))
#define WINSTYLE		WS_CAPTION | WS_SYSMENU
#define WINSTART_X		500
#define WINSTART_Y		0
#define WINSIZE_X		1920
#define WINSIZE_Y		1080
#define CAMERA_X		1920
#define CAMERA_Y		1080
#endif

#define CENTER_X		WINSIZE_X / 2
#define CENTER_Y		WINSIZE_Y / 2

// =============================================
// # ��ũ�� �Լ� # (Ŭ�������� �����Ҵ�� �κ� ����)
// =============================================
#define SAFE_DELETE(p)         {if(p) {delete (p); (p)=nullptr;}}
#define SAFE_DELETE_ARRAY(p)   {if(p) {delete[] (p); (p)=nullptr;}}
#define SAFE_RELEASE(p)         {if(p) {(p)->release(); (p)=nullptr;}}

//==CommonFunction
#include "RandomFunction.h"
#include "TimeManager.h"
#include "TempSoundManager.h"
#include "KeyManager.h"
#include "ImageManager.h"
#include "GdiPlusManager.h"
#include "TempSoundManager.h"
#include "ShapeFunction.h"
#include "FontManager.h"
#include "Utils.h"
#include "ImageClass.h"
#include "SceneManager.h"
#include "Camera.h"
#include "MapInfo.h"
//CommonFunction==

using namespace MY_UTIL;

extern HINSTANCE	_hInstance;
extern HWND			_hWnd;
extern POINT		_ptMouse;

extern int			_winsizeX;
extern int			_winsizeY;

extern int			_winRealSizeX;
extern int			_winRealSizeY;

//min - player size
#define PLAYER_X_SIZE	140
#define PLAYER_Y_SIZE	140
#define PLAYER_Y_ACTION_SIZE	180


//min - player keboard key
#define PLAYER_MOVE_R			'D'
#define PLAYER_MOVE_L			'A'
#define PLAYER_COMMAND_CALL		'S'
#define PLAYER_COMMAND_EXEC		'W'
#define PLAYER_RUN				VK_LSHIFT
#define PLAYER_SHOOT			VK_LBUTTON

//map
#define MAP_X_SIZE				CAMERA_Y * 28
#define MAP_Y_SIZE				CAMERA_Y

#define CAMERA_START_X		MAP_X_SIZE / 2.0f - (CAMERA_X / 2.0f)
#define CAMERA_START_Y		0.0f

#define MAX_MUSHROOM 6;

//ijh - monster size
#define MON_NORMAL_SEARCH_RANGE_X	300
#define MON_NORMAL_SEARCH_RANGE_Y	100
#define MON_NORMAL_ATTACK_RANGE_X	150
#define MON_NORMAL_ATTACK_RANGE_Y	90
#define MON_NORMAL_COLL_RANGE_X		50
#define MON_NORMAL_COLL_RANGE_Y		80
#define MON_NORMAL_IMAGE_RANGE_X	100
#define MON_NORMAL_IMAGE_RANGE_Y	130

#define MON_SUICIDE_SEARCH_RANGE_X	300
#define MON_SUICIDE_SEARCH_RANGE_Y	40
#define MON_SUICIDE_ATTACK_RANGE_X	200
#define MON_SUICIDE_ATTACK_RANGE_Y	40
#define MON_SUICIDE_COLL_RANGE_X	50
#define MON_SUICIDE_COLL_RANGE_Y	40
#define MON_SUICIDE_IMAGE_RANGE_X	100
#define MON_SUICIDE_IMAGE_RANGE_Y	100

#define MON_FROG_SEARCH_RANGE_X		300
#define MON_FROG_SEARCH_RANGE_Y		60
#define MON_FROG_ATTACK_RANGE_X		200
#define MON_FROG_ATTACK_RANGE_Y		60
#define MON_FROG_COLL_RANGE_X		140
#define MON_FROG_COLL_RANGE_Y		60
#define MON_FROG_IMAGE_RANGE_X		100
#define MON_FROG_IMAGE_RANGE_Y		100

#define MON_CANNON_SEARCH_RANGE_X	300
#define MON_CANNON_SEARCH_RANGE_Y	80
#define MON_CANNON_ATTACK_RANGE_X	200
#define MON_CANNON_ATTACK_RANGE_Y	80
#define MON_CANNON_COLL_RANGE_X		100
#define MON_CANNON_COLL_RANGE_Y		80
#define MON_CANNON_IMAGE_RANGE_X	100
#define MON_CANNON_IMAGE_RANGE_Y	100

//ijh - monster infomation
#define PHASE_OF_MONSTER_NUMBER		3
#define SIZE_OF_MONSTER_NUMBER		3
