#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//����
	// RECT getPlayerRc() -> �÷��̾� �浹ü
	// vector<RECT> getNpcRc() -> ��� npc �浹ü
	// tagDamage addDamage() -> tagDamage{ enum(player/npc/monster/building) , int arrNum, int damage }
};

