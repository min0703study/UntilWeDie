#include "Stdafx.h"
#include "Player.h"
#include "Camera.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);

	mAni.SetStatImage(Idle, IMAGEMANAGER->findImage(IMGCLASS->PlayerIdle));
	
	mAni.SetStatImage(WalkR, IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR));
	mAni.SetStatImage(WalkL, IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL));

	mAni.SetStatImage(RunR, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR));
	mAni.SetStatImage(RunL, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL));

	mAni.SetStatImage(CommandCall, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCall));
	mAni.SetStatImage(CommandExec, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExec));

	mAni.ChangeCurImage(Idle);
}

void Player::release(void)
{
}

void Player::draw()
{
	mAni.GetImage()->frameRender(getMemDc(), getX(), getY());
}

void Player::animation()
{
}

void Player::move()
{
	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_L)) 
	{
		//¶Ù´Â ¾×¼Ç
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN)) 
		{
			offsetX(-3.0f);
			CANERA->offSetX(-3.0f);
			changeStat(RunL);
		}
		else {
			offsetX(-1.0f);
			CANERA->offSetX(-1.0f);
			changeStat(WalkL);
		}

	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_R))
	{
		if (KEYMANAGER->isStayKeyDown(PLAYER_RUN))
		{
			offsetX(3.0f);
			CANERA->offSetX(3.0f);
			changeStat(RunR);
		}
		else {
			offsetX(1.0f);
			CANERA->offSetX(1.0f);
			changeStat(WalkR);
		}
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_COMMAND_EXEC))
	{
		changeStat(CommandExec);
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_COMMAND_CALL))
	{
		changeStat(CommandCall);
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_L) || KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_R)) {
		changeStat(Idle);
	}
}

void Player::action()
{
	mAni.frameUpdate(TIMEMANAGER->getElapsedTime());
}

void Player::changeStat(eStat changeStat)
{
	if (mCurStat != changeStat) 
	{
		mCurStat = changeStat;
		mAni.ChangeCurImage(mCurStat);
	}
}
