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

	HRESULT init(void);
	virtual void release(void);
};

