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
	//����
}

void Generator::draw()
{
	RectangleMake(getMemDc(), getRc());
	mImg->frameRender(getMemDc(), getRc().left, getRc().top);
}

void Generator::animation()
{
	//Do thing
}

void Generator::move()
{
	//Do Nothing
}

//update ���� ����
void Generator::action()
{
	//����
}

//���� ��ȣ�ۿ�
void Generator::intoNpc()
{

}

void Generator::Monstertrue()
{
	//���� �浹 ���� ����
}