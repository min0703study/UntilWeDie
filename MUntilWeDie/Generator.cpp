#include "Stdafx.h"
#include "Generator.h"

void Generator::init(float x, float y, float width, float height)
{
	GameObject::Init("Generator", x, y, width, height);

	mImg = IMAGEMANAGER->findImage(IMGCLASS->Generator_01);

	mBuildHp = 10;
}

void Generator::release(void)
{
	//없음
}

void Generator::draw()
{
	mImg->render(getMemDc(), getRc().left, getRc().top);
	RectangleMake(getMemDc(), getRc());
}

void Generator::animation()
{
	//Do thing
}

void Generator::move()
{
	//Do Nothing
}

//update 같은 동작
void Generator::action()
{
	//없음
}

//유닛 상호작용
void Generator::intoNpc()
{

}

void Generator::Monstertrue()
{
	//몬스터 충돌 영역 관리
}