#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);

	mCreateCount = 0;

	isNpcIn = false;
	mBuildHp = 1;
}

void ShovelShop::release(void)
{
	//생성 되어 있는 삽을 유닛 상호작용시 하나씩 지워준다.
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
	}
}

void ShovelShop::draw()
{
	RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);
}

void ShovelShop::animation()
{
	//Do thing
}

void ShovelShop::move()
{
	//Do Nothing
}

//update 같은 동작
void ShovelShop::action()
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

//삽을 주는거
void ShovelShop::giveShovelCommand()
{
	if (0 < mCurShovelCount) {
		mCurShovelCount--;
	}

	else {
		//상호작용 불가능
	}
}

//삽을 생성하는 곳
void ShovelShop::autoCreate()
{
	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		mCreateCount = 100;
		mCurShovelCount = 4;
	}

	else {
		mCurShovelCount++;
		mCreateCount = 0;
	}
}

//유닛 상호작용
void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		giveShovelCommand();
	}

	else {
		isNpcIn = true;
	}
}

void ShovelShop::Monstertrue()
{
	//몬스터 충돌 영역 관리
}