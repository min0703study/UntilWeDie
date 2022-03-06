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
#include <set>
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
#define EFFECTMANAGER EffectManager::getSingleton()
//Singleton==

// 디그리 1도의 라디안 값
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

#define WINSTART_X		0
#define WINSTART_Y		0

#define WINSIZE_X		1920
#define WINSIZE_Y		1080

#endif

#define CENTER_X		WINSIZE_X / 2
#define CENTER_Y		WINSIZE_Y / 2

// =============================================
// # 매크로 함수 # (클래스에서 동적할당된 부분 해제)
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
#include "EffectManager.h"
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

//min - player keboard key
#define PLAYER_MOVE_R			'D'
#define PLAYER_MOVE_L			'A'
#define PLAYER_COMMAND_CALL		'S'
#define PLAYER_COMMAND_EXEC		'W'
#define PLAYER_COMMAND_POS_CHANGE		'F'
#define PLAYER_DASH				VK_LSHIFT
#define PLAYER_SHOOT			VK_SPACE

#define C_DASH_PROGRESS_BAR		Gdiplus::Color(15,112,108)

//min - player default value
#define PLAYER_DASH_MAX_DASH_TIME			150
#define PLAYER_SPEED_RUN					3.0f
#define PLAYER_SPEED_DASH					6.0f

//min - npc default value
#define NPC_INIT_COUNT			4
#define NPC_BUILD_X_SIZE		220
#define NPC_FOLLOWING_SPACE		120.0f
#define NPC_CALLABLE_X_SIZE		300

//map
#define MAP_X_SIZE				CAMERA_Y * 28
#define MAP_Y_SIZE				CAMERA_Y

#define CAMERA_START_X		MAP_X_SIZE / 2.0f - (CAMERA_X / 2.0f)
#define CAMERA_START_Y		0.0f

#define MAX_MUSHROOM 6;
#define MAX_DEBRIS 10;

//ijh - monster size
#define MON_NORMAL_SEARCH_RANGE_X	300
#define MON_NORMAL_SEARCH_RANGE_Y	100
#define MON_NORMAL_ATTACK_RANGE_X	150
#define MON_NORMAL_ATTACK_RANGE_Y	95
#define MON_NORMAL_COLL_RANGE_X		50
#define MON_NORMAL_COLL_RANGE_Y		95
#define MON_NORMAL_IMAGE_RANGE_X	100
#define MON_NORMAL_IMAGE_RANGE_Y	95

#define MON_SUICIDE_SEARCH_RANGE_X	300
#define MON_SUICIDE_SEARCH_RANGE_Y	40
#define MON_SUICIDE_ATTACK_RANGE_X	200
#define MON_SUICIDE_ATTACK_RANGE_Y	40
#define MON_SUICIDE_COLL_RANGE_X	50
#define MON_SUICIDE_COLL_RANGE_Y	40
#define MON_SUICIDE_IMAGE_RANGE_X	50
#define MON_SUICIDE_IMAGE_RANGE_Y	40

#define MON_FROG_SEARCH_RANGE_X		300
#define MON_FROG_SEARCH_RANGE_Y		80
#define MON_FROG_ATTACK_RANGE_X		200
#define MON_FROG_ATTACK_RANGE_Y		80
#define MON_FROG_COLL_RANGE_X		140
#define MON_FROG_COLL_RANGE_Y		80
#define MON_FROG_IMAGE_RANGE_X		140
#define MON_FROG_IMAGE_RANGE_Y		80

#define MON_CANNON_SEARCH_RANGE_X	400
#define MON_CANNON_SEARCH_RANGE_Y	80
#define MON_CANNON_ATTACK_RANGE_X	300
#define MON_CANNON_ATTACK_RANGE_Y	80
#define MON_CANNON_COLL_RANGE_X		100
#define MON_CANNON_COLL_RANGE_Y		80
#define MON_CANNON_IMAGE_RANGE_X	100
#define MON_CANNON_IMAGE_RANGE_Y	80


//ijh - monster infomation
#define PHASE_OF_MONSTER_NUMBER		3
#define SIZE_OF_MONSTER_NUMBER		3

#define GRAB_MUSHROOM_TIME			500
#define BUILD_BUILDING_TIME			1000

#define DEBUG_ALL_TAG				"ALL"
#define DEBUG_MY_TAG				"민채영"
#define DEBUG_MIN					"민채영"
#define DEBUG_KHS					"김현석"

enum class eDirection {
	Left,
	Right
};
