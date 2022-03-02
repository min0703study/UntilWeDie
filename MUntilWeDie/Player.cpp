#include "Stdafx.h"
#include "Player.h"
#include "NpcManager.h"
#include "Weapon.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);
	
	mAni.mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleR), IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleL), 3);
	mAni.mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 3);
	mAni.mappingStatForImg(eStat::Dash, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 3);
	mAni.mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR), IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL), 3);
	mAni.mappingStatForImg(eStat::CommandCall, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallL), 3);
	mAni.mappingStatForImg(eStat::CommandExec, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecL), 3);
	mAni.mappingStatForImg(eStat::Shoot, IMAGEMANAGER->findImage(IMGCLASS->PlayerShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerShootL), 3);
	mAni.mappingStatForImg(eStat::ShootRun, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL), 3);

	mWeapon = new Weapon;
	mWeapon->init("");

	mNpcManager = new NpcManager;
	mNpcManager->init(getAbsX(), getAbsY(), &mCurStat, &mCurDirection);

	mCurStat = eStat::Idle;
	mCurDirection = eDirection::Right;

	mIsClickDownDashKey = false;

	mAni.ChangeCurImage(mCurStat, mCurDirection);

	mDashTime = PLAYER_DASH_MAX_DASH_TIME;
}

void Player::release(void)
{
	mWeapon->release();
	mNpcManager->release();
	SAFE_DELETE(mNpcManager);
}

void Player::update(void)
{
	move();
	action();
	mNpcManager->update();
	mWeapon->update();
}
void Player::render(void)
{
	draw();
	animation();
	mNpcManager->render();
	mWeapon->render();
};

void Player::draw()
{
	if (mIsClickDownDashKey) {
		GDIPLUSMANAGER->drawCProgressBar(getMemDc(), getX(), getY(), 5, mDashTime, PLAYER_DASH_MAX_DASH_TIME);
	}

	mAni.GetImage()->frameRender(getMemDc(), getX(), getY() + (mHeight - mAni.GetImage()->getHeight()));
}

void Player::animation()
{
	mAni.frameUpdate(TIMEMANAGER->getElapsedTime());
}

void Player::move()
{
	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_L))
	{
		mCurDirection = Left;
		//¶Ù´Â ¾×¼Ç
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN))
		{
			offsetX(-30.0f);
			CAMERA->offSetX(-30.0f);

			changeStat(Run);
		}
		else
		{
			offsetX(-1.0f);
			CAMERA->offSetX(-1.0f);
			changeStat(Walk);
		}
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_R))
	{
		mCurDirection = eDirection::Right;
		if (mIsClickDownDashKey)
		{
			if (mDashTime >= 0) {
				offsetX(5.0f);
				CAMERA->offSetX(5.0f);
				changeStat(eStat::Dash);
			}
			else {
				offsetX(3.0f);
				CAMERA->offSetX(3.0f);
				changeStat(eStat::Run);
			}
		}
		else {
			offsetX(3.0f);
			CAMERA->offSetX(3.0f);
			changeStat(eStat::Run);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_EXEC))
	{
		changeStat(eStat::CommandExec);
		mNpcManager->orderGetWrench();
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_CALL))
	{
		changeStat(eStat::CommandCall);
		orderCallNpc();
	}


	if (KEYMANAGER->isOnceKeyDown(PLAYER_SHOOT))
	{
		changeStat(eStat::Shoot);

		if (mCurDirection == eDirection::Right) {
			mWeapon->shoot(getAbsRc().right, *getAbsY() + (mHeight / 2), mCurDirection);
		}
		else {
			mWeapon->shoot(getAbsRc().left, *getAbsY() + (mHeight / 2), mCurDirection);
		}
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_L) || KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_R)) {
		changeStat(eStat::Idle);
	}
}

void Player::action()
{
	if (mCurStat == eStat::CommandCall || mCurStat == eStat::CommandExec) {
		if (mAni.mPlayCount > 0) {
			changeStat(mPastStat);
		};
	}

	if (mCurStat == eStat::Shoot) {
		if (mAni.mPlayCount > 0) {
			changeStat(mPastStat);
		};
	}

	if (mCurStat == eStat::Dash) {
		mDashTime -= 0.1f;
	}
	else {
		if(mDashTime < PLAYER_DASH_MAX_DASH_TIME)
		mDashTime += 0.01f;
	}
}

void Player::changeStat(eStat changeStat)
{
	if (mCurStat != changeStat)
	{
		mPastStat = mCurStat;
		mCurStat = changeStat;
		mAni.ChangeCurImage(mCurStat, mCurDirection);
	}
}

void Player::orderCallNpc()
{
	RECT callableRc = getRc();
	
	if (mCurDirection == eDirection::Left) {
		callableRc.left -= 300;
	}
	else {
		callableRc.right += 300;
	}

	mNpcManager->orderCallNpc(callableRc);
}

void Player::orderExcuteNpc()
{
	mNpcManager->orderExecNpc();
}
