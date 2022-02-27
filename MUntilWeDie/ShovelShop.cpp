#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	GameObject::Init("ShovelShop", x, y, width, height);

	//초기화 할 것들
	mCreateCount = 0; //--> 0에서 시작해서 100되면 하나씩 생성
	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
	isNpcIn = false;
}

void ShovelShop::release(void)
{
	//생성 되어 있는 삽을 유닛 상호작용시 하나씩 지워준다.
	if (true)
	{
		//벡터로 하나씩 빼줘야하니까...
		mShovels; //...?
		IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);
		mImg->release();
	}
}

void ShovelShop::draw()
{
	mImg->render(getMemDc(), getX(), getY());
	//mCurShovelCount 개수를 그려준다. --->  원형으로 게이지가 채워지니까....
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
			mCreateCount = 0; //--> 다시 0부터
			autoCreate(); //----> 삽 생성
		}
	}
}

void ShovelShop::giveShovelCommand()
{
	//삽이 있냐 없냐니까...
	if (mShoveltrue) {
		//생성 되지 않았을 때 로직


	}
	else {
		//생성 되어 있어서 명령 수행이 가능할 때 로직
		mCurShovelCount--;
	}


	switch (mShoveltrue)
	{
	case true:
		//생성되어있음
		//유닛이 삽든 유닛으로 바뀌는 거 추가
		mCurShovelCount--;

	case false:
		//없음
		//여기에는 유닛 위에 물음표 텍스쳐가 출력되야함 
	}

}

//삽을 생성하는 곳
void ShovelShop::autoCreate()
{
	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		//만들지 않는다
		//수치가 100까지 올라가지만 생성은 x
		mCurShovelCount = 100;

	}
	else {
		//만드는 로직
		IMAGEMANAGER->findImage(IMGCLASS->shovelshop_shovel);
		mCurShovelCount = 0;
	}
}

void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		// 이미 들어와 있기 때문에 삽을 주는 로직을 처리
		giveShovelCommand();
	}
	else {
		isNpcIn = true;

		IMAGEMANAGER->findImage("shovelshop_open");
		IMAGEMANAGER->release();
		
		IMAGEMANAGER->findImage("shovelshop_stand");
	}
}

