#include "Stdafx.h"
#include "Player.h"
#include "NpcManager.h"
#include "Camera.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);
	
	mNpcManager = new NpcManager;
	mNpcManager->init(getAbsX(), getAbsY(), &mCurDirection);
	
	mCurStat = Idle;
	mCurDirection = eDirection::Right;

	mAni.ChangeCurImage(mCurStat, mCurDirection);
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
	mAni.GetImage()->frameRender(getMemDc(), getX(), getY() + (mHeight - mAni.GetImage()->getHeight()));
}

void Player::animation()
{
}

void Player::move()
{
	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_L)) 
	{
		mCurDirection = eDirection::Left;
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN)) 
		{
			offsetX(-5.0f);
			CAMERA->offSetX(-5.0f);
			
			changeStat(Dash);
		}
		else {
			offsetX(-3.0f);
			CAMERA->offSetX(-3.0f);
			changeStat(Run);
		}
		mNpcManager->orderFollowActiveNpc();
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_R))
	{
		mCurDirection = eDirection::Right;
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN))
		{
			offsetX(5.0f);
			CAMERA->offSetX(5.0f);
			changeStat(Dash);
		}
		else {
			offsetX(3.0f);
			CAMERA->offSetX(3.0f);
			changeStat(Run);
		}
		mNpcManager->orderFollowActiveNpc();
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_EXEC))
	{
		changeStat(CommandExec);
		orderExcuteNpc();
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_CALL))
	{
		changeStat(CommandCall);
		orderCallNpc();
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_L) || KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_R)) {
		changeStat(Idle);
		mNpcManager->orderStopActiveNpc();
	}
}

void Player::action()
{
	mAni.frameUpdate(TIMEMANAGER->getElapsedTime());

	if (mCurStat == CommandCall || mCurStat == CommandExec) {
		if (mAni.mPlayCount > 0) {
			changeStat(mPastStat);
		};
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
