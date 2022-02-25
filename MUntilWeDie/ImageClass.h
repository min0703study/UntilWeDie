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


	const char* Generator_off = "발전기 최초 상태";
	const char* Generator_01 = "발전기 1단계";


	const char* shovelshop_off = "삽 생산시설 최초 상태";
	const char* shovelshop_off_02 = "삽 생산시설 유닛 투입 전 상태";

	const char* shovelshop_stand = "삽 생산시설 기본 상태";
	const char* shovelshop_open = "삽 생산시설 오픈";
	const char* shovelshop_close = "삽 생산시설 폐쇠";

	const char* shovelshop_light = "삽 생산시설 전등";
	const char* shovelshop_shovel = "삽";


	HRESULT init(void);
	virtual void release(void);
};

