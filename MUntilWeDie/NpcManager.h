#pragma once
#include "GameNode.h"
#include "NPC.h"

class NpcManager: public GameNode
{
public:
	HRESULT init(float * playerAbsX, float * playerAbsY, Player::eStat* playerStat, eDirection * playerDirection);

	void update(void);
	void release(void);
	void render(void);

	bool orderCallNpc(RECT playerCallableRc);
	bool orderExecNpc();

	bool orderGetShovel(); //삽 집는 명령
	bool orderGetWrench(); //렌치 집는 명령

	NpcManager() {};
	~NpcManager() {};
private:
	vector<Npc*> mVNpcs;
	vector<Npc*>::iterator mViNpcs;
	
	vector<Npc*> mActiveNpcs;
	vector<Npc*>::iterator mItActiveNpcs;

	int mNpcCount;
};

