#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TempBkImg = "임시 배경 화면";

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

	const char* NpcIdleR = "NPC 정지 오른쪽 액션";
	const char* NpcIdleL = "NPC 정지 왼쪽 액션";
	const char* NpcWalkR = "NPC 오른쪽으로 걷는 액션";
	const char* NpcWalkL = "NPC 왼쪽으로 걷는 액션";
	const char* NpcRunL = "NPC 왼쪽으로 뛰는 액션";
	const char* NpcRunR = "NPC 오른쪽으로 뛰는 액션";
	const char* NpcGrabL = "NPC 줍는 액션 왼쪽";
	const char* NpcGrabR = "NPC 줍는 액션 오른쪽";

	HRESULT init(void);
	virtual void release(void);
};

