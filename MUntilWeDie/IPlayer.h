#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//����
	// RECT getPlayerRc() -> �÷��̾� �浹ü
	// vector<RECT> getNpcRc() -> ��� npc �浹ü

	//�ڿ� - �ڿ� ������ ������ ȣ������
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;
};

