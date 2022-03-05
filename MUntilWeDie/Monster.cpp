#include "Stdafx.h"
#include "Monster.h"
#include "Player.h"
#include "IPlayer.h"

void Monster::init(IPlayer* p, eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int imageX, int imageY, int finalX, int finalY)
{
	GameObject::Init("Monster", posX, posY, collX, collY);

	setIPlayer(p);
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
	mTarget = { eTargetType::Generator, -1 };
	mbIsTargetOn = false;

	mAccrueDistance = 0;//
	mAttackCoolTime = 0;
	mFrameUpdateSec = 1.0f / 10.f;
	mElapsedSec = 0;
	mDeltaTime = TIMEMANAGER->getElapsedTime();

	mCurrentFrameX = 0;
	(mMonCurrDir == eDirection::Left) ? mCurrentFrameY = 1 : mCurrentFrameY = 0;

	bIsStop = true;
	bIsMove = false;
	bIsGround = true;
	bIsSuicide = false;
	bInAttackRange = false;
	bIsAttackStart = false;
	bIsAttack = false;
	bIsAttackEnd = false;

	switch (mMonType)
	{
	case eMonsterType::Normal:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_IDLE);
		mStatus.maxHp = mStatus.currentHp = 50.f;
		mStatus.moveSpeed = 80.f;
		mStatus.attackSpeed = 150.f;
		mStatus.power = 10;
		break;
	case eMonsterType::Suicide:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_IDLE);
		mStatus.maxHp = mStatus.currentHp = 25.f;
		mStatus.moveSpeed = 200.f;
		mStatus.attackSpeed = 300.f;
		mStatus.power = 20;
		break;
	case eMonsterType::Frog:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_IDLE);
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 50.f;
		mStatus.attackSpeed = 150.f;
		mStatus.power = 10;
		break;
	case eMonsterType::Cannon:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_IDLE);
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 50.f;
		mStatus.attackSpeed = 200.f;
		mStatus.power = 30;
		break;
	}

	//mBuildingAbsRc = mIBuilding->getBuildingAbsRc();
	mNpcAbsRc = mIPlayer->getNpcsAbsRc();
	mNpcAbsX = mIPlayer->getNpcsAbsX();
	mPlayerAbsRc = mIPlayer->getPlayerAbsRc();
	mPlayerAbsX = mIPlayer->getPlayerAbsX();
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
	//mBuildingAbsRc = mIBuilding->getBuildingAbsRc();
	mNpcAbsRc = mIPlayer->getNpcsAbsRc();
	mNpcAbsX = mIPlayer->getNpcsAbsX();
	mPlayerAbsRc = mIPlayer->getPlayerAbsRc();
	mPlayerAbsX = mIPlayer->getPlayerAbsX();

	mMonPrevState = mMonCurrState;
	mMonPrevDir = mMonCurrDir;
	move();
	search();
	action();
	if (mAttack) mAttack->update();
	attack();

	if (bIsGround && !bIsAttack) {
		if (bInAttackRange && mAttackCoolTime + 1.3f > TIMEMANAGER->getWorldTime()) {
			mMonCurrState = eMonsterState::Idle;
			bIsMove = false;
			bIsStop = true;
		}
		else {
			mMonCurrState = eMonsterState::Walk;
			bIsMove = true;
			bIsStop = false;
		}
	}
	else {
		mMonCurrState = eMonsterState::Attack;
		bIsMove = false;
		bIsStop = true;
	}

	if (mMonPrevState != mMonCurrState) {
		changeAnimation();
		mCurrentFrameX = 0;
	}
	if (mMonPrevDir != mMonCurrDir) {
		(mMonCurrDir == eDirection::Left) ? mCurrentFrameY = 1 : mCurrentFrameY = 0;
	}

	animation();
}

void Monster::render(void)
{
	draw();
}

void Monster::animation()
{
	mElapsedSec += mDeltaTime;

	if (mElapsedSec >= mFrameUpdateSec) {
		if (mCurrentFrameX > mImage->getMaxFrameX()) {
			//if (bInAttackRange) mImage->getMaxFrameX();
			mCurrentFrameX = 0;
		}
		mElapsedSec = 0;
		mCurrentFrameX += 1;
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
		mCurrentFrameX, mCurrentFrameY
	);
	if (mAttack) mAttack->render();
}

void Monster::move()
{
	if (bIsMove) {
		if (mMonCurrState == eMonsterState::Walk) {
			if (!mbIsTargetOn) {
				if (mFinalTarget.x < mSearchRange.left) {
					offsetX(-mStatus.moveSpeed * mDeltaTime);
					mMonCurrDir = eDirection::Left;
				}
				else if (mFinalTarget.x > mSearchRange.right) {
					offsetX(mStatus.moveSpeed * mDeltaTime);
					mMonCurrDir = eDirection::Right;
				}
			}
			else {
				if (mTarget.type == eTargetType::Player) {
					if (mPlayerAbsRc.right < mCollideRange.left) {
						offsetX(-mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Left;
					}
					else if (mPlayerAbsRc.left > mCollideRange.right) {
						offsetX(mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Right;
					}
				}
				else if (mTarget.type == eTargetType::NPC) {
					if(mNpcAbsRc[mTarget.arrNum].right < mCollideRange.left) {
						offsetX(-mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Left;
					}
					else if (mNpcAbsRc[mTarget.arrNum].left > mCollideRange.right) {
						offsetX(mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Right;
					}
				}
				/*
				else if (mTarget.type == eTargetType::Building) {
					if (mNpcAbsRc[mTarget.arrNum].right < mCollideRange.left) {
						offsetX(-mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Left;
					}
					else if (mNpcAbsRc[mTarget.arrNum].left > mCollideRange.right) {
						offsetX(mStatus.moveSpeed * mDeltaTime);
						mMonCurrDir = eDirection::Right;
					}
				}
				*/
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
	if (searchTarget(eTargetType::Player)) {}
	else if (searchTarget(eTargetType::NPC)) {}
	else if (searchTarget(eTargetType::Building)) {}
	else {
		mTarget.type = eTargetType::Generator;
		mTarget.arrNum = -1;
		mbIsTargetOn = false;
	}
}

bool Monster::searchTarget(eTargetType type)
{
	RECT tmpRect;
	switch (type)
	{
	case eTargetType::Player:
		if (IntersectRect(&tmpRect, &mSearchRange, &mPlayerAbsRc)) {
			mTarget.type = eTargetType::Player;
			mTarget.arrNum = 0;
			mbIsTargetOn = true;
			if (getAbsX() < mPlayerAbsX) mMonCurrDir = eDirection::Right;
			else mMonCurrDir = eDirection::Left;
			return true;
		}
		return false;
	case eTargetType::NPC:
		for (int i = 0; i < mNpcAbsRc.size(); i++) {
			if (IntersectRect(&tmpRect, &mSearchRange, &mNpcAbsRc[i])) {
				mTarget.type = eTargetType::NPC;
				mTarget.arrNum = i;
				mbIsTargetOn = true;
				if (getAbsX() < mNpcAbsX[i]) mMonCurrDir = eDirection::Right;
				else mMonCurrDir = eDirection::Left;
				return true;
			}
		}
		return false;
	case eTargetType::Building:
		break;
	}
}

bool Monster::attackTarget(eTargetType type)
{
	RECT tmpRect;
	switch (type)
	{
	case eTargetType::Player:
		if (IntersectRect(&tmpRect, &mAttackRange, &mPlayerAbsRc)) {
			bInAttackRange = true;
			if (getAbsX() < mPlayerAbsX) mMonCurrDir = eDirection::Right;
			else mMonCurrDir = eDirection::Left;
			return true;
		}
		return false;
	case eTargetType::NPC:
		for (int i = 0; i < mNpcAbsRc.size(); i++) {
			if (IntersectRect(&tmpRect, &mAttackRange, &mNpcAbsRc[i])) {
				bInAttackRange = true;
				if (getAbsX() < mNpcAbsX[i]) mMonCurrDir = eDirection::Right;
				else mMonCurrDir = eDirection::Left;
				return true;
			}
		}
		return false;
	case eTargetType::Building:
		return false;
	}
}

void Monster::action()
{
	if (attackTarget(eTargetType::Player)) {}
	else if (attackTarget(eTargetType::NPC)) {}
	else if (attackTarget(eTargetType::Building)) {}
	else bInAttackRange = false;

	if (!bIsAttackStart && mAttackCoolTime + 1.3f < TIMEMANAGER->getWorldTime() && !mAttack && !bIsAttack) bIsAttackStart = true;
	if (bInAttackRange) {
		if (!bIsAttack) {
			bIsAttack = true;
			mCurrentFrameX = 0;
		}
		if (bIsAttackStart && mCurrentFrameX >= 3) {
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
			mAttackCoolTime = TIMEMANAGER->getWorldTime();
			bIsAttackStart = false;
		}
	}
	if (bIsAttackEnd) {
		bIsAttack = false;
		bIsAttackEnd = false;
	}
}

void Monster::attack()
{
	float prevX = getX();

	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mCurrentFrameX > 4 && mCurrentFrameX < 7) {
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
			if (getAbsRc().left > mPlayerAbsRc.right) {
				offsetX(-mStatus.attackSpeed * mDeltaTime);
				if (getAbsRc().left < mPlayerAbsRc.right) {
					mIPlayer->attackDamage(mStatus.power);
					setAbsX(mPlayerAbsRc.right);
					mStatus.currentHp = 0;
					bIsSuicide = true;
					addEffect(eMonsterEffectType::Explosion);
				}
			}
		}
		else {
			if (getAbsRc().right < mPlayerAbsRc.left) {
				offsetX(mStatus.attackSpeed * mDeltaTime);
				if (getAbsRc().right > mPlayerAbsRc.left) {
					mIPlayer->attackDamage(mStatus.power);
					setAbsX(mPlayerAbsRc.left - getWidth());
					mStatus.currentHp = 0;
					bIsSuicide = true;
					addEffect(eMonsterEffectType::Explosion);
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
			if (IntersectRect(&tmpRect, &mPlayerAbsRc, &mAttack->getAbsRc())) {
				mIPlayer->attackDamage(mStatus.power);
				addEffect(eMonsterEffectType::Explosion);
				deleteAttack();
			}
			else if (mAttack->getAbsRc().bottom >= GROUND) {
				addEffect(eMonsterEffectType::Explosion);
				deleteAttack();
			}
		}
		if (bIsAttack) {
			if (mCurrentFrameX > mImage->getMaxFrameX()) {
				bIsAttack = false;
				bIsAttackEnd = true;
			}
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
	cout << "delete!!" << endl;
}

void Monster::addEffect(eMonsterEffectType type)
{
	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mMonCurrDir == eDirection::Left) {
			EFFECTMANAGER->addEffect("MonsterNormalDeath", getAbsX(), getAbsY(), 1);
		}
		else {
			EFFECTMANAGER->addEffect("MonsterNormalDeath", getAbsX(), getAbsY(), 0);
		}
		break;
	case eMonsterType::Suicide:
		if (type == eMonsterEffectType::Death) {
			EFFECTMANAGER->addEffect("MonsterSuicideDeath1", getAbsX(), getAbsY(), 0);
		}
		else if(type == eMonsterEffectType::Explosion && bIsSuicide) {
			if (mMonCurrDir == eDirection::Left) {
				EFFECTMANAGER->addEffect("MonsterSuicideDeath2", getAbsX(), getAbsY(), 1);
			}
			else {
				EFFECTMANAGER->addEffect("MonsterSuicideDeath2", getAbsX(), getAbsY(), 0);
			}
		}
		break;
	case eMonsterType::Frog:
		if (mMonCurrDir == eDirection::Left) {
			EFFECTMANAGER->addEffect("MonsterFrogDeath", getAbsX(), getAbsY(), 1);
		}
		else {
			EFFECTMANAGER->addEffect("MonsterFrogDeath", getAbsX(), getAbsY(), 0);
		}
		break;
	case eMonsterType::Cannon:
		if (type == eMonsterEffectType::Explosion) {
			if (mAttack) {
				EFFECTMANAGER->addEffect("MonsterEffect4", mAttack->getAbsX(), mAttack->getAbsY(), 0);
			}
		}
		else {
			if (mMonCurrDir == eDirection::Left) {
				EFFECTMANAGER->addEffect("MonsterCannonDeath", getAbsX(), getAbsY(), 1);
			}
			else {
				EFFECTMANAGER->addEffect("MonsterCannonDeath", getAbsX(), getAbsY(), 0);
			}
		}
		break;
	}
}

void Monster::attackDamage(int damage)
{
	mStatus.currentHp -= damage;
	if (mStatus.currentHp < 0) mStatus.currentHp = 0;
}

Monster::Monster()
{
}

Monster::~Monster()
{
}
