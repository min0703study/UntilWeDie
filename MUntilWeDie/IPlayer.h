#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;
<<<<<<< HEAD

	//����
	// RECT getPlayerRc() -> �÷��̾� �浹ü
	// vector<RECT> getNpcRc() -> ��� npc �浹ü
	// tagDamage addDamage() -> tagDamage{ enum(player/npc/monster/building) , int arrNum, int damage }
=======
	//�ڿ� - �ڿ� ������ ������ ȣ������
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;
>>>>>>> master
};

