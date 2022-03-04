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
	IMAGEMANAGER->addFrameImage(PlayerRunShootL, "Resources/Images/Player/tex_hero_run_reload_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerRunShootR, "Resources/Images/Player/tex_hero_run_reload_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerShootL, "Resources/Images/Player/tex_hero_reload_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(PlayerShootR, "Resources/Images/Player/tex_hero_reload_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	IMAGEMANAGER->addFrameImage(CivilianIdleL, "Resources/Images/Npc/tex_civilian_idle_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianIdleR, "Resources/Images/Npc/tex_civilian_idle_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianWalkR, "Resources/Images/Npc/tex_civilian_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianWalkL, "Resources/Images/Npc/tex_civilian_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianRunR, "Resources/Images/Npc/tex_civilian_run_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianRunL, "Resources/Images/Npc/tex_civilian_run_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianGrabL, "Resources/Images/Npc/tex_civilian_grab_r.bmp", PLAYER_X_SIZE * 4, PLAYER_X_SIZE, 4, 1);
	IMAGEMANAGER->addFrameImage(CivilianGrabR, "Resources/Images/Npc/tex_civilian_grab_l.bmp", PLAYER_X_SIZE * 4, PLAYER_X_SIZE, 4, 1);
	IMAGEMANAGER->addFrameImage(CivilianBuildR, "Resources/Images/Npc/tex_civilian_build_r.bmp", NPC_BUILD_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(CivilianBuildL, "Resources/Images/Npc/tex_civilian_build_l.bmp", NPC_BUILD_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);

	IMAGEMANAGER->addFrameImage(DiggerIdleL, "Resources/Images/Npc/tex_digger_idle_l.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(DiggerIdleR, "Resources/Images/Npc/tex_digger_idle_r.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(DiggerWalkR, "Resources/Images/Npc/tex_digger_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(DiggerWalkL, "Resources/Images/Npc/tex_digger_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(DiggerRunR, "Resources/Images/Npc/tex_digger_run_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(DiggerRunL, "Resources/Images/Npc/tex_digger_run_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(DiggerGrabL, "Resources/Images/Npc/tex_digger_grab_l.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(DiggerGrabR, "Resources/Images/Npc/tex_digger_grab_r.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(DiggerBuildL, "Resources/Images/Npc/tex_digger_build_l.bmp", NPC_BUILD_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(DiggerBuildR, "Resources/Images/Npc/tex_digger_build_r.bmp", NPC_BUILD_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);

	IMAGEMANAGER->addFrameImage(EngineerIdleL, "Resources/Images/Npc/tex_engineer_idle_l.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(EngineerIdleR, "Resources/Images/Npc/tex_engineer_idle_r.bmp", PLAYER_X_SIZE * 6, PLAYER_X_SIZE, 6, 1);
	IMAGEMANAGER->addFrameImage(EngineerWalkR, "Resources/Images/Npc/tex_engineer_walk_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(EngineerWalkL, "Resources/Images/Npc/tex_engineer_walk_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(EngineerRunR, "Resources/Images/Npc/tex_engineer_run_r.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(EngineerRunL, "Resources/Images/Npc/tex_engineer_run_l.bmp", PLAYER_X_SIZE * 8, PLAYER_X_SIZE, 8, 1);
	IMAGEMANAGER->addFrameImage(EngineerBuildR, "Resources/Images/Npc/tex_engineer_build_r.bmp", PLAYER_X_SIZE * 12, PLAYER_X_SIZE, 12, 1);
	IMAGEMANAGER->addFrameImage(EngineerBuildL, "Resources/Images/Npc/tex_engineer_build_l.bmp", PLAYER_X_SIZE * 12, PLAYER_X_SIZE, 12, 1);

	//KHS - BUilding
	IMAGEMANAGER->addImage(Generator_off, "Resources/Images/Building/Generator/Generator_off.bmp", 208, 98, true, RGB(255, 0, 255));
	IMAGEMANAGER->addFrameImage(Generator_01, "Resources/Images/Building/Generator/Generator_01.bmp", 802, 93, 4, 1);

	IMAGEMANAGER->addImage(shovelshop_off, "Resources/Images/Building/shovelshop/shovelshop_off.bmp", 253 * 2, 107 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(shovelshop_off_02, "Resources/Images/Building/shovelshop/shovelshop_off_02.bmp", 253 * 2, 107 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(shovelshop_stand, "Resources/Images/Building/shovelshop/shovelshop_stand.bmp", 1518 * 2, 107 * 2, 6, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_open, "Resources/Images/Building/shovelshop/shovelshop_open.bmp", 2024 * 2, 107 * 2, 8, 1);
	IMAGEMANAGER->addFrameImage(shovelshop_close, "Resources/Images/Building/shovelshop/shovelshop_close.bmp", 2277 * 2, 107 * 2, 9, 1);

	IMAGEMANAGER->addImage(shovelshop_shovel, "Resources/Images/Building/shovelshop/shovelshop_shovel.bmp", 20 * 2, 54 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(shovelshop_light, "Resources/Images/Building/shovelshop/shovelshop_light.bmp", 139 * 2, 82 * 2, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addImage(workbanch, "Resources/Images/Building/workbanch/workbanch.bmp", 125 * 2, 116 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(shopStalkers_off, "Resources/Images/Building/shopStalkers/shopStalkers_off.bmp", 153 * 2, 85 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(shopStalkers_off_2, "Resources/Images/Building/shopStalkers/shopStalkers_off_2.bmp", 247 * 2, 178 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(shopStalkers_stand, "Resources/Images/Building/shopStalkers/shopStalkers_stand.bmp", 1235 * 2, 178 * 2, 5, 1);
	IMAGEMANAGER->addFrameImage(shopStalkers_open, "Resources/Images/Building/shopStalkers_close/shopStalkers_open.bmp", 2223 * 2, 178 * 2, 9, 1);
	IMAGEMANAGER->addFrameImage(shopStalkers_close, "Resources/Images/Building/shopStalkers/shopStalkers_close.bmp", 2223 * 2, 178 * 2, 9, 1);

	IMAGEMANAGER->addImage(shopStalkers_weapon, "Resources/Images/Building/shopStalkers/shopStalkers_weapon.bmp", 12 * 2, 26 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addImage(engineerShop_off, "Resources/Images/Building/engineerShop/engineerShop_off.bmp", 170 * 2, 17 * 2, true, RGB(255, 0, 255));
	IMAGEMANAGER->addImage(engineerShop_off_2, "Resources/Images/Building/engineerShop/engineerShop_off_2.bmp", 262 * 2, 141 * 2, true, RGB(255, 0, 255));
	
	IMAGEMANAGER->addFrameImage(engineerShop_stand, "Resources/Images/Building/engineerShop/engineerShop_stand.bmp", 2277 * 2, 107 * 2, 9, 1);
	IMAGEMANAGER->addFrameImage(engineerShop_open, "Resources/Images/Building/engineerShop/engineerShop_open.bmp", 2277 * 2, 107 * 2, 9, 1);
	IMAGEMANAGER->addFrameImage(engineerShop_close, "Resources/Images/Building/engineerShop/engineerShop_close.bmp", 2277 * 2, 107 * 2, 9, 1);
	
	IMAGEMANAGER->addImage(engineerShop_wrench, "Resources/Images/Building/engineerShop/engineerShop_wrench.bmp", 12 * 2, 26 * 2, true, RGB(255, 0, 255));

	IMAGEMANAGER->addFrameImage(Object_Mushroom, "Resources/Images/Objects/mushroom1.bmp", 440 * 2.125, 41 * 2.125, 4, 1);
	IMAGEMANAGER->addImage(Item_shroom, "Resources/Images/Items/item_shroom.bmp", 22, 21, true, RGB(255, 0 ,255));

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

	IMAGEMANAGER->addFrameImage(MONSTER_FROG_IDLE, "Resources/Images/Monster/monster_frog_idle.bmp", 900 * 2, 160 * 2, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_WALK, "Resources/Images/Monster/monster_frog_walk.bmp", 1200 * 2, 160 * 2, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_ATTACK, "Resources/Images/Monster/monster_frog_attack.bmp", 1200 * 2, 160 * 2, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_DEATH, "Resources/Images/Monster/monster_frog_death.bmp", 1500 * 2, 160 * 2, 10, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_FROG_JUMP, "Resources/Images/Monster/monster_frog_jump.bmp", 1650 * 2, 160 * 2, 11, 2);

	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_IDLE, "Resources/Images/Monster/monster_cannon_idle.bmp", 600 * 2, 180 * 2, 6, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_WALK, "Resources/Images/Monster/monster_cannon_walk.bmp", 800 * 2, 180 * 2, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_ATTACK, "Resources/Images/Monster/monster_cannon_attack.bmp", 800 * 2, 180 * 2, 8, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_DEATH, "Resources/Images/Monster/monster_cannon_death.bmp", 900 * 2, 180 * 2, 9, 2);
	IMAGEMANAGER->addFrameImage(MONSTER_CANNON_PROJECTILE, "Resources/Images/Monster/monster_projectile.bmp", 150 * 2, 25 * 2, 6, 1);

	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT3, "Resources/Images/Monster/monster_effect3.bmp", 1540 * 2, 80 * 2, 11, 1, true, RGB(50, 150, 200));
	IMAGEMANAGER->addFrameImage(MONSTER_EFFECT4, "Resources/Images/Monster/monster_effect4.bmp", 360 * 2, 60 * 2, 6, 1);

	return S_OK;
}

void ImageClass::release(void)
{

}