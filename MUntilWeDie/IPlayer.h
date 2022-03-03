#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//지혁
	// RECT getPlayerRc() -> 플레이어 충돌체
	// vector<RECT> getNpcRc() -> 모든 npc 충돌체

	//자원 - 자원 수집이 끝나면 호출해줘
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;
};

