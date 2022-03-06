#pragma once
class IPlayer
{
public:
	virtual float getPlayerAbsX() = 0;
	virtual RECT getPlayerRc() = 0;
	virtual RECT getPlayerAbsRc() = 0;
	virtual vector<float> getNpcsAbsX() = 0;
	virtual vector<RECT> getNpcsRc() = 0;
	virtual vector<RECT> getNpcsAbsRc() = 0;
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamageToPlayer(int damage) = 0;
	virtual void attackDamageToNpc(int damage, int arrNum) = 0;

	// 이거 하나 추가해줘 num에 맞는 npc에 데미지 주는걸로
	//virtual void attackDamageToNpc(int damage, int num) = 0;
};

