#include "Stdafx.h"
#include "NPC.h"

void Npc::init(float* playerAbsX, float* playerAbsY, eDirection * playerDirection, Player::eStat* playerStat, float width, float height)
{
	GameObject::Init("Npc", *playerAbsX + RND->getFromIntTo(300, 600), *playerAbsY, width, height);

	mPlayerAbsX = playerAbsX;
	mPlayerAbsY = playerAbsY;

	mPlayerDirection = playerDirection;

	mPlayerStat = playerStat;

	mCurStat = eStat::StopNoting;
	mCurDirection = eDirection::Left;

	nothing();
}

void Npc::release(void)
{

}

void Npc::draw()
{
	mAni.GetImage()->frameRender(getMemDc(), getX(), getY());
}

void Npc::animation()
{
}

void Npc::move()
{
	switch (mCurStat)
	{
	case eStat::WalkNoting: {
		if (mCurDirection == eDirection::Left) {
			if (mNotingToX < getAbsRc().left) {
				offsetX(-1.0f);
			}
			else {
				mNotingStopCount = RND->getFromIntTo(300, 600);
				mNotingToX = mNotingStartX + RND->getFromIntTo(200, 400);
				mCurDirection = eDirection::Right;
				changeStat(eStat::StopNoting, mCurDirection);
			}
		}
		else if (mCurDirection == eDirection::Right) {
			if (mNotingToX > getAbsRc().right) {
				offsetX(1.0f);
			}
			else {
				mNotingStopCount = RND->getFromIntTo(300, 600);
				mNotingToX = mNotingStartX - RND->getFromIntTo(200, 400);
				mCurDirection = eDirection::Left;
				changeStat(eStat::StopNoting, mCurDirection);
			}
		}
	}
	break;
	case eStat::StopNoting:
		mNotingStopCount--;
		if (mNotingStopCount == 0) {
			changeStat(eStat::WalkNoting, mCurDirection);
		}
		break;

	case eStat::FollowToPlayer: {
		int distance = 0;

		if (*mPlayerDirection == eDirection::Left) {
			distance = static_cast<int> (*mPlayerAbsX + (mRank * 80) - *getAbsX());
		}
		else if (*mPlayerDirection == eDirection::Right) {
			distance = static_cast<int> (*mPlayerAbsX - (mRank * 80) - *getAbsX());
		}

		if (distance > 0) {
			mAni.ChangeCurImage(eStat::Run, mCurDirection);
			if (*mPlayerStat == Player::eStat::Dash) {
				offsetX(RND->getFromFloatTo(3.0f, 6.0f));
			}
			else {
				offsetX(RND->getFromFloatTo(2.0f, 4.0f));
			}
		}
		else if (distance < 0) {
			mAni.ChangeCurImage(eStat::Run, mCurDirection);
			if (*mPlayerStat == Player::eStat::Dash) {
				offsetX(-RND->getFromFloatTo(3.0f, 6.0f));
			}
			else {
				offsetX(-RND->getFromFloatTo(2.0f, 4.0f));
			}
		}
		else {
			mCurDirection = *mPlayerDirection;
			mAni.ChangeCurImage(eStat::Idle, mCurDirection);
		};
	}
	break;
	default:
		break;
	}
}

void Npc::action()
{
	mAni.frameUpdate(TIMEMANAGER->getElapsedTime());

	switch (mCurStat)
	{
	case eStat::Grab:
		mOrderCount--;
		if (mOrderCount == 0) {
			nothing();
		}
		break;
	default:
		break;
	}
}

void Npc::orderCall(int rank)
{
	mRank = rank;

	if (*mPlayerAbsX - *getAbsX() > 0) {
		mCurDirection = eDirection::Right;
	}
	else if (*mPlayerAbsX - *getAbsX() < 0) {
		mCurDirection = eDirection::Left;
	};

	changeStat(eStat::FollowToPlayer, mCurDirection);
}

void Npc::orderGrap()
{
	mOrderCount = 500;
	changeStat(eStat::Grab, *mPlayerDirection);
}

void Npc::changeType(eType type)
{
	mType = type;
}

void Npc::nothing()
{
	mNotingStartX = getX();

	if (mCurDirection == eDirection::Left) {
		mNotingToX = mNotingStartX - RND->getFromIntTo(0, 400);
	}
	else if (mCurDirection == eDirection::Right) {
		mNotingToX = mNotingStartX + RND->getFromIntTo(0, 400);
	}

	changeStat(eStat::WalkNoting, mCurDirection);
}

void Npc::changeStat(eStat changeStat, eDirection direction)
{
	if (mCurStat != changeStat)
	{
		mPastStat = mCurStat;
		mCurStat = changeStat;
		mAni.ChangeCurImage(mCurStat, direction);
	}
}
