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
			(*mViNpcs)->orderCall(mActiveNpcs.size() + 1);
			mActiveNpcs.push_back(*mViNpcs);
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

bool NpcManager::changeStat(int npcIndex, Npc::eOrderType stat)
{
	if (mVNpcs.begin() + npcIndex != mVNpcs.end()) {
		Npc* npc = *(mVNpcs.begin() + npcIndex);
		switch (stat)
		{
		case Npc::eOrderType::Noting:
			npc->nothing();
			break;
		default:
			break;
		}
	}

	return true;
}

bool NpcManager::orderGetShovel() {
	if (mActiveNpcs.begin() == mActiveNpcs.end()) return false;
	(*mActiveNpcs.begin())->orderGetShovel();
	mActiveNpcs.erase(mActiveNpcs.begin());
	return true;
}

bool NpcManager::orderGetWrench()
{
	if (mActiveNpcs.begin() == mActiveNpcs.end()) return false;
	(*mActiveNpcs.begin())->orderGetWrench();
	mActiveNpcs.erase(mActiveNpcs.begin());
	return true;
}
