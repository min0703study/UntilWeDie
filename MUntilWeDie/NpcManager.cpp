#include "Stdafx.h"
#include "NpcManager.h"
#include "BuildManager.h"

HRESULT NpcManager::init(float* playerAbsX, float* playerAbsY, Player::eStat* playerStat, eDirection* playerDirection)
{
	mNpcCount = NPC_INIT_COUNT;

	for (int i = 0; i < NPC_INIT_COUNT; i++) {
		Npc* npc = new Npc;
		npc->init(playerAbsX, playerAbsY, playerDirection, playerStat, MAP::SIZE::NPC_X, MAP::SIZE::NPC_Y);
		mVNpcs.push_back(npc);
	}

	mCurFollowingNpcCount = 0;
	
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
	Npc* tempNpc = nullptr;

	auto firstNpc = mSFollowingNpc.find(1);
	if (firstNpc != mSFollowingNpc.end())
	{
		tempNpc = firstNpc->second;

		for (int i = 2; i <= mCurFollowingNpcCount; i++) {
			auto pull = mSFollowingNpc.find(i);

			if (pull != mSFollowingNpc.end())
			{
				if (pull->second->getType() != tempNpc->getType()) {
					//rank change
					firstNpc->second->setRank(i);
					pull->second->setRank(1);

					//순서 change
					tempNpc = pull->second;
					pull->second = firstNpc->second;
					firstNpc->second = tempNpc;
				}
			}
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


bool NpcManager::pullNpc() {
	if (mCurFollowingNpcCount < 2) return false;

	for (int i = 2; i < mCurFollowingNpcCount; i++) {
		auto head = mSFollowingNpc.find(i - 1);
		auto pull = mSFollowingNpc.find(i);

		//검색한 키를 찾았다면
		if (pull != mSFollowingNpc.end())
		{
			pull->second->setRank(i - 1);
			pull->second = head->second;
		}

		if (head == --mSFollowingNpc.end()) {
			mSFollowingNpc.erase(head);
			break;
		}
	}

	--mCurFollowingNpcCount;
	return true;
}


vector<RECT> NpcManager::getNpcsRc() {
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

vector<float> NpcManager::getNpcsAbsX()
{
	vector<float> returnVX;

	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		returnVX.push_back((*mViNpcs)->getAbsX());
	}
	return returnVX;
}


bool NpcManager::orderCallNpc(RECT playerCallableRc)
{
	RECT tempRc;
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		if ((*mViNpcs)->isActivated()) continue;
		if (IntersectRect(&tempRc, &(*mViNpcs)->getAbsRc(), &playerCallableRc)) {
			(*mViNpcs)->orderCall(mVFollowingNpc.size() + 1);
			mVFollowingNpc.push_back(*mViNpcs);
			mSFollowingNpc.insert(make_pair(++mCurFollowingNpcCount, *mViNpcs));
		};
	}
	return true;
}

bool NpcManager::orderRunDiffDirection()
{
	for (int i = 1; i <= mCurFollowingNpcCount; i++) {
		auto key = mSFollowingNpc.find(i);

		//검색한 키를 찾았다면
		if (key != mSFollowingNpc.end())
		{
			key->second->runDiffDirection();
		}
	}
	return true;
}

bool NpcManager::orderExecNpc(float xPos)
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;

	bool isCanExcuteOrder = (*mVFollowingNpc.begin())->orderGrap(xPos);
	pullRank((*mVFollowingNpc.begin())->getRank());

	if (!isCanExcuteOrder) {
		Npc* npc = *mVFollowingNpc.begin();
		mVFollowingNpc.push_back(npc);
		npc->setRank(mVFollowingNpc.size() - 1);
	}

	mVFollowingNpc.erase(mVFollowingNpc.begin());

	for (int i = 2; i < mCurFollowingNpcCount; i++) {
		auto key = mSFollowingNpc.find(i - 1);
		auto pull = mSFollowingNpc.find(i);

		//검색한 키를 찾았다면
		if (key != mSFollowingNpc.end() && pull != mSFollowingNpc.end())
		{
			pull->second->setRank(i);
			pull->second = key->second;
		}

		if (key == --mSFollowingNpc.end()) {
			mSFollowingNpc.erase(key);
		}
	}

	--mCurFollowingNpcCount;

	return true;
}

bool NpcManager::orderGetShovel() {

	if (mCurFollowingNpcCount < 1) return false;
	auto orderNpc = mSFollowingNpc.find(1);

	if (orderNpc != mSFollowingNpc.end())
	{
		if (orderNpc->second->getType() != Npc::eType::Digger) {
			orderNpc->second->orderGetShovel();
			return true;
		}
	}

	return false;
}

bool NpcManager::orderGetWrench()
{
	if (mCurFollowingNpcCount < 1) return false;
	auto orderNpc = mSFollowingNpc.find(1);

	if (orderNpc != mSFollowingNpc.end())
	{
		if (orderNpc->second->getType() != Npc::eType::Engineer) {
			orderNpc->second->orderGetWrench();
			return true;
		}
	}

	return false;
}

bool NpcManager::orderGetGun()
{
	if (mCurFollowingNpcCount < 1) return false;
	auto orderNpc = mSFollowingNpc.find(1);

	if (orderNpc != mSFollowingNpc.end())
	{
		if (orderNpc->second->getType() != Npc::eType::Engineer) {
			orderNpc->second->orderGetGun();
			return true;
		}
	}

	return false;
}

bool NpcManager::orderBuildBuilding()
{
	if (mCurFollowingNpcCount < 1) return false;
	auto orderNpc = mSFollowingNpc.find(1);

	if (orderNpc != mSFollowingNpc.end())
	{
		if (orderNpc->second->getType() != Npc::eType::Engineer) {
			orderNpc->second->orderBuild();
			pullNpc();
			return true;
		}
	}

	return false;
}
int NpcManager::orderResetType()
{
	auto firstNpc = mSFollowingNpc.find(1);

	if (firstNpc != mSFollowingNpc.end()) {
		switch (firstNpc->second->getType())
		{
			case Npc::eType::Digger:
				firstNpc->second->changeType(Npc::eType::Civilian);
				return BuildManager::eBuildType::tShovelShop;
		default:
			break;
		}
	}

	return -1;
}

