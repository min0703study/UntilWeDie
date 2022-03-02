#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* BgImg = "��� ȭ��";
	const char* BgGrassImg = "��� Ǯ";

	const char* PlayerIdleR = "�÷��̾� ���� ������ �׼�";
	const char* PlayerIdleL = "�÷��̾� ���� ���� �׼�";

	const char* PlayerWalkR = "�÷��̾� ���������� �ȴ� �׼�";
	const char* PlayerWalkL = "�÷��̾� �������� �ȴ� �׼�";

	const char* PlayerRunL = "�÷��̾� �������� �ٴ� �׼�";
	const char* PlayerRunR = "�÷��̾� ���������� �ٴ� �׼�";

	const char* PlayerCommandCallL = "�÷��̾� �������� ȣ�� ���";
	const char* PlayerCommandCallR = "�÷��̾� ���������� ȣ�� ���";
	const char* PlayerCommandExecL = "�÷��̾� �������� ���� ���";
	const char* PlayerCommandExecR = "�÷��̾� ���������� ���� ���";

	const char* Generator_off = "������ ���� ����";
	const char* Generator_01 = "������ 1�ܰ�";


	const char* shovelshop_off = "�� ����ü� ���� ����";
	const char* shovelshop_off_02 = "�� ����ü� ���� ���� �� ����";

	const char* shovelshop_stand = "�� ����ü� �⺻ ����";
	const char* shovelshop_open = "�� ����ü� ����";
	const char* shovelshop_close = "�� ����ü� ���";

	const char* shovelshop_light = "�� ����ü� ����";
	const char* shovelshop_shovel = "��";

	const char* Object_Mushroom = "����";
	const char* Item_shroom = "��������";
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

