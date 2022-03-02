#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* BgImg = "배경 화면";
	const char* BgGrassImg = "배경 풀";

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

	const char* EngineerIdleR = "엔지니어 NPC 정지 오른쪽 액션";
	const char* EngineerIdleL = "엔지니어 NPC 정지 왼쪽 액션";
	const char* EngineerWalkR = "엔지니어 NPC 오른쪽으로 걷는 액션";
	const char* EngineerWalkL = "엔지니어 NPC 왼쪽으로 걷는 액션";
	const char* EngineerRunL = "엔지니어 NPC 왼쪽으로 뛰는 액션";
	const char* EngineerRunR = "엔지니어 NPC 오른쪽으로 뛰는 액션";

	const char* Generator_off = "발전기 최초 상태";
	const char* Generator_01 = "발전기 1단계";


	const char* shovelshop_off = "삽 생산시설 최초 상태";
	const char* shovelshop_off_02 = "삽 생산시설 유닛 투입 전 상태";

	const char* shovelshop_stand = "삽 생산시설 기본 상태";
	const char* shovelshop_open = "삽 생산시설 오픈";
	const char* shovelshop_close = "삽 생산시설 폐쇠";

	const char* shovelshop_light = "삽 생산시설 전등";
	const char* shovelshop_shovel = "삽";

	const char* Object_Mushroom = "버섯";
	const char* Item_shroom = "버섯조각";
	const char* MONSTER_NORMAL_IDLE = "MonsterNormalIdle";
	const char* MONSTER_NORMAL_WALK = "MonsterNormalWalk";
	const char* MONSTER_NORMAL_ATTACK = "MonsterNormalAttack";
	const char* MONSTER_NORMAL_DEATH = "MonsterNormalDeath";
	const char* MONSTER_NORMAL_FALL = "MonsterNormalFall";

	const char* MONSTER_SUICIDE_IDLE = "MonsterSuicideIdle";
	const char* MONSTER_SUICIDE_WALK = "MonsterSuicideWalk";
	const char* MONSTER_SUICIDE_ATTACK = "MonsterSuicideAttack";

	const char* MONSTER_FROG_IDLE = "MonsterFrogIdle";
	const char* MONSTER_FROG_WALK = "MonsterFrogWalk";
	const char* MONSTER_FROG_JUMP = "MonsterFrogJump";
	const char* MONSTER_FROG_ATTACK = "MonsterFrogAttack";
	const char* MONSTER_FROG_DEATH = "MonsterFrogDeath";

	const char* MONSTER_CANNON_IDLE = "MonsterCannonIdle";
	const char* MONSTER_CANNON_WALK = "MonsterCannonWalk";
	const char* MONSTER_CANNON_ATTACK = "MonsterCannonAttack";
	const char* MONSTER_CANNON_DEATH = "MonsterCannonDeath";

	const char* MONSTER_EFFECT1 = "MonsterEffect1";
	const char* MONSTER_EFFECT2 = "MonsterEffect2";
	const char* MONSTER_EFFECT3 = "MonsterEffect3";
	const char* MONSTER_EFFECT4 = "MonsterEffect4";
	
	HRESULT init(void);
	virtual void release(void);
};

