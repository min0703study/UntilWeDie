#include "Stdafx.h"
#include "Projectile.h"
#include "Monster.h"

void Projectile::init(eMonsterType type, eDirection dir, float x, float y, float width, float height, float distance)
{
	if (dir == eDirection::Left) GameObject::Init("Attack", x - width * 0.5f - distance, y - height * 0.5f, width, height);
	else GameObject::Init("Attack", x - width * 0.5f + distance, y - height * 0.5f, width, height);

	mAtkStatus.type = type;
	mAtkStatus.dir = dir;

	switch (type)
	{
	case eMonsterType::Normal:
		mAtkStatus.speed = 1.f;
		mAtkStatus.angle = 0;
		mAtkStatus.power = 10;
		mImage = nullptr;
		break;
	case eMonsterType::Suicide:
		mAtkStatus.speed = 0;
		mAtkStatus.angle = 0;
		mAtkStatus.power = 0;
		mImage = nullptr;
		break;
	case eMonsterType::Frog:
		mAtkStatus.speed = 0;
		mAtkStatus.angle = 0;
		mAtkStatus.power = 0;
		mImage = nullptr;
		break;
	case eMonsterType::Cannon:
		mAtkStatus.speed = 0;
		mAtkStatus.angle = 0;
		mAtkStatus.power = 0;
		mImage = IMAGEMANAGER->findImage("Cannon");
		break;
	}
}

void Projectile::release(void)
{
}

void Projectile::update(void)
{
	move();
}

void Projectile::render(void)
{
	draw();
}

void Projectile::move(void)
{
	switch (mAtkStatus.type)
	{
	case eMonsterType::Normal:
		break;
	case eMonsterType::Suicide:
		break;
	case eMonsterType::Frog:
		break;
	case eMonsterType::Cannon:
		break;
	}
}

void Projectile::draw(void)
{
	Rectangle(getMemDc(), getX(), getY(), getX() + getWidth(), getY() + getHeight());
	if (mImage != nullptr) mImage->frameRender(getMemDc(), getX(), getY(), 0, 0);
}
