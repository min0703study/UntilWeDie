#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;
	//�ڿ� - �ڿ� ������ ������ ȣ������
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;
};

