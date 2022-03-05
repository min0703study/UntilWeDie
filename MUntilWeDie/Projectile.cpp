#include "Stdafx.h"
#include "Projectile.h"
#include "Monster.h"

void Projectile::init(eMonsterType type, eDirection dir, float x, float y, float width, float height, float distanceX, float distanceY)
{
	//if (dir == eDirection::Left) GameObject::Init("Attack", x - width * 0.5f - distance, y - height * 0.5f, width, height);
	//else GameObject::Init("Attack", x - width * 0.5f + distance, y - height * 0.5f, width, height);

	if (dir == eDirection::Left) GameObject::Init("Attack", x - distanceX, y - distanceY, width, height);
	else GameObject::Init("Attack", x + distanceX, y - distanceY, width, height);

	mGravity = 2.0f;
	mSpeedX = mSpeedY = 0;

	mAtkStatus.type = type;
	mAtkStatus.dir = dir;

	switch (type)
	{
	case eMonsterType::Normal:
		mAtkStatus.speed = 0;
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
		mAtkStatus.speed = 200.f;
		mAtkStatus.angle = 30.f;
		mAtkStatus.power = 30;
		mImage = IMAGEMANAGER->findImage("MonsterCannonProjectile");
		if (dir == eDirection::Left) mAtkStatus.angle = 180.f - mAtkStatus.angle;
		mSpeedX = cosf(PI / 180.f * mAtkStatus.angle) * mAtkStatus.speed;
		mSpeedY = -sinf(PI / 180.f * mAtkStatus.angle) * mAtkStatus.speed;
		break;
	}
	
}

void Projectile::release(void)
{
}

void Projectile::update(void)
{
	mDeltaTime = TIMEMANAGER->getElapsedTime();
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
		offsetX(mSpeedX * mDeltaTime);
		offsetY(mSpeedY * mDeltaTime);
		mSpeedY += mGravity;
		break;
	}
}

void Projectile::draw(void)
{
	Rectangle(getMemDc(), getRc().left, getRc().top, getRc().right, getRc().bottom);
	if (mImage != nullptr) mImage->frameRender(getMemDc(), getX() - getHalfWidth(), getY() - getHeight(), 0, 0);
}
