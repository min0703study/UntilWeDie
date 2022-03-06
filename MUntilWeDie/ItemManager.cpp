#include "Stdafx.h"
#include "ItemManager.h"

HRESULT ItemManager::init()
{

	return S_OK;
}

void ItemManager::release()
{
}

void ItemManager::update()
{
	for (vector<DropItem*>::iterator iDropItem = mDropItems.begin(); iDropItem != mDropItems.end();) {
		if ((*iDropItem)->isDropToPlayer) {
			iDropItem = mDropItems.erase(iDropItem);
		}
		else {
			iDropItem++;
		}
	}
	for (vector<DropItem*>::iterator iDropItem = mDropItems.begin(); iDropItem != mDropItems.end(); iDropItem++) {
		if (!(*iDropItem)->isEndDrop &&
			(*iDropItem)->mY <= GROUND) {
			// 아이템 드롭 움직임 추가
			(*iDropItem)->mGravity += (*iDropItem)->_dropSpeed;
			(*iDropItem)->mY = 50 * (*iDropItem)->mGravity;
		}
		else {
			(*iDropItem)->isEndDrop = true;
		}
	}
}

void ItemManager::render()
{
	for (vector<DropItem*>::iterator iDropItem = mDropItems.begin(); iDropItem != mDropItems.end(); iDropItem++) 
	{
		(*iDropItem)->render();
	}
}

void ItemManager::createDropItem(ImageBase* img, float x, float y, eDirection direction)
{
	int i = 1;
	DropItem* dropItem = new DropItem();
	dropItem->Init("재료", x, y - 50, MAP::SIZE::MUSHROOM_ITEM_W, MAP::SIZE::MUSHROOM_ITEM_H, img, direction);
	mDropItems.push_back(dropItem);
}

void ItemManager::collisionCheckForDropItem(RECT& playerAbsRc)
{

}

void DropItem::animation()
{
	if (mTime + 0.5f < TIMEMANAGER->getWorldTime()) {
		mItemFrameX += 1;
		if (mItemFrameX > mImg->getMaxFrameX() - 1)
		{
			mItemFrameX = 0;
			mTime = TIMEMANAGER->getWorldTime();
		}
	}
}
