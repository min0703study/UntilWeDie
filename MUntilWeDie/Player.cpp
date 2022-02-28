#include "Stdafx.h"
#include "Player.h"
#include "NpcManager.h"
#include "Camera.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);
	
	mNpcManager = new NpcManager;
	mNpcManager->init(getAbsX(), getAbsY(),&mCurStat, &mCurDirection);
	
	mCurStat = eStat::Idle;
	mCurDirection = eDirection::Right;

	mIsClickDownDashKey = false;

	mAni.ChangeCurImage(mCurStat, mCurDirection);

	mDashTime = PLAYER_DASH_MAX_DASH_TIME;
}

void Player::release(void)
{
	mNpcManager->release();
	SAFE_DELETE(mNpcManager);
}

void Player::update(void)
{
	move();
	action();
	mNpcManager->update();
}
void Player::render(void)
{
	draw();
	animation();
	mNpcManager->render();
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

	if (KEYMANAGER->isOnceKeyDown(PLAYER_DASH)) {
		mIsClickDownDashKey = true;
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_DASH)) {
		mIsClickDownDashKey = false;
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_L)) 
	{
		mCurDirection = eDirection::Left;
		if (mIsClickDownDashKey)
		{
			if (mDashTime >= 0) {
				offsetX(-5.0f);
				CAMERA->offSetX(-5.0f);
				changeStat(eStat::Dash);
			}
			else {
				offsetX(-3.0f);
				CAMERA->offSetX(-3.0f);
				changeStat(eStat::Run);
			}

		} else {
			offsetX(-3.0f);
			CAMERA->offSetX(-3.0f);
			changeStat(eStat::Run);
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
		orderExcuteNpc();
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_CALL))
	{
		changeStat(eStat::CommandCall);
		orderCallNpc();
	}


	if (KEYMANAGER->isOnceKeyDown(PLAYER_SHOOT))
	{
		changeStat(eStat::Shoot);
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

	if (mCurStat == eStat::Dash) {
		mDashTime -= 0.1;
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
	RECT callableRc = getAbsRc();
	
	callableRc.left -= 200;
	callableRc.right += 200;

	mNpcManager->orderCallNpc(callableRc);
}

void Player::orderExcuteNpc()
{
	mNpcManager->orderExecNpc();
}
