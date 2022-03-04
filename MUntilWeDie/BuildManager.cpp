#include "Stdafx.h"
#include "BuildManager.h"
#include "ShovelShop.h"
#include "engineerShop.h"
#include "shopStalkers.h"
#include "Generator.h"
#include "workbanch.h"

HRESULT BuildManager::init(float x, float y, float width, float height)
{
	mShovelShop = new ShovelShop;
	mShovelShop->init(15120 + 100, GROUND, 253 * 2, 107 * 2);

	mEngineerShop = new engineerShop;
	mEngineerShop->init(15120 - 100, GROUND, 170 * 2, 17 * 2);

	mshopStalkers = new shopStalkers;
	mshopStalkers->init(15120 + 200, GROUND, 153 * 2, 85 * 2);

	mGenerator = new Generator;
	mGenerator->init(15120, GROUND, 802 * 2, 93 * 2);

	mWorkBanch = new workbanch;
	mWorkBanch->init(15120 - 70, GROUND, 125 * 2, 116 * 2);

	return S_OK;
}

void BuildManager::release(void)
{
	mShovelShop->release();
}

void BuildManager::update(void)
{
	mShovelShop->update();
}

void BuildManager::render(void)
{
	mShovelShop->render();
}

RECT BuildManager::getBuildingRc()
{
	return RECT();
}

int BuildManager::isBuildingCollisionToPlayer(RECT playerAbsRc)
{
	RECT tempRc;

	if (IntersectRect(&tempRc, &mShovelShop->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 삽 생산 시설");
		return 1;
	}

	else {
		MY_UTIL::log(DEBUG_KHS, "충돌 실패 : 삽 생산 시설");
		return -1;
	}

	return -1;
}
