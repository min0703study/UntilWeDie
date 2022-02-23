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

	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL, "Resources/Images/Monster/Monster_Normal.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE, "Resources/Images/Monster/Monster_Suicide.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG, "Resources/Images/Monster/Monster_Frog.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON, "Resources/Images/Monster/Monster_Cannon.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	return S_OK;
}

void ImageClass::release(void)
{

}