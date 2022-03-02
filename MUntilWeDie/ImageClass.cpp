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

	IMAGEMANAGER->addImage(Generator_off, "Resources/Images/Building/Generator/Generator_off.bmp", 208, 98);
	IMAGEMANAGER->addFrameImage(Generator_01, "Resources/Images/Building/Generator/Generator_01.bmp", 802, 93, 4, 1);

	IMAGEMANAGER->addImage(shovelshop_off, "Resources/Images/Building/shovelshop/shovelshop_off.bmp", 253, 107, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(shovelshop_off_02, "Resources/Images/Building/shovelshop/shovelshop_off_02.bmp", 253, 107, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(shovelshop_stand, "Resources/Images/Building/shovelshop/shovelshop_stand.bmp", 1518, 107, 6, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_open, "Resources/Images/Building/shovelshop/shovelshop_open.bmp", 2024, 107, 8, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_close, "Resources/Images/Building/shovelshop/shovelshop_close.bmp", 2277, 107, 9, 1);

	IMAGEMANAGER->addImage(shovelshop_shovel, "Resources/Images/Building/shovelshop/shovelshop_shovel.bmp", 20, 54);
	IMAGEMANAGER->addImage(shovelshop_light, "Resources/Images/Building/shovelshop/shovelshop_light.bmp", 139, 82);
	
	IMAGEMANAGER->addFrameImage(Object_Mushroom, "Resources/Images/Objects/mushroom1.bmp", 440 * 2.125, 41 * 2.125, 4, 1);
	IMAGEMANAGER->addImage(Item_shroom, "Resources/Images/Items/item_shroom.bmp", 22, 21, true, RGB(255, 0 ,255));

	//ijh - Monster
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_IDLE, "Resources/Images/Monster/monster_normal_idle.bmp", 800 * 2, 600 * 2, 8, 6);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_WALK, "Resources/Images/Monster/monster_normal_walk.bmp", 800 * 2, 600 * 2, 8, 6);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_ATTACK, "Resources/Images/Monster/monster_normal_attack.bmp", 1100 * 2, 200 * 2, 11, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_DEATH, "Resources/Images/Monster/monster_normal_death.bmp", 1200 * 2, 200 * 2, 12, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_NORMAL_FALL, "Resources/Images/Monster/monster_normal_fall.bmp", 500 * 2, 200 * 2, 5, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_IDLE, "Resources/Images/Monster/monster_suicide_idle.bmp", 200, 80, 4, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_WALK, "Resources/Images/Monster/monster_suicide_walk.bmp", 200, 80, 4, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_SUICIDE_ATTACK, "Resources/Images/Monster/monster_suicide_attack.bmp", 100, 200, 2, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_FROG_IDLE, "Resources/Images/Monster/monster_frog_idle.bmp", 900, 160, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_WALK, "Resources/Images/Monster/monster_frog_walk.bmp", 1200, 160, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_ATTACK, "Resources/Images/Monster/monster_frog_attack.bmp", 1200, 160, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_DEATH, "Resources/Images/Monster/monster_frog_death.bmp", 1500, 160, 10, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_JUMP, "Resources/Images/Monster/monster_frog_jump.bmp", 1650, 160, 11, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_IDLE, "Resources/Images/Monster/monster_cannon_idle.bmp", 600, 180, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_WALK, "Resources/Images/Monster/monster_cannon_walk.bmp", 800, 180, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_ATTACK, "Resources/Images/Monster/monster_cannon_attack.bmp", 800, 180, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_DEATH, "Resources/Images/Monster/monster_cannon_death.bmp", 900, 180, 9, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT1, "Resources/Images/Monster/monster_effect1.bmp", 100, 50, 2, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT2, "Resources/Images/Monster/monster_effect2.bmp", 640, 130, 8, 1);
	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT3, "Resources/Images/Monster/monster_effect3.bmp", 1540, 80, 11, 1, true, RGB(50, 150, 200));
	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT4, "Resources/Images/Monster/monster_effect4.bmp", 360, 60, 6, 1);

	return S_OK;
}

void ImageClass::release(void)
{

}