#include "Stdafx.h"
#include "ImageClass.h"

#define PLAYER_X_SIZE	140

HRESULT ImageClass::init(void)
{
	IMAGEMANAGER->addImage(TEMP_BK_IMG, "Resources/Images/Background/tempBackground.bmp", 3713, 1080);

	IMAGEMANAGER->addFrameImage(PLAYER_IDLE, "Resources/Images/Player/tex_hero_idle.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(PLAYER_WALK_R, "Resources/Images/Player/tex_hero_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PLAYER_WALK_L, "Resources/Images/Player/tex_hero_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	return S_OK;
}

void ImageClass::release(void)
{

}