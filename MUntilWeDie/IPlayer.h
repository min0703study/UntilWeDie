#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;
	virtual vector<RECT> getNpcsRc() = 0;
	virtual void isOverGrapObject(int npcIndex) = 0;
	virtual void attackDamage(int damage) = 0;
};

