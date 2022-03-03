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
