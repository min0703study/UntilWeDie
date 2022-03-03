#include "Stdafx.h"
#include "BuildManager.h"
#include "ShovelShop.h"

HRESULT BuildManager::init(float x, float y, float width, float height)
{
	mShovelShop = new ShovelShop;
	mShovelShop->init(15120 - 600, GROUND, 253 * 2, 107 * 2);




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
		cout << "충돌완료" << ":" << "삽 생산시설 초기상태" << endl;

		return 1;
	}

	else {
		cout << "충돌실패" << ":" << "삽 생산시설 초기상태" << endl;

		return -1;
	}

	return -1;
}
