#pragma once
class IMonster
{
public:
	virtual RECT getMonsterRc() = 0;
	virtual void attackDamage(int damage) = 0;
};

