#include "Stdafx.h"
#include "ObjectManager.h"

HRESULT ObjectManager::init(float x, float y, float width, float height)
{
	mShroomCount = MAX_MUSHROOM;

	for (int i = 0; i < mShroomCount; i++) {
		Objects* objects = new Objects;
		objects->init((x +( i  * 2850)), y , width, height);
		mObjects.push_back(objects);
	}
	return S_OK;
}

void ObjectManager::update(void)
{
	for (mIterObjects = mObjects.begin(); mIterObjects != mObjects.end(); ++mIterObjects) {
		(*mIterObjects)->update();
	}
}

void ObjectManager::release(void)
{
	for (mIterObjects = mObjects.begin(); mIterObjects != mObjects.end(); ++mIterObjects) {
		(*mIterObjects)->release();
	}
}

void ObjectManager::render(void)
{
	for (mIterObjects = mObjects.begin(); mIterObjects != mObjects.end(); ++mIterObjects) {
		(*mIterObjects)->render();
	}
}

RECT ObjectManager::getObjectRc()
{
	return RECT();
}

int ObjectManager::isObjectCollisionToPlayer(RECT playerAbsRc)
{
	RECT temp;
	int index = 0;
	for (mIterObjects = mObjects.begin(); mIterObjects != mObjects.end(); ++mIterObjects, ++index) {
		if (IntersectRect(&temp, &(*mIterObjects)->getAbsRc(), &playerAbsRc)) {

			cout << "오브젝트 충돌: " << "버섯" << endl;
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
	for (mIterObjects = mObjects.begin(); mIterObjects != mObjects.end(); ++mIterObjects) {

	}
	return false;
}
