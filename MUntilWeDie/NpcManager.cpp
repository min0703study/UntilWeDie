#include "Stdafx.h"
#include "NpcManager.h"

HRESULT NpcManager::init(float* playerAbsX, float* playerAbsY,Player::eStat* playerStat, eDirection* playerDirection)
{
	mNpcCount = NPC_INIT_COUNT;

	for (int i = 0; i < NPC_INIT_COUNT; i++) {
		Npc* npc = new Npc;
		npc->init(playerAbsX, playerAbsY, playerDirection, playerStat, PLAYER_X_SIZE, PLAYER_X_SIZE);
		mVNpcs.push_back(npc);
	}
	return S_OK;
}

void NpcManager::update(void)
{
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		(*mViNpcs)->update();
	}
}

void NpcManager::release(void)
{
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		(*mViNpcs)->release();
	}
}

void NpcManager::render(void)
{
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		(*mViNpcs)->render();
	}
}

bool NpcManager::orderCallNpc(RECT playerCallableRc)
{
	RECT tempRc;
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		if ((*mViNpcs)->isActivated()) continue;
		if (IntersectRect(&tempRc, &(*mViNpcs)->getAbsRc(), &playerCallableRc)) {
			(*mViNpcs)->orderCall(mVFollowingNpc.size() + 1);
			mVFollowingNpc.push_back(*mViNpcs);
		};
	}
	return true;
}

bool NpcManager::orderExecNpc()
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	bool isCanExcuteOrder = (*mVFollowingNpc.begin())->orderGrap();
	pullRank((*mVFollowingNpc.begin())->getRank());

	if (!isCanExcuteOrder) {
		Npc* npc = *mVFollowingNpc.begin();
		mVFollowingNpc.push_back(npc);
		npc->setRank(mVFollowingNpc.size() - 1);
	}

	mVFollowingNpc.erase(mVFollowingNpc.begin());
	return true;
}

bool NpcManager::changeStat(int npcIndex, Npc::eOrderType stat)
{
	if (mVNpcs.begin() + npcIndex != mVNpcs.end()) {
		Npc* npc = *(mVNpcs.begin() + npcIndex);
		switch (stat)
		{
		case Npc::eOrderType::Nothing:
			npc->nothing();
			break;
		default:
			break;
		}
	}

	return true;
}

bool NpcManager::changeNpcPosition()
{
	for (mViFollowingNpc = mVFollowingNpc.begin() + 1; mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc) {
		if ((*mVFollowingNpc.begin())->getType() != (*mViFollowingNpc)->getType()) {
			int tempRank = (*mViFollowingNpc)->getRank();
			(*mViFollowingNpc)->setRank((*mVFollowingNpc.begin())->getRank());
			(*mVFollowingNpc.begin())->setRank(tempRank);
		}
	}

	return true;
}

bool NpcManager::changeRank()
{
	int i = 1;
	for (mViFollowingNpc = mVFollowingNpc.begin(); mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc, i++) {
		(*mViFollowingNpc)->setRank(i);
	}
	return false;
}

bool NpcManager::pullRank(int rank)
{
	int i = 1;
	for (mViFollowingNpc = mVFollowingNpc.begin(); mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc, i++) {
		if ((*mViFollowingNpc)->getRank() > rank) {
			(*mViFollowingNpc)->setRank((*mViFollowingNpc)->getRank() - 1);
		}
	}
	return false;
}

bool NpcManager::orderGetShovel() {
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	(*mVFollowingNpc.begin())->orderGetShovel();
	pullRank((*mVFollowingNpc.begin())->getRank());
	mVFollowingNpc.erase(mVFollowingNpc.begin());
	return true;
}

bool NpcManager::orderGetWrench()
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	(*mVFollowingNpc.begin())->orderGetWrench();
	pullRank((*mVFollowingNpc.begin())->getRank());
	mVFollowingNpc.erase(mVFollowingNpc.begin());
	return true;
}

bool NpcManager::orderBuildBuilding()
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	(*mVFollowingNpc.begin())->orderBuild();
	pullRank((*mVFollowingNpc.begin())->getRank());
	mVFollowingNpc.erase(mVFollowingNpc.begin());
	return true;
}
vector<RECT> NpcManager::getNpcsRc()
{
	vector<RECT> returnVRc;
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		returnVRc.push_back((*mViNpcs)->getRc());
	}
	return returnVRc;
}

vector<RECT> NpcManager::getNpcsAbsRc()
{
	vector<RECT> returnVRc;
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		returnVRc.push_back((*mViNpcs)->getAbsRc());
	}
	return returnVRc;
}
