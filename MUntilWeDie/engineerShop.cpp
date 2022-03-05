#include "Stdafx.h"
#include "engineerShop.h"

void engineerShop::init(float x, float y, float width, float height)
{
	GameObject::Init("engineerShop", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->engineerShop_off);

	mCreateCount = 0;

	isNpcIn = false;
	mBuildHp = 1;
}

void engineerShop::release(void)
{
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
	}
}

void engineerShop::draw()
{
	RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);
}

void engineerShop::animation()
{
	//Do thing
}

void engineerShop::move()
{
	//Do Nothing
}

//update 같은 동작
void engineerShop::action()
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
void engineerShop::giveWrenchCommand()
{
	if (0 < mCurWrenchCount) {
		mCurWrenchCount--;
	}

	else {
		//상호작용 불가능
	}
}

//삽을 생성하는 곳
void engineerShop::autoCreate()
{
	if (MAX_WRENCH_COUNT <= mCurWrenchCount) {
		mCreateCount = 100;
		mCurWrenchCount = 4;
	}

	else {
		mCurWrenchCount++;
		mCreateCount = 0;
	}
}

//유닛 상호작용
void engineerShop::intoNpc()
{
	if (isNpcIn == true) {
		giveWrenchCommand();
	}

	else {
		isNpcIn = true;
	}
}

void engineerShop::Monstertrue()
{
	//몬스터 충돌 영역 관리
}