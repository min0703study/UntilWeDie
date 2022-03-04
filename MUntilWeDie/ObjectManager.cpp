#include "Stdafx.h"
#include "ObjectManager.h"

HRESULT ObjectManager::init(float x, float y, float width, float height)
{
	mShroomCount = MAX_MUSHROOM;
	mDebrisCount = MAX_DEBRIS;

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
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms) {
		(*mIterMushrooms)->update();
	}
	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end(); ++mIterDebris) {
		(*mIterDebris)->update();
	}

}

void ObjectManager::release(void)
{
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms) {
		(*mIterMushrooms)->release();
	}

	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end(); ++mIterDebris) {
		(*mIterDebris)->release();
	}
}

void ObjectManager::render(void)
{
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
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms, ++index) {
		if (IntersectRect(&temp, &(*mIterMushrooms)->getAbsRc(), &playerAbsRc)) {

			cout << "오브젝트 충돌: " << "버섯" << endl;
			return index;
		}
		else {
			cout << "충돌 안함 " << endl;
			return -1;
		}
	}

	for (mIterDebris = mDebris.begin(); mIterDebris != mDebris.end(); ++mIterDebris, ++index) {
		if (IntersectRect(&temp, &(*mIterDebris)->getAbsRc(), &playerAbsRc)) {

			cout << "오브젝트 충돌: " << "잡동사니" << endl;
			return index;
		}
		else {
			cout << "충돌 안함 " << endl;
			return -1;
		}
	}
}

bool ObjectManager::startGrapObject(int objectIndex, int npcIndex, OUT int & xPos)
{
	for (mIterMushrooms = mMushrooms.begin(); mIterMushrooms != mMushrooms.end(); ++mIterMushrooms, ++objectIndex) {

	}
	return false;
}
