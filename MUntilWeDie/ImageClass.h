#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TempBkImg = "임시 배경 화면";

	const char* PlayerIdle = "플레이어 정지 액션";

	const char* PlayerWalkR = "플레이어 오른쪽으로 걷는 액션";
	const char* PlayerWalkL = "플레이어 왼쪽으로 걷는 액션";

	const char* PlayerRunL = "플레이어 왼쪽으로 뛰는 액션";
	const char* PlayerRunR = "플레이어 오른쪽으로 뛰는 액션";

	const char* PlayerCommandCall = "플레이어 호출 명령";
	const char* PlayerCommandExec = "플레이어 실행 명령";

	HRESULT init(void);
	virtual void release(void);
};

