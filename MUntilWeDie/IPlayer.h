#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//자원 - 자원 수집이 끝나면 호출해줘
	virtual void isOverGrapObject(int npcIndex) = 0;
};

