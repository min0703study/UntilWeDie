#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* BgBackImg = "뒷 배경 화면";
	const char* BgImg = "배경 화면";
	const char* BgMiddleImg = "중간 배경 화면";
	const char* BgGrassImg = "배경 풀";
	const char* EndSecene = "사망";

	const char* PlayerIdleR = "플레이어 정지 오른쪽 액션";
	const char* PlayerIdleL = "플레이어 정지 왼쪽 액션";
	const char* PlayerWalkR = "플레이어 오른쪽으로 걷는 액션";
	const char* PlayerWalkL = "플레이어 왼쪽으로 걷는 액션";
	const char* PlayerRunL = "플레이어 왼쪽으로 뛰는 액션";
	const char* PlayerRunR = "플레이어 오른쪽으로 뛰는 액션";
	const char* PlayerCommandCallL = "플레이어 왼쪽으로 호출 명령";
	const char* PlayerCommandCallR = "플레이어 오른쪽으로 호출 명령";
	const char* PlayerCommandExecL = "플레이어 왼쪽으로 실행 명령";
	const char* PlayerCommandExecR = "플레이어 오른쪽으로 실행 명령";
	const char* PlayerShootL = "플레이어 왼쪽으로 공격";
	const char* PlayerShootR = "플레이어 오른쪽으로 공격";
	const char* PlayerRunShootL = "플레이어 뛰면서 왼쪽으로 공격";
	const char* PlayerRunShootR = "플레이어 뛰면서 오른쪽으로 공격";
	const char* PlayerDeathL = "플레이어 왼쪽으로 사망";
	const char* PlayerDeathR = "플레이어 오른쪽으로 사망";
	const char* PlayerUIMushRoom = "플레이어 버섯 수량";
	const char* PlayerUIGear = "플레이어 기어 수량";

	const char* CivilianIdleR = "민간인 정지 오른쪽 액션";
	const char* CivilianIdleL = "민간인 정지 왼쪽 액션";
	const char* CivilianWalkR = "민간인 오른쪽으로 걷는 액션";
	const char* CivilianWalkL = "민간인 왼쪽으로 걷는 액션";
	const char* CivilianRunL = "민간인 왼쪽으로 뛰는 액션";
	const char* CivilianRunR = "민간인 오른쪽으로 뛰는 액션";
	const char* CivilianGrabL = "민간인 줍는 액션 왼쪽";
	const char* CivilianGrabR = "민간인 줍는 액션 오른쪽";
	const char* CivilianBuildL = "민간인 건물 짓기 왼쪽";
	const char* CivilianBuildR = "민간인 건물 짓기 오른쪽";

	const char* DiggerIdleR = "삽 NPC 정지 오른쪽 액션";
	const char* DiggerIdleL = "삽 NPC 정지 왼쪽 액션";
	const char* DiggerWalkR = "삽 NPC 오른쪽으로 걷는 액션";
	const char* DiggerWalkL = "삽 NPC 왼쪽으로 걷는 액션";
	const char* DiggerRunL = "삽 NPC 왼쪽으로 뛰는 액션";
	const char* DiggerRunR = "삽 NPC 오른쪽으로 뛰는 액션";
	const char* DiggerGrabL = "삽 NPC 줍는 액션 왼쪽";
	const char* DiggerGrabR = "삽 NPC 줍는 액션 오른쪽";
	const char* DiggerBuildR = "삽 NPC 건물 짓기 액션 오른쪽";
	const char* DiggerBuildL = "삽 NPC 건물 짓기 액션 왼쪽";

	const char* EngineerIdleR = "엔지니어 NPC 정지 오른쪽 액션";
	const char* EngineerIdleL = "엔지니어 NPC 정지 왼쪽 액션";
	const char* EngineerWalkR = "엔지니어 NPC 오른쪽으로 걷는 액션";
	const char* EngineerWalkL = "엔지니어 NPC 왼쪽으로 걷는 액션";
	const char* EngineerRunL = "엔지니어 NPC 왼쪽으로 뛰는 액션";
	const char* EngineerRunR = "엔지니어 NPC 오른쪽으로 뛰는 액션";
	const char* EngineerBuildR = "엔지니어 NPC 오른쪽으로 건물 짓기 액션";
	const char* EngineerBuildL = "엔지니어 NPC 왼쪽으로 건물 짓기 액션";

	const char* FighterIdleR = "총잡이 NPC 정지 오른쪽 액션";
	const char* FighterIdleL = "총잡이 NPC 정지 왼쪽 액션";
	const char* FighterWalkR = "총잡이 NPC 오른쪽으로 걷는 액션";
	const char* FighterWalkL = "총잡이 NPC 왼쪽으로 걷는 액션";
	const char* FighterRunL = "총잡이 NPC 왼쪽으로 뛰는 액션";
	const char* FighterRunR = "총잡이 NPC 오른쪽으로 뛰는 액션";


	const char* Generator_off = "발전기 최초 상태";
	const char* Generator_01 = "발전기 1단계";

	const char* shovelshop_off = "삽 생산시설 최초 상태";
	const char* shovelshop_off_02 = "삽 생산시설 유닛 투입 전 상태";

	const char* shovelshop_stand = "삽 생산시설 기본 상태";
	const char* shovelshop_open = "삽 생산시설 오픈";
	const char* shovelshop_close = "삽 생산시설 폐쇠";

	const char* shovelshop_light = "삽 생산시설 전등";
	const char* shovelshop_shovel = "삽";

	const char* workbanch = "유닛 초기화 시설";

	const char* shopStalkers_off = "총 생산시설 최초 상태";
	const char* shopStalkers_off_2 = "총 생산시설 유닛 투입 전 상태";

	const char* shopStalkers_stand  = "총 생산시설 기본 상태";
	const char* shopStalkers_open = "총 생산시설 오픈";
	const char* shopStalkers_close = "총 생산시설 폐쇠";

	const char* shopStalkers_weapon = "총";

	const char* engineerShop_off = "렌치 생산시설 최초 상태";
	const char* engineerShop_off_2 = "렌치 생산시설 유닛 투입 전 상태";

	const char* engineerShop_stand = "렌치 생산시설 기본 상태";
	const char* engineerShop_open = "렌치 생산시설 오픈";
	const char* engineerShop_close = "렌치 생산시설 폐쇠";
				 
	const char* engineerShop_wrench = "렌치";

	const char* Object_Mushroom = "버섯";
	const char* Item_Shroom = "버섯조각";
	const char* Object_Debris = "상자";
	const char* Object_Debris2 = "상자2";
	const char* Item_Gear = "상자조각";
	const char* Item_Flask = "플라스크";

	const char* Object_Cocoon1 = "오브젝트1";
	const char* Object_Cocoon2 = "오브젝트2";
	const char* Object_Cocoon3 = "오브젝트3";
	const char* Object_Cocoon4 = "오브젝트4";
	const char* Object_Cocoon5 = "오브젝트5";
	const char* Object_Cocoon6 = "오브젝트6";
	const char* Object_CocoonHive = "오브젝트7";

	const char* WaterFallImg = "폭포";
	const char* WaterFallMImg = "중간폭포";
	const char* WaterFallSImg = "작은폭포";

	const char* MONSTER_NORMAL_IDLE = "MonsterNormalIdle";
	const char* MONSTER_NORMAL_WALK = "MonsterNormalWalk";
	const char* MONSTER_NORMAL_ATTACK = "MonsterNormalAttack";
	const char* MONSTER_NORMAL_DEATH = "MonsterNormalDeath";
	const char* MONSTER_NORMAL_FALL = "MonsterNormalFall";

	const char* MONSTER_SUICIDE_IDLE = "MonsterSuicideIdle";
	const char* MONSTER_SUICIDE_WALK = "MonsterSuicideWalk";
	const char* MONSTER_SUICIDE_ATTACK = "MonsterSuicideAttack";
	const char* MONSTER_SUICIDE_DEATH1 = "MonsterSuicideDeath1";
	const char* MONSTER_SUICIDE_DEATH2 = "MonsterSuicideDeath2";

	const char* MONSTER_FROG_IDLE = "MonsterFrogIdle";
	const char* MONSTER_FROG_WALK = "MonsterFrogWalk";
	const char* MONSTER_FROG_JUMP = "MonsterFrogJump";
	const char* MONSTER_FROG_ATTACK = "MonsterFrogAttack";
	const char* MONSTER_FROG_DEATH = "MonsterFrogDeath";

	const char* MONSTER_CANNON_IDLE = "MonsterCannonIdle";
	const char* MONSTER_CANNON_WALK = "MonsterCannonWalk";
	const char* MONSTER_CANNON_ATTACK = "MonsterCannonAttack";
	const char* MONSTER_CANNON_DEATH = "MonsterCannonDeath";
	const char* MONSTER_CANNON_PROJECTILE = "MonsterCannonProjectile";

	const char* MONSTER_EFFECT3 = "MonsterEffect3";
	const char* MONSTER_EFFECT4 = "MonsterEffect4";
	
	HRESULT init(void);
	virtual void release(void);
};

