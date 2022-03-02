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

	//ijh - Monster
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_IDLE, "Resources/Images/Monster/monster_normal_idle.bmp", 800 * 2, 600 * 2, 8, 6);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_WALK, "Resources/Images/Monster/monster_normal_walk.bmp", 800 * 2, 600 * 2, 8, 6);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_ATTACK, "Resources/Images/Monster/monster_normal_attack.bmp", 1100 * 2, 200 * 2, 11, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_DEATH, "Resources/Images/Monster/monster_normal_death.bmp", 1200 * 2, 200 * 2, 12, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_FALL, "Resources/Images/Monster/monster_normal_fall.bmp", 500 * 2, 200 * 2, 5, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_IDLE, "Resources/Images/Monster/monster_suicide_idle.bmp", 200 * 2, 80 * 2, 4, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_WALK, "Resources/Images/Monster/monster_suicide_walk.bmp", 200 * 2, 80 * 2, 4, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_ATTACK, "Resources/Images/Monster/monster_suicide_attack.bmp", 100 * 2, 80 * 2, 2, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_DEATH1, "Resources/Images/Monster/monster_effect1.bmp", 100 * 2, 50 * 2, 2, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_DEATH2, "Resources/Images/Monster/monster_effect2.bmp", 640 * 2, 130 * 2, 8, 1);

	IMAGEMANAGER->addFrameImage(MONSTER_FROG_IDLE, "Resources/Images/Monster/monster_frog_idle.bmp", 900, 160, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_WALK, "Resources/Images/Monster/monster_frog_walk.bmp", 1200, 160, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_ATTACK, "Resources/Images/Monster/monster_frog_attack.bmp", 1200, 160, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_DEATH, "Resources/Images/Monster/monster_frog_death.bmp", 1500, 160, 10, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_JUMP, "Resources/Images/Monster/monster_frog_jump.bmp", 1650, 160, 11, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_IDLE, "Resources/Images/Monster/monster_cannon_idle.bmp", 600, 180, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_WALK, "Resources/Images/Monster/monster_cannon_walk.bmp", 800, 180, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_ATTACK, "Resources/Images/Monster/monster_cannon_attack.bmp", 800, 180, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_DEATH, "Resources/Images/Monster/monster_cannon_death.bmp", 900, 180, 9, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT3, "Resources/Images/Monster/monster_effect3.bmp", 1540, 80, 11, 1, true, RGB(50, 150, 200));
	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT4, "Resources/Images/Monster/monster_effect4.bmp", 360, 60, 6, 1);

	return S_OK;
}

void ImageClass::release(void)
{

}