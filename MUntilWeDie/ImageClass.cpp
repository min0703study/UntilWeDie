#include "Stdafx.h"
#include "ImageClass.h"

HRESULT ImageClass::init(void)
{
	IMAGEMANAGER->addImage(BgImg, "Resources/Images/Background/onworking2.bmp", 21818 * 2.125, 780 * 2.125, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(BgGrassImg, "Resources/Images/Background/GrassField.bmp", 21687 * 2.125, 39 * 2.125, true, RGB(255, 0, 255));

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

	IMAGEMANAGER->addFrameImage(Object_Mushroom, "Resources/Images/Objects/mushroom1.bmp", 440 * 2.125, 41 * 2.125, 4, 1);
	IMAGEMANAGER->addImage(Item_shroom, "Resources/Images/Items/item_shroom.bmp", 22, 21, true, RGB(255, 0 ,255));


	return S_OK;
}

void ImageClass::release(void)
{

}