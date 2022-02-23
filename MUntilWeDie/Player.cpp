#include "Stdafx.h"
#include "Player.h"
#include "Camera.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);

	mAni.SetStatImage(Idle, IMAGEMANAGER->findImage(IMGCLASS->PLAYER_IDLE));
	
	mAni.SetStatImage(WalkR, IMAGEMANAGER->findImage(IMGCLASS->PLAYER_WALK_R));
	mAni.SetStatImage(WalkL, IMAGEMANAGER->findImage(IMGCLASS->PLAYER_WALK_L));

	mAni.SetStatImage(RunR, IMAGEMANAGER->findImage(IMGCLASS->PLAYER_RUN_R));
	mAni.SetStatImage(RunL, IMAGEMANAGER->findImage(IMGCLASS->PLAYER_RUN_L));

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
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) 
	{
		//¶Ù´Â ¾×¼Ç
		if (KEYMANAGER->isStayKeyDown(VK_LSHIFT)) 
		{
			offsetX(-3.0f);
			CANERA->OffSetX(-3.0f);
			changeStat(RunL);
		}
		else {
			offsetX(-1.0f);
			CANERA->OffSetX(-1.0f);
			changeStat(WalkL);
		}

	}

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) 
	{
		if (KEYMANAGER->isStayKeyDown(VK_LSHIFT))
		{
			offsetX(3.0f);
			CANERA->OffSetX(3.0f);
			changeStat(RunR);
		}
		else {
			offsetX(1.0f);
			CANERA->OffSetX(1.0f);
			changeStat(WalkR);
		}
	}

	if (KEYMANAGER->isOnceKeyUp(VK_LEFT) || KEYMANAGER->isOnceKeyUp(VK_RIGHT)) {
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
