#include "Stdafx.h"
#include "Player.h"
#include "Camera.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);
	
	mCurStat = Idle;
	mCurDirection = Right;

	mAni.ChangeCurImage(mCurStat, mCurDirection);
}

void Player::release(void)
{
}

void Player::draw()
{
	RectangleMake(getMemDc(), getRc());
	mAni.GetImage()->frameRender(getMemDc(), getX(), getY() + (mHeight - mAni.GetImage()->getHeight()));
}

void Player::animation()
{
}

void Player::move()
{
	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_L)) 
	{
		mCurDirection = Left;
		//¶Ù´Â ¾×¼Ç
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN)) 
		{
			offsetX(-3.0f);
			CAMERA->offSetX(-3.0f);
			
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
		mCurDirection = Right;
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN))
		{
			offsetX(3.0f);
			CAMERA->offSetX(3.0f);
			changeStat(Run);
		}
		else
		{
			offsetX(1.0f);
			CAMERA->offSetX(1.0f);
			changeStat(Walk);
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_EXEC))
	{
		changeStat(CommandExec);
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_CALL))
	{
		changeStat(CommandCall);
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_L) || KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_R))
	{
		changeStat(Idle);
	}
}

void Player::action()
{
	mAni.frameUpdate(TIMEMANAGER->getElapsedTime());

	if (mCurStat == CommandCall || mCurStat == CommandExec)
	{
		if (mAni.mPlayCount > 0)
		{
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
