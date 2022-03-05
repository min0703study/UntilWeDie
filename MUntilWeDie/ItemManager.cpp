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
			(*iDropItem)->mY > GROUND) {
			// ������ ��� ������ �߰�
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
	dropItem->Init("����", x, y - 50, MAP::SIZE::MUSHROOM_ITEM_W, MAP::SIZE::MUSHROOM_ITEM_H, img, direction);
	mDropItems.push_back(dropItem);
}

void ItemManager::collisionCheckForDropItem(RECT& playerAbsRc)
{

}