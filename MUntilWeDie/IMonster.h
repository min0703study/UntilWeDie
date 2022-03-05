#pragma once
class IMonster
{
public:
	virtual vector<RECT> getMonstersAbsRc() = 0;
	virtual void attackDamage(int damage, int arrNum) = 0;
};

