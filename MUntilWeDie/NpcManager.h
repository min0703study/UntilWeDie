#pragma once
#include "GameNode.h"

class Npc;

class NpcManager: public GameNode
{
public:
	HRESULT init(float * playerAbsX, float * playerAbsY, eDirection * playerDirection);

	void update(void);
	void release(void);
	void render(void);

	bool orderCallNpc(RECT playerCallableRc);
	bool orderExecNpc();
	bool orderFollowActiveNpc();
	bool orderStopActiveNpc();

	NpcManager() {};
	~NpcManager() {};
private:
	vector<Npc*> mNpcs;
	vector<Npc*>::iterator mItNpcs;
	
	vector<Npc*> mActiveNpcs;
	vector<Npc*>::iterator mItActiveNpcs;

	int mNpcCount;
};

