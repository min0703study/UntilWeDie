#include "Stdafx.h"
#include "Monster.h"

void Monster::init(const char* key, eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int finalX, int finalY)
{
	cout << "key: " << key << endl;
	mImage = IMAGEMANAGER->findImage(key);
	mMonType = type;
	mStatus.pos.x = posX;
	mStatus.pos.y = posY;
	mStatus.search.x = searchX;
	mStatus.search.y = searchY;
	mStatus.attack.x = attackX;
	mStatus.attack.y = attackY;
	mStatus.size.x = collX;
	mStatus.size.y = collY;

	mSearchRange = RectMakeCenter(posX, posY, searchX, searchY);
	mAttackRange = RectMakeCenter(posX, posY, attackX, attackY);
	mCollideRange = RectMakeCenter(posX, posY, collX, collY);
	
	mFinalTarget = PointMake(finalX, finalY);
	mbIsTargetOn = false;

	mAnimationTime = TIMEMANAGER->getWorldTime();
}

void Monster::release(void)
{
}

void Monster::draw()
{
	Rectangle(getMemDc(), mSearchRange.left, mSearchRange.top, mSearchRange.right, mSearchRange.bottom);
	Rectangle(getMemDc(), mAttackRange.left, mAttackRange.top, mAttackRange.right, mAttackRange.bottom);
	Rectangle(getMemDc(), mCollideRange.left, mCollideRange.top, mCollideRange.right, mCollideRange.bottom);
	mImage->frameRender(getMemDc(), mStatus.pos.x, mStatus.pos.y, mImage->getFrameX(), mImage->getFrameY());
}

void Monster::animation()
{
	//mAnimationTime += TIMEMANAGER->getElapsedTime();
	if (mAnimationTime + 1 < TIMEMANAGER->getWorldTime()) {
		mImage->offsetX(1, false);
		mAnimationTime = TIMEMANAGER->getWorldTime();
	}
}

void Monster::move()
{
	if (!mbIsTargetOn) {
		if (mFinalTarget.x <= mAttackRange.right) {
			mStatus.pos.x -= 0.3f;
		}
		else if (mFinalTarget.x >= mAttackRange.left) {
			mStatus.pos.x += 0.3f;
		}
	}
	// ¿¹ºñ
	else {
		if (mPlayerRect.right <= mAttackRange.left) {
			mStatus.pos.x -= 0.3f;
		}
		if (mPlayerRect.left >= mAttackRange.right) {
			mStatus.pos.x += 0.3f;
		}
	}
	mSearchRange = RectMakeCenter(mStatus.pos.x, mStatus.pos.y, mStatus.search.x, mStatus.search.y);
	mAttackRange = RectMakeCenter(mStatus.pos.x, mStatus.pos.y, mStatus.search.x, mStatus.search.y);
	mCollideRange = RectMakeCenter(mStatus.pos.x, mStatus.pos.y, mStatus.size.x, mStatus.size.y);
}

void Monster::search()
{
	RECT tmpRect;
	if (IntersectRect(&tmpRect, &mSearchRange, &mPlayerRect)) {
		mTargerType = eTargetType::Player;
		mbIsTargetOn = true;
	}
	else {
		mbIsTargetOn = false;
	}
}

void Monster::action()
{

}

Monster::Monster()
{
}

Monster::~Monster()
{
}
