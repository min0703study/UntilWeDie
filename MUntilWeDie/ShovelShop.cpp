#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	//초기 샵 위치, 크기 만들어주면되고
	GameObject::Init("ShovelShop", x, y, width, height);

	//초기화 할 것들
	mGeneratorCount = 100;
	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
	isNpcIn = false;
}

void ShovelShop::release(void)
{
	//생성 되어 있는 삽 지워준다.
}

void ShovelShop::draw()
{
	//img ShovlShop 깔아주고
	mImg->render(getMemDc(), getX(), getY());
	//mCurShovelCount 개수를 그려준다.
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
		mGeneratorCount--;
		if (mGeneratorCount = 0) {
			mGeneratorCount = 100;
			autoGenerator();
		}
	}
}

void ShovelShop::giveShovelCommand()
{
	if (mCurShovelCount <= 0) {
		//생성 되지 않았을 때 로직
	}
	else {
		//생성 되어 있어서 명령 수행이 가능할 때 로직
		mCurShovelCount--;
	}

}

void ShovelShop::autoGenerator()
{
	/*
		랜덤한 시간이 지나면
		삽을 하나씩 생성
	*/

	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		//만들지 않는다
	}
	else {
		//만드는 로직
	}
}

void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		// 이미 들어와 있기 때문에 삽을 주는 로직을 처리
	}
	else {
		isNpcIn = true;
	}
}

