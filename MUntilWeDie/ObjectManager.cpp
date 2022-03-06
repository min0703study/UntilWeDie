#include "Stdafx.h"
#include "ObjectManager.h"

HRESULT ObjectManager::init(float x, float y, float width, float height)
{
	mShroomCount = MAX_MUSHROOM;
	mDebrisCount = MAX_DEBRIS;

	mItemManager = new ItemManager;

	for (int i = 0; i < mShroomCount; i++) {
		Mushroom* mushroom = new Mushroom;
		mushroom->init((x +( i  * 2850)), y , width, height);
		mMushrooms.push_back(mushroom);
	}

	for (int i = 0; i < mDebrisCount; i++) {
		Debris* debris = new Debris;
		debris->init((x + (i * 1850 + RND->getFromIntTo(100, 2000))), y -30, width, height);
		mDebris.push_back(debris);
	}
	return S_OK;
}

void ObjectManager::update(void)
{
	mItemManager->update();
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end();) {
		(*mIterMushrooms)->update();
		if ((*mIterMushrooms)->isEndMushroomGrap) {
			mItemManager->createDropItem(IMAGEMANAGER->findImage(IMGCLASS->Item_Shroom),(*mIterMushrooms)->getAbsX(), (*mIterMushrooms)->getAbsY(), eDirection::Left);
			mIPlayer->isOverGrapObject(0);
			mIterMushrooms = mMushrooms.erase(mIterMushrooms);
		}
		else {
			++mIterMushrooms;
		}
	}

	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end();) {
		(*mIterDebris)->update();
		if ((*mIterDebris)->isEndDebrisGrap) {
			mItemManager->createDropItem(IMAGEMANAGER->findImage(IMGCLASS->Item_Gear), (*mIterDebris)->getAbsX(), (*mIterDebris)->getAbsY(), eDirection::Left);
			mIPlayer->isOverGrapObject(0);
			mIterDebris = mDebris.erase(mIterDebris);
		}
		else {
			++mIterDebris;
		}
	}
}

void ObjectManager::release(void)
{
	mItemManager->release();
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms) {
		(*mIterMushrooms)->release();
	}

	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end(); ++mIterDebris) {
		(*mIterDebris)->release();
	}
}

void ObjectManager::render(void)
{
	mItemManager->render();
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms) {
		(*mIterMushrooms)->render();
	}

	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end(); ++mIterDebris) {
		(*mIterDebris)->render();
	}
}

RECT ObjectManager::getObjectRc()
{
	return RECT();
}

int ObjectManager::isObjectCollisionToPlayer(RECT playerAbsRc)
{
	RECT temp;
	int index = -1;
	for (mIterMushrooms = mMushrooms.begin(), index = 0; mIterMushrooms != mMushrooms.end(); ++mIterMushrooms, ++index) {
		if (IntersectRect(&temp, &(*mIterMushrooms)->getAbsRc(), &playerAbsRc)) {
			cout << "������Ʈ �浹: " << "����" << endl;
			return index;
		}
	}

	for (mIterDebris = mDebris.begin(), index = 0; mIterDebris != mDebris.end(); ++mIterDebris, ++index) {
		if (IntersectRect(&temp, &(*mIterDebris)->getAbsRc(), &playerAbsRc)) {

			cout << "������Ʈ �浹: " << "�⵿���" << endl;
			return index;
		}
	}

	return -1;
}

bool ObjectManager::startGrapObject(int objectIndex, int npcIndex, OUT int & xPos)
{
	mMushrooms[objectIndex]->isStartMushroomGrap = true;
	if (mMushrooms[objectIndex]->isStartMushroomGrap == true) {
		return mDebris[objectIndex]->isStartDebrisGrap = false;
	}
	else {
	mDebris[objectIndex]->isStartDebrisGrap = false;
	return mMushrooms[objectIndex]->isStartMushroomGrap = false ;
	}
	return false;
}
