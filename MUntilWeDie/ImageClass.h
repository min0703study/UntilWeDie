#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TEMP_BK_IMG = "�ӽ� ��� ȭ��";

	const char* PLAYER_IDLE = "�÷��̾� ���� �׼�";
	const char* PLAYER_WALK_R = "�÷��̾� ���������� �ȴ� �׼�";
	const char* PLAYER_WALK_L = "�÷��̾� �������� �ȴ� �׼�";

	const char* PLAYER_RUN_L = "�÷��̾� �������� �ٴ� �׼�";
	const char* PLAYER_RUN_R = "�÷��̾� ���������� �ٴ� �׼�";

	HRESULT init(void);
	virtual void release(void);
};

