#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TEMP_BK_IMG = "�ӽ� ��� ȭ��";

	const char* PLAYER_IDLE = "�÷��̾� ���� �׼�";
	const char* PLAYER_WALK_R = "�÷��̾� ���������� �ȴ� �׼�";
	const char* PLAYER_WALK_L = "�÷��̾� �������� �ȴ� �׼�";

	const char* MONSTER_NORMAL = "MonsterNormal";
	const char* MONSTER_SUICIDE = "MonsterSuicide";
	const char* MONSTER_FROG = "MonsterFrog";
	const char* MONSTER_CANNON = "MonsterCannon";

	HRESULT init(void);
	virtual void release(void);
};

