#include "Stdafx.h"
#include "NpcManager.h"
#include "NPC.h"

HRESULT NpcManager::init(float* playerAbsX, float* playerAbsY, eDirection* playerDirection)
{
	
	mNpcCount = NPC_INIT_COUNT;

	for (int i = 0; i < mNpcCount; i++) {
		Npc* npc = new Npc;
		npc->init(playerAbsX, playerAbsY, playerDirection, PLAYER_X_SIZE, PLAYER_X_SIZE);
		mNpcs.push_back(npc);
	}
	return S_OK;
}

void NpcManager::update(void)
{
	for (mItNpcs = mNpcs.begin(); mItNpcs != mNpcs.end(); mItNpcs++) {
		(*mItNpcs)->update();
	}
}

void NpcManager::release(void)
{
	for (mItNpcs = mNpcs.begin(); mItNpcs != mNpcs.end(); mItNpcs++) {
		(*mItNpcs)->release();
	}
}

void NpcManager::render(void)
{
	for (mItNpcs = mNpcs.begin(); mItNpcs != mNpcs.end(); mItNpcs++) {
		(*mItNpcs)->render();
	}
}

bool NpcManager::orderCallNpc(RECT playerCallableRc)
{
	RECT tempRc;
	for (mItNpcs = mNpcs.begin(); mItNpcs != mNpcs.end(); mItNpcs++) {
		if (IntersectRect(&tempRc, &(*mItNpcs)->getAbsRc(), &playerCallableRc)) {
			(*mItNpcs)->orderCall(mActiveNpcs.size() + 1);
			mActiveNpcs.push_back(*mItNpcs);
		};
	}
	return true;
}

bool NpcManager::orderExecNpc()
{
	if (mActiveNpcs.begin() == mActiveNpcs.end()) return false;
	(*mActiveNpcs.begin())->orderGrap();
	mActiveNpcs.erase(mActiveNpcs.begin());
	return true;
}

bool NpcManager::orderFollowActiveNpc()
{
	for (mItActiveNpcs = mActiveNpcs.begin(); mItActiveNpcs != mActiveNpcs.end(); mItActiveNpcs++) {
		(*mItActiveNpcs)->orderFollow();
	}
	return true;
}

bool NpcManager::orderStopActiveNpc()
{
	for (mItActiveNpcs = mActiveNpcs.begin(); mItActiveNpcs != mActiveNpcs.end(); mItActiveNpcs++) {
		(*mItActiveNpcs)->orderStop();
	}
	return true;
}
