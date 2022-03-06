#include "Stdafx.h"
#include "ObjectManager.h"

HRESULT ObjectManager::init(float x, float y, float width, float height)
{
	mShroomCount = MAX_MUSHROOM;
	mDebrisCount = MAX_DEBRIS;

	mItemManager = new ItemManager;

	isMushRoomGrab = false;
	isDebrisGrab = false;

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

	mMushrooms[0]->setAbsX(MAP::POS::MUSHROOM_01_X);
	mMushrooms[1]->setAbsX(MAP::POS::MUSHROOM_02_X);
	mMushrooms[2]->setAbsX(MAP::POS::MUSHROOM_03_X);
	mMushrooms[3]->setAbsX(MAP::POS::MUSHROOM_04_X);
	mMushrooms[4]->setAbsX(MAP::POS::MUSHROOM_05_X);
	mMushrooms[5]->setAbsX(MAP::POS::MUSHROOM_06_X);


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
			cout << "오브젝트 충돌: " << "버섯" << endl;
			isMushRoomGrab = true;
			return index;
		}
	}

	for (mIterDebris = mDebris.begin(), index = 0; mIterDebris != mDebris.end(); ++mIterDebris, ++index) {
		if (IntersectRect(&temp, &(*mIterDebris)->getAbsRc(), &playerAbsRc)) {
			cout << "오브젝트 충돌: " << "잡동사니" << endl;
			isDebrisGrab = true;
			return index;
		}
	}

	return -1;
}

int ObjectManager::isItemManagerCollisionToPlayer(RECT playerAbsRc)
{
	int returnInt = mItemManager->collisionCheckForDropItem(playerAbsRc);
	return returnInt;
}

bool ObjectManager::startGrapObject(int objectIndex, int npcIndex, OUT float & xPos)
{
	if (isMushRoomGrab) {
		xPos = mMushrooms[objectIndex]->getAbsX();
		mMushrooms[objectIndex]->isStartMushroomGrap = true;
		isMushRoomGrab = false;
		return true;
	}
	else {
		xPos = mDebris[objectIndex]->getAbsX();
		mDebris[objectIndex]->isStartDebrisGrap = true;
		isDebrisGrab = false;
		return true;
	}
	return false;
}
