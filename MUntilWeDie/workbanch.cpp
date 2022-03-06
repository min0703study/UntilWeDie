#include "Stdafx.h"
#include "workbanch.h"

void workbanch::init(float x, float y, float width, float height)
{
	GameObject::Init("workbanch", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->workbanch);
}

void workbanch::release(void)
{
	//없음
}

void workbanch::draw()
{
	//RectangleMake(getMemDc(), getRc());
	mImg->render(getMemDc(), getRc().left, getRc().top);
}

void workbanch::animation()
{
	//Do thing
}

void workbanch::move()
{
	//Do Nothing
}

//update 같은 동작
void workbanch::action()
{
	//없음
}

//유닛 상호작용
void workbanch::intoNpc()
{

}