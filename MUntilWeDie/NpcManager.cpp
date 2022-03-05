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

	/*

	Npc* tempNpc = nullptr;
	Npc* tempNpc2 = nullptr;

	auto firstNpc = mSFollowingNpc.find(1);
	//검색한 키를 찾았다면
	if (firstNpc != mSFollowingNpc.end())
	{
		tempNpc = firstNpc->second;
	}

	int startIndex = 0;
	int endIndex = mCurFollowingNpcCount;


	for (int i = 2; i <= mCurFollowingNpcCount; i++) {
		auto pull = mSFollowingNpc.find(i);

		if (pull != mSFollowingNpc.end())
		{
			if (startIndex != 0) {
				if (pull->second->getType() != tempNpc2->getType()) {
					endIndex = i;
				}
			}
			else {
				if (pull->second->getType() != tempNpc->getType()) {
					tempNpc2 = pull->second;
					startIndex = i;
				}
			}
		}
	}
	map<int, Npc*> tempNpcMap;
	for (int i = 1; i < startIndex; i++) {
		tempNpcMap.insert(make_pair(endIndex + i - 1, mSFollowingNpc.find(i)->second));
	}

	for (int i = startIndex; i <= endIndex; i++) {
		tempNpcMap.insert(make_pair(i - startIndex + 1, mSFollowingNpc.find(i)->second));
	}

	for (int i = endIndex; i < mCurFollowingNpcCount; i++) {
		tempNpcMap.insert(make_pair(i, mSFollowingNpc.find(i)->second));
	}

	for (int i = 1; i <= mCurFollowingNpcCount; i++) {
		tempNpcMap.find(i)->second->setRank(i);
		mSFollowingNpc[i] = tempNpcMap.find(i)->second;
	}

	*/
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
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	for (mViFollowingNpc = mVFollowingNpc.begin(); mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc) {
		if ((*mViFollowingNpc)->getRank() == 1) {
			(*mViFollowingNpc)->orderGetShovel();
			break;
		}
	}
	return true;
}

bool NpcManager::orderGetWrench()
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	for (mViFollowingNpc = mVFollowingNpc.begin(); mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc) {
		if ((*mViFollowingNpc)->getRank() == 1) {
			(*mViFollowingNpc)->orderGetWrench();
			break;
		}
	}

	return true;
}

bool NpcManager::orderBuildBuilding()
{
	if (mVFollowingNpc.begin() == mVFollowingNpc.end()) return false;
	for (mViFollowingNpc = mVFollowingNpc.begin(); mViFollowingNpc != mVFollowingNpc.end(); ++mViFollowingNpc) {
		if ((*mViFollowingNpc)->getRank() == 1) {
			(*mViFollowingNpc)->orderBuild();
			pullRank(1);
			mVFollowingNpc.erase(mVFollowingNpc.begin());
			break;
		}
	}

	return true;
}

vector<float> NpcManager::getNpcsAbsX()
{
	vector<float> returnVX;
	for (mViNpcs = mVNpcs.begin(); mViNpcs != mVNpcs.end(); mViNpcs++) {
		returnVX.push_back((*mViNpcs)->getAbsX());
	}
	return returnVX;
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
