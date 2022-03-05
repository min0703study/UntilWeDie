#include "Stdafx.h"
#include "ShopStalkers.h"

void ShopStalkers::init(float x, float y, float width, float height)
{
	GameObject::Init("shopStalkers", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shopStalkers_off);

	mCreateCount = 0;

	isNpcIn = false;
	mBuildHp = 1;
}

void ShopStalkers::release(void)
{
	if (true)
	{
		//���ͷ� �ϳ��� ������ϴϱ�...
	}
}

void ShopStalkers::draw()
{
	RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);
}

void ShopStalkers::animation()
{
	//Do thing
}

void ShopStalkers::move()
{
	//Do Nothing
}

void ShopStalkers::action()
{
	if (isNpcIn) {
		mCreateCount++;

		if (mCreateCount = 100) {
			mCreateCount = 0;
			autoCreate();
		}
	}

	else {
		mCreateCount = 0;
	}
}

void ShopStalkers::giveWeaponCommand()
{
	if (0 < mCurWeaponCount) {
		mCurWeaponCount--;
	}

	else {
		//��ȣ�ۿ� �Ұ���
	}
}

void ShopStalkers::autoCreate()
{
	if (MAX_WEAPON_COUNT <= mCurWeaponCount) {
		mCreateCount = 100;
		mCurWeaponCount = 4;
	}

	else {
		mCurWeaponCount++;
		mCreateCount = 0;
	}
}

void ShopStalkers::intoNpc()
{
	if (isNpcIn == true) {
		giveWeaponCommand();
	}

	else {
		isNpcIn = true;
	}
}

void ShopStalkers::Monstertrue()
{
	//���� �浹 ���� ����
}