#include "Stdafx.h"
#include "ShovelShop.h"

void ShovelShop::init(float x, float y, float width, float height)
{
	//�ʱ� �� ��ġ, ũ�� ������ָ�ǰ�
	GameObject::Init("ShovelShop", x, y, width, height);

	//�ʱ�ȭ �� �͵�
	mGeneratorCount = 100;
	mImg = IMAGEMANAGER->findImage(IMGCLASS->shovelshop_off);
	isNpcIn = false;
}

void ShovelShop::release(void)
{
	//���� �Ǿ� �ִ� �� �����ش�.
}

void ShovelShop::draw()
{
	//img ShovlShop ����ְ�
	mImg->render(getMemDc(), getX(), getY());
	//mCurShovelCount ������ �׷��ش�.
}

void ShovelShop::animation()
{
	//Do thing
}

void ShovelShop::move()
{
	//Do Nothing
}

//update ���� ����
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
		//���� ���� �ʾ��� �� ����
	}
	else {
		//���� �Ǿ� �־ ��� ������ ������ �� ����
		mCurShovelCount--;
	}

}

void ShovelShop::autoGenerator()
{
	/*
		������ �ð��� ������
		���� �ϳ��� ����
	*/

	if (MAX_SHOVEL_COUNT <= mCurShovelCount) {
		//������ �ʴ´�
	}
	else {
		//����� ����
	}
}

void ShovelShop::intoNpc()
{
	if (isNpcIn == true) {
		// �̹� ���� �ֱ� ������ ���� �ִ� ������ ó��
	}
	else {
		isNpcIn = true;
	}
}

