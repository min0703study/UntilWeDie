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

	const char* Object_Mushroom = "버섯";
	const char* Item_shroom = "버섯조각";

	HRESULT init(void);
	virtual void release(void);
};

