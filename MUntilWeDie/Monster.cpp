#include "Stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "IPlayer.h"

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

	mSearchRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), searchX, searchY);
	mAttackRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), attackX, attackY);
	mCollideRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), collX, collY);
	
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
		mStatus.power = 10;
		break;
	case eMonsterType::Suicide:
		mStatus.maxHp = mStatus.currentHp = 25.f;
		mStatus.moveSpeed = 4.f;
		mStatus.attackSpeed = 15.f;
		mStatus.power = 20;
		break;
	case eMonsterType::Frog:
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 1.f;
		mStatus.attackSpeed = 10.f;
		mStatus.power = 10;
		break;
	case eMonsterType::Cannon:
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 1.f;
		mStatus.attackSpeed = 5.f;
		mStatus.power = 30;
		break;
	}
}

void Monster::release(void)
{
	if (mAttack) {
		mAttack->release();
		SAFE_DELETE(mAttack);
	}
}

void Monster::update(void)
{
	mMonPrevState = mMonCurrState;
	mMonPrevDir = mMonCurrDir;
	move();
	search();
	action();
	if (mAttack) mAttack->update();
	if (bIsAttack) attack();

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
	if (bIsAttack && mAttack) mAttack->render();
}

void Monster::animation()
{
	if (mAnimationTime + 0.1f < TIMEMANAGER->getWorldTime()) {
		if(!mAttack) mCurrFrameX += 1;
		if (mCurrFrameX > mImage->getMaxFrameX()) {
			mCurrFrameX = 0;
		}
		mAnimationTime = TIMEMANAGER->getWorldTime();
	}
}

void Monster::draw()
{
	Rectangle(getMemDc(), mSearchRange.left - CAMERA->getX(), mSearchRange.top - CAMERA->getY(), mSearchRange.right - CAMERA->getX(), mSearchRange.bottom - CAMERA->getY());
	Rectangle(getMemDc(), mAttackRange.left - CAMERA->getX(), mAttackRange.top - CAMERA->getY(), mAttackRange.right - CAMERA->getX(), mAttackRange.bottom - CAMERA->getY());
	Rectangle(getMemDc(), mCollideRange.left - CAMERA->getX(), mCollideRange.top - CAMERA->getY(), mCollideRange.right - CAMERA->getX(), mCollideRange.bottom - CAMERA->getY());

	mImage->frameRender
	(
		getMemDc(),
		getX() - mImageX * 0.5f,
		getY() - mImageY,
		mCurrFrameX, mCurrFrameY
	);
	if (mAttack) mAttack->render();
}

void Monster::move()
{
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
				if (mIPlayer->getPlayerAbsRc().right < mCollideRange.left) {
					offsetX(-mStatus.moveSpeed);
					mMonCurrDir = eDirection::Left;
				}
				if (mIPlayer->getPlayerAbsRc().left > mCollideRange.right) {
					offsetX(mStatus.moveSpeed);
					mMonCurrDir = eDirection::Right;
				}
			}
		}
	}
	mSearchRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), mStatus.search.x, mStatus.search.y);
	mAttackRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), mStatus.attack.x, mStatus.attack.y);
	mCollideRange = RectMakeCenter(getAbsX(), getAbsY() - getHalfWidth(), mStatus.size.x, mStatus.size.y);
	//cout << "mFinalTarget.x: " << mFinalTarget.x << endl;
	//cout << "mIPlayer->getPlayerRc().left: " << mIPlayer->getPlayerAbsRc().left << endl;
	//cout << "monAbsRc.right: " << getAbsRc().right << endl;
	//cout << "monRc.right: " << getRc().right << endl;
	//cout << "mSearchRange.right: " << mSearchRange.right << endl;
	//cout << "mAttackRange.right: " << mAttackRange.right << endl;
}

void Monster::search()
{
	RECT tmpRect;
	if (IntersectRect(&tmpRect, &mSearchRange, &mIPlayer->getPlayerAbsRc())) {
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
		if (IntersectRect(&tmpRect, &mAttackRange, &mIPlayer->getPlayerAbsRc())) {
			if (!bIsAttack) {
				bIsAttack = true;
				mCurrFrameX = 0;
			}
			if (!mAttack) {
				mAttack = new Projectile;
				switch (mMonType)
				{
				case eMonsterType::Normal:
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 50, 50, 50, 50);
					break;
				case eMonsterType::Suicide:
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 20, 20, 20, 20);
					break;
				case eMonsterType::Frog:
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 50, 50, 50, 50);
					break;
				case eMonsterType::Cannon:
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 50, 50, -20, 70);
					break;
				}
			}
			mMonCurrState = eMonsterState::Attack;
			//attack();
		}
		else if (bIsAttackEnd){
			bIsAttack = false;
			bIsAttackEnd = false;
		}
	}
}

void Monster::attack()
{
	float prevX = getX();

	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mCurrFrameX > 4 && mCurrFrameX < 7) {
			if (mMonCurrDir == eDirection::Left) {
				if (getAbsRc().left > mIPlayer->getPlayerAbsRc().right) {
					offsetX(-mStatus.attackSpeed);
					if (getAbsRc().left < mIPlayer->getPlayerAbsRc().right) {
						setAbsX(mIPlayer->getPlayerAbsRc().right);
					}
					//mAccrueDistance += -10;
				}
			}
			else {
				if (getAbsRc().right < mIPlayer->getPlayerAbsRc().left) {
					offsetX(mStatus.attackSpeed);
					if (getAbsRc().right > mIPlayer->getPlayerAbsRc().left) {
						setAbsX(mIPlayer->getPlayerAbsRc().left - getWidth());
					}
				}
			}
		}
		//if (mCurrFrameX == 5) {
		//	/*if (mMonCurrDir == eDirection::Left) {
		//		RECT tmpRect;
		//		if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mIPlayer->getPlayerRc())) {
		//			cout << "attack L!" << endl;
		//		}
		//		mAttack->render();
		//	}
		//	else {
		//		RECT tmpRect;
		//		if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mIPlayer->getPlayerRc())) {
		//			cout << "attack R!" << endl;
		//		}
		//		if (getAbsRc().right > mIPlayer->getPlayerRc().left) {
		//			setX(mIPlayer->getPlayerRc().left);
		//			mCurrFrameX = 6;
		//		}
		//		mAttack->render();
		//	}*/

		//	RECT tmpRect;
		//	if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mIPlayer->getPlayerRc())) {
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
			if (getAbsRc().left > mIPlayer->getPlayerAbsRc().right) {
				offsetX(-mStatus.attackSpeed);
				if (getAbsRc().left < mIPlayer->getPlayerAbsRc().right) {
					mIPlayer->attackDamage(mStatus.power);
					setAbsX(mIPlayer->getPlayerAbsRc().right);
					mStatus.currentHp = 0;
					bIsSuicide = true;
				}
			}
		}
		else {
			if (getAbsRc().right < mIPlayer->getPlayerAbsRc().left) {
				offsetX(mStatus.attackSpeed);
				if (getAbsRc().right > mIPlayer->getPlayerAbsRc().left) {
					mIPlayer->attackDamage(mStatus.power);
					setAbsX(mIPlayer->getPlayerAbsRc().left - getWidth());
					mStatus.currentHp = 0;
					bIsSuicide = true;
				}
			}
		}
		break;
	case eMonsterType::Frog:
		break;
	case eMonsterType::Cannon:
		if (mAttack)
		{
			RECT tmpRect;
			if (IntersectRect(&tmpRect, &mIPlayer->getPlayerAbsRc(), &mAttack->getAbsRc())) {
				mIPlayer->attackDamage(mStatus.power);
				//addEffect();
				deleteAttack();
			}
			else if (mAttack->getAbsRc().bottom >= GROUND) {
				//addEffect();
				deleteAttack();
			}
		}
		if (mCurrFrameX == mImage->getMaxFrameX()) {
			bIsAttack = false;
			bIsAttackEnd = true;
		}
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
