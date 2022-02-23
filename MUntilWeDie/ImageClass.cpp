#include "Stdafx.h"
#include "ImageClass.h"

#define PLAYER_X_SIZE	140

HRESULT ImageClass::init(void)
{
	IMAGEMANAGER->addImage(TEMP_BK_IMG, "Resources/Images/Background/onworking2.bmp", 21818 * 2.125, 780 * 2.125, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(PLAYER_IDLE, "Resources/Images/Player/tex_hero_idle.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(PLAYER_WALK_R, "Resources/Images/Player/tex_hero_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PLAYER_WALK_L, "Resources/Images/Player/tex_hero_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	IMAGEMANAGER->addFrameImage(Obj_Mushroom, "Resources/Images/Objects/mushroom1.bmp", 440 * 2.125, 41 * 2.125, 4, 1, true, RGB(255, 0, 255));

	return S_OK;
}

void ImageClass::release(void)
{

}