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

	bool pullNpc();

	bool orderCallNpc(RECT playerCallableRc);
	bool orderRunDiffDirection();
	bool orderExecNpc(float xPos);

	bool changeStat(int npcIndex, Npc::eOrderType stat);
	bool changeNpcPosition();
	
	bool orderGetShovel(); //삽 집는 명령
	bool orderGetWrench(); // 렌치 집는 명령
	bool orderGetGun();
	bool orderBuildBuilding();
	int orderResetType();

	vector<float> getNpcsAbsX();
	vector<RECT> getNpcsRc();
	vector<RECT> getNpcsAbsRc();

	NpcManager() {};
	~NpcManager() {};
private:
	vector<Npc*> mVNpcs;
	vector<Npc*>::iterator mViNpcs;

	map<int, Npc*> mSFollowingNpc;
	map<int, Npc*>::iterator mSiFollowingNpc;

	int mCurFollowingNpcCount;


	int mNpcCount;
};

