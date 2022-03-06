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
	mFrameUpdateSec = 1.f / 5.f;
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
	bIsDirLock = false;

	switch (mMonType)
	{
	case eMonsterType::Normal:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_IDLE);
		mStatus.maxHp = mStatus.currentHp = 50.f;
		mStatus.moveSpeed = 80.f;
		mStatus.attackSpeed = 150.f;
		mStatus.power = 10;
		mAtkStartFrameX = 5;
		break;
	case eMonsterType::Suicide:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_IDLE);
		mStatus.maxHp = mStatus.currentHp = 25.f;
		mStatus.moveSpeed = 200.f;
		mStatus.attackSpeed = 300.f;
		mStatus.power = 20;
		mAtkStartFrameX = 0;
		break;
	case eMonsterType::Frog:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_IDLE);
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 50.f;
		mStatus.attackSpeed = 150.f;
		mStatus.power = 10;
		mAtkStartFrameX = 3;
		break;
	case eMonsterType::Cannon:
		mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_IDLE);
		mStatus.maxHp = mStatus.currentHp = 150.f;
		mStatus.moveSpeed = 50.f;
		mStatus.attackSpeed = 200.f;
		mStatus.power = 30;
		mAtkStartFrameX = 3;
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

	if (!bIsAttack) {
		if (bInAttackRange && mAttackCoolTime > TIMEMANAGER->getWorldTime()) {
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
	if (mMonPrevDir != mMonCurrDir && !bIsDirLock) {
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
		mElapsedSec = 0;
		mCurrentFrameX += 1;
		switch (mMonCurrState)
		{
		case eMonsterState::Idle:
		case eMonsterState::Walk:
			if (mCurrentFrameX > mImage->getMaxFrameX()) mCurrentFrameX = 0;
			break;
		case eMonsterState::Attack:
			if (mMonType == eMonsterType::Normal) {
				if (mCurrentFrameX > mImage->getMaxFrameX()) mCurrentFrameX = 0;
			}
			else if (mMonType == eMonsterType::Suicide) {
				if (mCurrentFrameX > mImage->getMaxFrameX()) mCurrentFrameX = 0;
			}
			else if (mMonType == eMonsterType::Frog) {
				if (mCurrentFrameX > mImage->getMaxFrameX()) mCurrentFrameX = 0;
			}
			else if (mMonType == eMonsterType::Cannon) {
				if (mCurrentFrameX > mImage->getMaxFrameX()) mCurrentFrameX = 0;
			}
			break;
		}
	}
}

void Monster::draw()
{
	//Rectangle(getMemDc(), mSearchRange.left - CAMERA->getX(), mSearchRange.top - CAMERA->getY(), mSearchRange.right - CAMERA->getX(), mSearchRange.bottom - CAMERA->getY());
	//Rectangle(getMemDc(), mAttackRange.left - CAMERA->getX(), mAttackRange.top - CAMERA->getY(), mAttackRange.right - CAMERA->getX(), mAttackRange.bottom - CAMERA->getY());
	//Rectangle(getMemDc(), mCollideRange.left - CAMERA->getX(), mCollideRange.top - CAMERA->getY(), mCollideRange.right - CAMERA->getX(), mCollideRange.bottom - CAMERA->getY());

	mImage->frameRender
	(
		getMemDc(),
		getX() - mImageX * 0.5f,
		getY() - mImageY,
		mCurrentFrameX, mCurrentFrameY
	);
	if (mAttack && mMonType == eMonsterType::Cannon) mAttack->render();
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
	else {
		bInAttackRange = false;
	}

	if (!bIsAttackStart && mAttackCoolTime < TIMEMANAGER->getWorldTime() && !mAttack && !bIsAttack) bIsAttackStart = true;
	if (bInAttackRange) {
		if (bIsAttackStart && mCurrentFrameX >= mAtkStartFrameX) {
			if (!bIsAttack) {
				bIsAttack = true;
				mCurrentFrameX = 0;
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
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 50, 50, 120, 50);
					break;
				case eMonsterType::Cannon:
					mAttack->init(mMonType, mMonCurrDir, getAbsX(), getAbsY(), 50, 50, -20, 70);
					break;
				}
			}
			mMonCurrState = eMonsterState::Attack;
			bIsAttackStart = false;
			bIsDirLock = true;
		}
	}
	if (bIsAttackEnd) {
		bIsAttack = false;
		bIsAttackEnd = false;
	}
}

void Monster::attack()
{
	RECT tmpRect;
	float prevX = getX();

	switch (mMonType)
	{
	case eMonsterType::Normal:
		if (mCurrentFrameX >= 5) {
			switch (mTarget.type)
			{
			case eTargetType::Player:
				if (mMonCurrDir == eDirection::Left) {
					if (getAbsRc().left > mPlayerAbsRc.right) {
						offsetX(-mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().left < mPlayerAbsRc.right) {
							setAbsX(mPlayerAbsRc.right + getHalfWidth());
							if (mAttack) {
								mAttack->setAbsX(mPlayerAbsRc.right);
								if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mPlayerAbsRc)) {
									mIPlayer->attackDamageToPlayer(mStatus.power);
								}
							}
						}
					}
				}
				else {
					if (getAbsRc().right < mPlayerAbsRc.left) {
						offsetX(mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().right > mPlayerAbsRc.left) {
							setAbsX(mPlayerAbsRc.left - getHalfWidth());
							if (mAttack) {
								mAttack->setAbsX(mPlayerAbsRc.left);
								if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mPlayerAbsRc)) {
									mIPlayer->attackDamageToPlayer(mStatus.power);
								}
							}
						}
					}
				}
				break;
			case eTargetType::NPC:
				if (mMonCurrDir == eDirection::Left) {
					for (int i = 0; i < mNpcAbsRc.size(); i++) {
						if (getAbsRc().left > mNpcAbsRc[i].right) {
							offsetX(-mStatus.attackSpeed * mDeltaTime);
							if (getAbsRc().left < mNpcAbsRc[i].right) {
								setAbsX(mNpcAbsRc[i].right + getHalfWidth());
								if (mAttack) {
									mAttack->setAbsX(mNpcAbsRc[i].right);
									if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mNpcAbsRc[i])) {
										mIPlayer->attackDamageToNpc(mStatus.power, i);
									}
								}
								break;
							}
						}
					}
				}
				else {
					for (int i = 0; i < mNpcAbsRc.size(); i++) {
						if (getAbsRc().right < mNpcAbsRc[i].left) {
							offsetX(mStatus.attackSpeed * mDeltaTime);
							if (getAbsRc().right > mNpcAbsRc[i].left) {
								setAbsX(mNpcAbsRc[i].left - getHalfWidth());
								if (mAttack) {
									mAttack->setAbsX(mNpcAbsRc[i].left);
									if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mNpcAbsRc[i])) {
										mIPlayer->attackDamageToNpc(mStatus.power, i);
									}
								}
								break;
							}
						}
					}
				}
				break;
			case eTargetType::Building:
				break;
			}			
			
			if (bIsAttack) {
				if (mCurrentFrameX >= mImage->getMaxFrameX()) {
					if (mAttack) {
						deleteAttack();
					}
					bIsAttack = false;
					bIsAttackEnd = true;
					bIsDirLock = false;
					mAttackCoolTime = TIMEMANAGER->getWorldTime() + 1.f;
				}
			}
		}
		break;
	case eMonsterType::Suicide:
		switch (mTarget.type)
		{
		case eTargetType::Player:
			if (mMonCurrDir == eDirection::Left) {
				if (getAbsRc().left > mPlayerAbsRc.right) {
					offsetX(-mStatus.attackSpeed * mDeltaTime);
					if (getAbsRc().left < mPlayerAbsRc.right) {
						mIPlayer->attackDamageToPlayer(mStatus.power);
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
						mIPlayer->attackDamageToPlayer(mStatus.power);
						setAbsX(mPlayerAbsRc.left - getWidth());
						mStatus.currentHp = 0;
						bIsSuicide = true;
						addEffect(eMonsterEffectType::Explosion);
					}
				}
			}
			break;
		case eTargetType::NPC:
			if (mMonCurrDir == eDirection::Left) {
				for (int i = 0; i < mNpcAbsRc.size(); i++) {
					if (getAbsRc().left > mNpcAbsRc[i].right) {
						offsetX(-mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().left < mNpcAbsRc[i].right) {
							mIPlayer->attackDamageToNpc(mStatus.power, i);
							setAbsX(mNpcAbsRc[i].right + getHalfWidth());
							mStatus.currentHp = 0;
							bIsSuicide = true;
							addEffect(eMonsterEffectType::Explosion);
							break;
						}
					}
				}
			}
			else {
				for (int i = 0; i < mNpcAbsRc.size(); i++) {
					if (getAbsRc().right < mNpcAbsRc[i].left) {
						offsetX(-mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().right > mNpcAbsRc[i].left) {
							mIPlayer->attackDamageToNpc(mStatus.power, i);
							setAbsX(mNpcAbsRc[i].left - getHalfWidth());
							mStatus.currentHp = 0;
							bIsSuicide = true;
							addEffect(eMonsterEffectType::Explosion);
							break;
						}
					}
				}
			}
			break;
		case eTargetType::Building:
			break;
		}
		break;
	case eMonsterType::Frog:
		if (mCurrentFrameX >= mAtkStartFrameX) {
			switch (mTarget.type)
			{
			case eTargetType::Player:
				if (mMonCurrDir == eDirection::Left) {
					if (getAbsRc().left > mPlayerAbsRc.right) {
						offsetX(-mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().left < mPlayerAbsRc.right) {
							setAbsX(mPlayerAbsRc.right + getHalfWidth());
							if (mAttack) {
								mAttack->setAbsX(mPlayerAbsRc.right);
								if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mPlayerAbsRc)) {
									mIPlayer->attackDamageToPlayer(mStatus.power);
								}
							}
						}
					}
				}
				else {
					if (getAbsRc().right < mPlayerAbsRc.left) {
						offsetX(mStatus.attackSpeed * mDeltaTime);
						if (getAbsRc().right > mPlayerAbsRc.left) {
							setAbsX(mPlayerAbsRc.left - getHalfWidth());
							if (mAttack) {
								mAttack->setAbsX(mPlayerAbsRc.left);
								if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mPlayerAbsRc)) {
									mIPlayer->attackDamageToPlayer(mStatus.power);
								}
							}
						}
					}
				}
				break;
			case eTargetType::NPC:
				if (mMonCurrDir == eDirection::Left) {
					for (int i = 0; i < mNpcAbsRc.size(); i++) {
						if (getAbsRc().left > mNpcAbsRc[i].right) {
							offsetX(-mStatus.attackSpeed * mDeltaTime);
							if (getAbsRc().left < mNpcAbsRc[i].right) {
								setAbsX(mNpcAbsRc[i].right + getHalfWidth());
								if (mAttack) {
									mAttack->setAbsX(mNpcAbsRc[i].right);
									if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mNpcAbsRc[i])) {
										mIPlayer->attackDamageToNpc(mStatus.power, i);
									}
								}
								break;
							}
						}
					}
				}
				else {
					for (int i = 0; i < mNpcAbsRc.size(); i++) {
						if (getAbsRc().right < mNpcAbsRc[i].left) {
							offsetX(mStatus.attackSpeed * mDeltaTime);
							if (getAbsRc().right > mNpcAbsRc[i].left) {
								setAbsX(mNpcAbsRc[i].left - getHalfWidth());
								if (mAttack) {
									mAttack->setAbsX(mNpcAbsRc[i].left);
									if (IntersectRect(&tmpRect, &mAttack->getAbsRc(), &mNpcAbsRc[i])) {
										mIPlayer->attackDamageToNpc(mStatus.power, i);
									}
								}
								break;
							}
						}
					}
				}
				break;
			case eTargetType::Building:
				break;
			}
			if (bIsAttack) {
				if (mCurrentFrameX >= mImage->getMaxFrameX()) {
					if (mAttack) {
						deleteAttack();
					}
					bIsAttack = false;
					bIsAttackEnd = true;
					bIsDirLock = false;
					mAttackCoolTime = TIMEMANAGER->getWorldTime() + 1.f;
				}
			}
		}
		break;
	case eMonsterType::Cannon:
		if (mAttack)
		{
			switch (mTarget.type)
			{
			case eTargetType::Player:
				if (IntersectRect(&tmpRect, &mPlayerAbsRc, &mAttack->getAbsRc())) {
					mIPlayer->attackDamageToPlayer(mStatus.power);
					addEffect(eMonsterEffectType::Explosion);
					deleteAttack();
				}
				break;
			case eTargetType::NPC:
				for (int i = 0; i < mNpcAbsRc.size(); i++) {
					if (IntersectRect(&tmpRect, &mNpcAbsRc[i], &mAttack->getAbsRc())) {
						mIPlayer->attackDamageToNpc(mStatus.power, i);
						addEffect(eMonsterEffectType::Explosion);
						deleteAttack();
						break;
					}
				}
				break;
			case eTargetType::Building:
				break;
			}
			if (mAttack) {
				if (mAttack->getAbsRc().bottom >= GROUND) {
					addEffect(eMonsterEffectType::Explosion);
					deleteAttack();
				}
			}
		}
		if (bIsAttack) {
			if (mCurrentFrameX >= mImage->getMaxFrameX()) {
				bIsAttack = false;
				bIsAttackEnd = true;
				bIsDirLock = false;
				mAttackCoolTime = TIMEMANAGER->getWorldTime() + 1.f;
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
		if (mMonCurrState == eMonsterState::Idle) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_IDLE);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Walk) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_WALK);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Attack) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_NORMAL_ATTACK);
			mFrameUpdateSec = 1.f / 5.f;
		}
		break;
	case eMonsterType::Suicide:
		if (mMonCurrState == eMonsterState::Idle) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_IDLE);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Walk) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_WALK);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Attack) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_SUICIDE_ATTACK);
			mFrameUpdateSec = 1.f / 5.f;
		}
		break;
	case eMonsterType::Frog:
		if (mMonCurrState == eMonsterState::Idle) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_IDLE);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Walk) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_WALK);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Attack) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_FROG_ATTACK);
			mFrameUpdateSec = 1.f / 5.f;
		}
		break;
	case eMonsterType::Cannon:
		if (mMonCurrState == eMonsterState::Idle) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_IDLE);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Walk) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_WALK);
			mFrameUpdateSec = 1.f / 10.f;
		}
		else if (mMonCurrState == eMonsterState::Attack) {
			mImage = IMAGEMANAGER->findImage(IMGCLASS->MONSTER_CANNON_ATTACK);
			mFrameUpdateSec = 1.f / 5.f;
		}
		break;
	}
}

void Monster::deleteAttack(void)
{
	if (mAttack) {
		mAttack->release();
		SAFE_DELETE(mAttack);
	}
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
		if (type == eMonsterEffectType::Death && !bIsSuicide) {
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
