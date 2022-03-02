#include "Stdafx.h"
#include "Monster.h"
#include "Player.h"

void Monster::init(eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int imageX, int imageY, int finalX, int finalY)
{
	GameObject::Init("Monster", posX, posY, collX, collY);

	if (posX < finalX) mMonPrevDir = mMonCurrDir = eDirection::Right;
	else if (posX > finalX) mMonPrevDir = mMonCurrDir = eDirection::Left;
	mMonType = type;
	mMonPrevState = mMonCurrState = eMonsterState::Idle;
	mStatus.search.x = searchX;
	mStatus.search.y = searchY;
	mStatus.attack.x = attackX;
	mStatus.attack.y = attackY;
	mStatus.size.x = collX;
	mStatus.size.y = collY;
	mImageX = imageX;
	mImageY = imageY;

	mSearchRange = RectMakeCenter(getCenterX(), getCenterY(), searchX, searchY);
	mAttackRange = RectMakeCenter(getCenterX(), getCenterY(), attackX, attackY);
	mCollideRange = RectMakeCenter(getCenterX(), getCenterY(), collX, collY);
	
	mFinalTarget = PointMake(finalX, finalY);
	mbIsTargetOn = false;

	mAccrueDistance = 0;
	mAnimationTime = TIMEMANAGER->getWorldTime();
	mAttackCoolTime = 0;
	mCurrFrameX = 0;
	(mMonCurrDir == eDirection::Left) ? mCurrFrameY = 1 : mCurrFrameY = 0;

	bIsStop = true;
	bIsMove = false;
	bIsAttack = false;
	bIsGround = true;
	bIsSuicide = false;
	bIsAttackEnd = false;

	switch (mMonType)
	{
	case eMonsterType::Normal:
		mStatus.maxHp = mStatus.currentHp = 50.f;
		mStatus.moveSpeed = 2.f;
		mStatus.attackSpeed = 10.f;
		break;
	case eMonsterType::Suicide:
		mStatus.maxHp = mStatus.currentHp = 25.f;
		mStatus.moveSpeed = 4.f;
		mStatus.attackSpeed = 15.f;
		break;
	case eMonsterType::Frog:
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 1.f;
		mStatus.attackSpeed = 10.f;
		break;
	case eMonsterType::Cannon:
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 1.f;
		mStatus.attackSpeed = 5.f;
		break;
	}
}

void Monster::release(void)
{
	mAttack->release();
	SAFE_DELETE(mAttack);
}

void Monster::update(void)
{
	mMonPrevState = mMonCurrState;
	mMonPrevDir = mMonCurrDir;
	move();
	search();
	action();

	//if (bIsAttack && !mAttack) mAttack->update();

	if (mMonPrevState != mMonCurrState) {
		changeAnimation();
		mCurrFrameX = 0;
	}
	if (mMonPrevDir != mMonCurrDir) {
		(mMonCurrDir == eDirection::Left) ? mCurrFrameY = 1 : mCurrFrameY = 0;
	}
}

void Monster::render(void)
{
	animation();
	draw();
	if (bIsAttack && mAttack != nullptr) mAttack->render();
}

void Monster::animation()
{
	if (mAnimationTime + 0.1f < TIMEMANAGER->getWorldTime()) {
		mCurrFrameX += 1;
		if (mCurrFrameX > mImage->getMaxFrameX()) {
			mCurrFrameX = 0;
		}
		cout << mCurrFrameX << endl;
		mAnimationTime = TIMEMANAGER->getWorldTime();
	}
}

void Monster::draw()
{
	//Rectangle(getMemDc(), mSearchRange.left, mSearchRange.top, mSearchRange.right, mSearchRange.bottom);
	//Rectangle(getMemDc(), mAttackRange.left, mAttackRange.top, mAttackRange.right, mAttackRange.bottom);
	Rectangle(getMemDc(), mCollideRange.left, mCollideRange.top, mCollideRange.right, mCollideRange.bottom);

	mImage->frameRender
	(
		getMemDc(),
		getCenterX() - mImageX * 0.5f,
		getCenterY() - mImageY * 0.5f,
		mCurrFrameX, mCurrFrameY
	);
}

void Monster::move()
{
	//cout << "p abs: " << mPlayer->getAbsX() << endl;
	//cout << "p rel: " << mPlayer->getX() << endl;
	//cout << "m :" << getAbsX() << endl;

	// isGround + !attack -> move
	if (bIsGround && !bIsAttack) {
		mMonCurrState = eMonsterState::Walk;
		bIsMove = true;
		bIsStop = false;
	}
	else {
		mMonCurrState = eMonsterState::Attack;
		bIsMove = false;
		bIsStop = true;
	}

	if (bIsMove) {
		if (mMonCurrState == eMonsterState::Walk) {
			if (!mbIsTargetOn) {
				if (mFinalTarget.x < mSearchRange.left) {
					offsetX(-mStatus.moveSpeed);
					mMonCurrDir = eDirection::Left;
				}
				else if (mFinalTarget.x > mSearchRange.right) {
					offsetX(mStatus.moveSpeed);
					mMonCurrDir = eDirection::Right;
				}
			}
			else {
				if (mPlayer->getRc().right < mCollideRange.left) {
					offsetX(-mStatus.moveSpeed);
					mMonCurrDir = eDirection::Left;
				}
				if (mPlayer->getRc().left > mCollideRange.right) {
					offsetX(mStatus.moveSpeed);
					mMonCurrDir = eDirection::Right;
				}
			}
		}
	}
	/*else if (mMonCurrState == eMonsterState::Attack) {
		switch (mMonType)
		{
		case eMonsterType::Normal:
			if (mCurrFrameX > 4 && mCurrFrameX < 7) {
				if (mMonCurrDir == eDirection::Left) {
					if (getRc().left > mPlayer->getRc().right) {
						offsetX(-10.0f);
						if (getRc().left < mPlayer->getRc().right) {
							setX(mPlayer->getRc().right);
						}
					}
				}
				else {
					if (getRc().right < mPlayer->getRc().left) {
						offsetX(10.0f);
						if (getRc().right > mPlayer->getRc().left) {
							setX(mPlayer->getRc().left - getWidth());
						}
					}
				}
			}
			break;
		case eMonsterType::Suicide:
			break;
		case eMonsterType::Frog:
			break;
		case eMonsterType::Cannon:
			break;
		}
	}*/
	mSearchRange = RectMakeCenter(getCenterX(), getCenterY(), mStatus.search.x, mStatus.search.y);
	mAttackRange = RectMakeCenter(getCenterX(), getCenterY(), mStatus.attack.x, mStatus.attack.y);
	mCollideRange = RectMakeCenter(getCenterX(), getCenterY(), mStatus.size.x, mStatus.size.y);
}

void Monster::search()
{
	RECT tmpRect;
	if (IntersectRect(&tmpRect, &mSearchRange, &mPlayer->getRc())) {
		mTargetType = eTargetType::Player;
		mbIsTargetOn = true;
	}
	else {
		mbIsTargetOn = false;
	}
}

void Monster::action()
{
	if (mAttackCoolTime + 2.f < TIMEMANAGER->getWorldTime()) {
		RECT tmpRect;
		if (IntersectRect(&tmpRect, &mAttackRange, &mPlayer->getRc())) {
			if (!bIsAttack) {
				bIsAttack = true;
				mCurrFrameX = 0;
			}
			if (!mAttack) {
				mAttack = new Projectile;
				mAttack->init(mMonType, mMonCurrDir, getCenterX(), getCenterY(), 50, 50, mImageX * 0.3f);
			}
			mMonCurrState = eMonsterState::Attack;
			//attack();
		}
		else if (bIsAttackEnd){
			bIsAttack = false;
			bIsAttackEnd = false;
		}
	}
	if(bIsAttack) attack();
}

void Monster::attack()
{
	float prevX = getCenterX();

	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mCurrFrameX > 4 && mCurrFrameX < 7) {
			if (mMonCurrDir == eDirection::Left) {
				if (getRc().left > mPlayer->getRc().right) {
					offsetX(-mStatus.attackSpeed);
					if (getRc().left < mPlayer->getRc().right) {
						setAbsX(mPlayer->getRc().right);
					}
					mAccrueDistance += -10;
				}
			}
			else {
				if (getRc().right < mPlayer->getRc().left) {
					offsetX(mStatus.attackSpeed);
					if (getRc().right > mPlayer->getRc().left) {
						setAbsX(mPlayer->getRc().left - getWidth());
					}
				}
			}
		}
		//if (mCurrFrameX == 5) {
		//	/*if (mMonCurrDir == eDirection::Left) {
		//		RECT tmpRect;
		//		if (IntersectRect(&tmpRect, &mAttack->getRc(), &mPlayer->getRc())) {
		//			cout << "attack L!" << endl;
		//		}
		//		mAttack->render();
		//	}
		//	else {
		//		RECT tmpRect;
		//		if (IntersectRect(&tmpRect, &mAttack->getRc(), &mPlayer->getRc())) {
		//			cout << "attack R!" << endl;
		//		}
		//		if (getRc().right > mPlayer->getRc().left) {
		//			setX(mPlayer->getRc().left);
		//			mCurrFrameX = 6;
		//		}
		//		mAttack->render();
		//	}*/

		//	RECT tmpRect;
		//	if (IntersectRect(&tmpRect, &mAttack->getRc(), &mPlayer->getRc())) {
		//		cout << "attack!" << endl;
		//	}
		//	if (mAttack) {
		//		mAttack->render();
		//		deleteAttack();
		//	}	
		//}
		mAttackCoolTime = TIMEMANAGER->getWorldTime();
		break;
	case eMonsterType::Suicide:
		if (mMonCurrDir == eDirection::Left) {
			if (getRc().left > mPlayer->getRc().right) {
				cout << "getRc().left: " << getRc().left << endl;
				cout << "Player->getRc().right: " << mPlayer->getRc().right << endl;
				offsetX(-mStatus.attackSpeed);
				if (getRc().left < mPlayer->getRc().right) {
					cout << "coll L" << endl;
					setX(mPlayer->getRc().right);
					mStatus.currentHp = 0;
					bIsSuicide = true;
				}
			}
		}
		else {
			if (getRc().right < mPlayer->getRc().left) {
				cout << "getRc().right: " << getRc().right << endl;
				cout << "Player->getRc().left: " << mPlayer->getRc().left << endl;
				offsetX(mStatus.attackSpeed);
				cout << "getRc().right2: " << getRc().right << endl;
				cout << "Player->getRc().left2: " << mPlayer->getRc().left << endl;
				if (getRc().right > mPlayer->getRc().left) {
					cout << "coll R" << endl;
					setX(mPlayer->getRc().left - getWidth());
					mStatus.currentHp = 0;
					bIsSuicide = true;
					cout << "getRc().right3: " << getRc().right << endl;
					cout << "Player->getRc().left3: " << mPlayer->getRc().left << endl;
				}
			}
		}
		break;
	case eMonsterType::Frog:
		break;
	case eMonsterType::Cannon:
		break;
	}
}

void Monster::changeAnimation(void)
{
	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mMonCurrState == eMonsterState::Idle) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_IDLE);
		else if (mMonCurrState == eMonsterState::Walk) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_WALK);
		else if (mMonCurrState == eMonsterState::Attack) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_ATTACK);
		else if (mMonCurrState == eMonsterState::Death) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_DEATH);
		else if (mMonCurrState == eMonsterState::Fall) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_FALL);
		break;
	case eMonsterType::Suicide:
		if (mMonCurrState == eMonsterState::Idle) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_IDLE);
		else if (mMonCurrState == eMonsterState::Walk) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_WALK);
		else if (mMonCurrState == eMonsterState::Attack) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_ATTACK);
		break;
	case eMonsterType::Frog:
		if (mMonCurrState == eMonsterState::Idle) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_IDLE);
		else if (mMonCurrState == eMonsterState::Walk) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_WALK);
		else if (mMonCurrState == eMonsterState::Attack) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_ATTACK);
		else if (mMonCurrState == eMonsterState::Death) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_DEATH);
		else if (mMonCurrState == eMonsterState::Fall) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_JUMP);
		break;
	case eMonsterType::Cannon:
		if (mMonCurrState == eMonsterState::Idle) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_IDLE);
		else if (mMonCurrState == eMonsterState::Walk) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_WALK);
		else if (mMonCurrState == eMonsterState::Attack) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_ATTACK);
		else if (mMonCurrState == eMonsterState::Death) mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_DEATH);
		break;
	}
}

void Monster::deleteAttack(void)
{
	mAttack->release();
	SAFE_DELETE(mAttack);
}

void Monster::addEffect(void)
{
	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mMonCurrDir == eDirection::Left) {

		}
		else {

		}
		break;
	case eMonsterType::Suicide:
		if (bIsSuicide) {

		}
		else {

		}
		break;
	case eMonsterType::Frog:
		if (mMonCurrDir == eDirection::Left) {

		}
		else {

		}
		break;
	case eMonsterType::Cannon:
		if (mMonCurrDir == eDirection::Left) {

		}
		else {

		}
		break;
	}
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
