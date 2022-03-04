#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;
	virtual RECT getPlayerAbsRc() = 0;
	virtual vector<RECT> getNpcsRc() = 0;
	virtual vector<RECT> getNpcsAbsRc() = 0;
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;

	// �̰� �ϳ� �߰����� num�� �´� npc�� ������ �ִ°ɷ�
	//virtual void attackDamageToNpc(int damage, int num) = 0;
};

