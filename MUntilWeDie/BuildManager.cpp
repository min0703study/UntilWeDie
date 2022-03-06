#include "Stdafx.h"
#include "BuildManager.h"
#include "ShovelShop.h"
#include "EngineerShop.h"
#include "ShopStalkers.h"
#include "Generator.h"
#include "workbanch.h"

HRESULT BuildManager::init(float x, float y, float width, float height)
{
	mShovelShop = new ShovelShop;
	mShovelShop->init(MAP::POS::SHOVELBUIDLING_X, GROUND, 253 * 2, 107 * 2);

	mEngineerShop = new engineerShop;
	mEngineerShop->init(MAP::POS::RENCHBUILDING_X, GROUND, 170 * 2, 71 * 2);

	mShopStalkers = new ShopStalkers;
	mShopStalkers->init(MAP::POS::GUNBUILDING_X, GROUND, 153 * 2, 85 * 2);

	mGenerator = new Generator;
	mGenerator->init(MAP::POS::GENERATOR_X, GROUND, 802 * 2 / 4, 93 * 2);

	mWorkBanch = new workbanch;
	mWorkBanch->init(MAP::POS::RESETBUILDING_X, GROUND, 125 * 2, 116 * 2);

	return S_OK;
}

void BuildManager::release(void)
{
	mShovelShop->release();
	mEngineerShop->release();
	mShopStalkers->release();
	mGenerator->release();
	mWorkBanch->release();
}

void BuildManager::update(void)
{
	mShovelShop->update();
	mEngineerShop->update();
	mShopStalkers->update();
	mGenerator->update();
	mWorkBanch->update();
}

void BuildManager::render(void)
{
	mShovelShop->render();
	mEngineerShop->render();
	mShopStalkers->render();
	mGenerator->render();
	mWorkBanch->render();
}

RECT BuildManager::getBuildingRc()
{
	return RECT();
}

int BuildManager::isBuildingCollisionToPlayer(RECT playerAbsRc, OUT bool& isSuccessBuild)
{
	RECT tempRc;

	int returnType = eBuildType::tNothing;

	if (IntersectRect(&tempRc, &mShovelShop->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 삽 생산 시설");

		mShovelShop->getShovelCount();
		isSuccessBuild = mShovelShop->getIsBuild();
		returnType = eBuildType::tShovelShop;

		if (!isSuccessBuild) {
			mShovelShop->startBuild();
		}

		cout << "현재 삽 갯수" << " : " <<  endl;

	}

	if (IntersectRect(&tempRc, &mEngineerShop->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 렌치 생산 시설");
		returnType = eBuildType::tEngineerShop;

		mEngineerShop->getWrenchCount();
		isSuccessBuild = mEngineerShop->getIsBuild();
		returnType = eBuildType::tEngineerShop;

		if (!isSuccessBuild) {
			mEngineerShop->startBuild();
		}

		cout << "현재 렌치 갯수" << " : " << endl;
	}

	if (IntersectRect(&tempRc, &mShopStalkers->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 총 생산 시설");
		returnType = eBuildType::tShopStalkers;

		mShopStalkers->getWeaponCount();
		isSuccessBuild = mShopStalkers->getIsBuild();
		returnType = eBuildType::tShopStalkers;

		if (!isSuccessBuild) {
			mEngineerShop->startBuild();
		}

		cout << "현재 총 갯수" << " : " << endl;
	}

	if (IntersectRect(&tempRc, &mGenerator->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 초기화 시설");
		returnType = eBuildType::tGenerator;
	}

	if (IntersectRect(&tempRc, &mWorkBanch->getAbsRc(), &playerAbsRc)) {
		MY_UTIL::log(DEBUG_KHS, "충돌완료 : 발전기");
		returnType = eBuildType::tWorkbanch;
	}

	if (returnType == eBuildType::tNothing) {
		MY_UTIL::log(DEBUG_KHS, "충돌 실패 : 생산 시설");
	}

	return returnType;
}

void BuildManager::resetShopItem(int shopType)
{
	switch (shopType) {
	case eBuildType::tShovelShop:
		mShovelShop->getShovelCount();
		break;
	}
}
