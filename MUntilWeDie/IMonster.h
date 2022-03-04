#pragma once
class IMonster
{
public:
	virtual vector<RECT> getMonstersRc() = 0;
	virtual void attackDamage(int damage) = 0;
};

