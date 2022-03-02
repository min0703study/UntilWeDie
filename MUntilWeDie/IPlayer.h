#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//지혁
	// RECT getPlayerRc() -> 플레이어 충돌체
	// vector<RECT> getNpcRc() -> 모든 npc 충돌체
	// tagDamage addDamage() -> tagDamage{ enum(player/npc/monster/building) , int arrNum, int damage }
};

