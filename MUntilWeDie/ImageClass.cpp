#include "Stdafx.h"
#include "ImageClass.h"

HRESULT ImageClass::init(void)
{
	IMAGEMANAGER->addImage(TempBkImg, "Resources/Images/Background/tempBackground.bmp", 3713, 1080);

	IMAGEMANAGER->addFrameImage(PlayerIdleL, "Resources/Images/Player/tex_hero_idle_l.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(PlayerIdleR, "Resources/Images/Player/tex_hero_idle_r.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);

	IMAGEMANAGER->addFrameImage(PlayerWalkR, "Resources/Images/Player/tex_hero_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerWalkL, "Resources/Images/Player/tex_hero_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	IMAGEMANAGER->addFrameImage(PlayerRunR, "Resources/Images/Player/tex_hero_run_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerRunL, "Resources/Images/Player/tex_hero_run_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	IMAGEMANAGER->addFrameImage(PlayerCommandCallR, "Resources/Images/Player/tex_hero_command_r.bmp", PLAYER_X_SIZE * 11, PLAYER_Y_ACTION_SIZE, 11, 1);
	IMAGEMANAGER->addFrameImage(PlayerCommandCallL, "Resources/Images/Player/tex_hero_command_l.bmp", PLAYER_X_SIZE * 11, PLAYER_Y_ACTION_SIZE, 11, 1);
	IMAGEMANAGER->addFrameImage(PlayerCommandExecR, "Resources/Images/Player/tex_hero_command2_r.bmp", PLAYER_X_SIZE * 8, PLAYER_Y_ACTION_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerCommandExecL, "Resources/Images/Player/tex_hero_command2_l.bmp", PLAYER_X_SIZE * 8, PLAYER_Y_ACTION_SIZE, 8, 1);


	IMAGEMANAGER->addImage(Generator_off, "Resources/Images/Building/Generator/Generator_off.bmp", 208, 98);
	IMAGEMANAGER->addFrameImage(Generator_01, "Resources/Images/Building/Generator/Generator_01.bmp", 802, 93, 4, 1);

	IMAGEMANAGER->addImage(shovelshop_off, "Resources/Images/Building/shovelshop/shovelshop_off.bmp", 253, 107, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(shovelshop_off_02, "Resources/Images/Building/shovelshop/shovelshop_off_02.bmp", 253, 107, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(shovelshop_stand, "Resources/Images/Building/shovelshop/shovelshop_stand.bmp", 1518, 107, 6, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_open, "Resources/Images/Building/shovelshop/shovelshop_open.bmp", 2024, 107, 8, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_close, "Resources/Images/Building/shovelshop/shovelshop_close.bmp", 2277, 107, 9, 1);

	IMAGEMANAGER->addImage(shovelshop_shovel, "Resources/Images/Building/shovelshop/shovelshop_shovel.bmp", 20, 54);
	IMAGEMANAGER->addImage(shovelshop_light, "Resources/Images/Building/shovelshop/shovelshop_light.bmp", 139, 82);

	return S_OK;
}

void ImageClass::release(void)
{

}