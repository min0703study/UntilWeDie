#include "Stdafx.h"
#include "NPC.h"

void Npc::init(float* playerAbsX, float* playerAbsY, eDirection* playerDirection, float width, float height)
{
	GameObject::Init("Npc", *playerAbsX + RND->getFromIntTo(300, 600), *playerAbsY, width, height);

	mPlayerAbsX = playerAbsX;
	mPlayerAbsY = playerAbsY;

	mPlayerDirection = playerDirection;

	mCurStat = StopNoting;
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
	case RunToPlayer: {
		int distance = 0;

		if (*mPlayerDirection == eDirection::Left) {
			distance = static_cast<int> (*mPlayerAbsX + (mRank * 80) - *getAbsX());
		}
		else if (*mPlayerDirection == eDirection::Right) {
			distance = static_cast<int> (*mPlayerAbsX - (mRank * 80) - *getAbsX());
		}

		if (distance > 3) {
			offsetX(3.0f);
		}
		else if (distance < 3) {
			offsetX(-3.0f);
		}
		else {
			changeStat(StopToPlayer, *mPlayerDirection);
		};
	}
	break;
	case WalkNoting: {
		if (mCurDirection == eDirection::Left) {
			if (mNotingToX < getAbsRc().left) {
				offsetX(-1.0f);
			}
			else {
				mNotingStopCount = RND->getFromIntTo(300, 600);
				mNotingToX = mNotingStartX + RND->getFromIntTo(200, 400);
				mCurDirection = eDirection::Right;
				changeStat(StopNoting, mCurDirection);
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
				changeStat(StopNoting, mCurDirection);
			}
		}
	}
	break;
	case StopNoting:
		mNotingStopCount--;
		if (mNotingStopCount == 0) {
			changeStat(WalkNoting, mCurDirection);
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
	case Grab: 
		mActiveCount--;
		if (mActiveCount == 0) {
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

	changeStat(RunToPlayer, mCurDirection);
}

void Npc::orderFollow()
{
	changeStat(RunToPlayer, *mPlayerDirection);
}

void Npc::orderStop()
{
	changeStat(StopToPlayer, *mPlayerDirection);
}

void Npc::orderGrap()
{
	mActiveCount = 500;
	changeStat(Grab, *mPlayerDirection);
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

	changeStat(WalkNoting, mCurDirection);
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
