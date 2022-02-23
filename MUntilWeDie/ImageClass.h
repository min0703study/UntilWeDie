#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TEMP_BK_IMG = "임시 배경 화면";

	const char* PLAYER_IDLE = "플레이어 정지 액션";
	const char* PLAYER_WALK_R = "플레이어 오른쪽으로 걷는 액션";
	const char* PLAYER_WALK_L = "플레이어 왼쪽으로 걷는 액션";

	const char * Object_Mushroom = "버섯 임시";

	HRESULT init(void);
	virtual void release(void);
};

