#include "Stdafx.h"
#include "NPC.h"

void Npc::init(float* playerAbsX, float* playerAbsY, eDirection * playerDirection, Player::eStat* playerStat, float width, float height)
{
	GameObject::Init("Npc", *playerAbsX + RND->getFromIntTo(300, 600), GROUND, width, height);

	Animation* cAni = new Animation;
	cAni->mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->CivilianIdleR), IMAGEMANAGER->findImage(IMGCLASS->CivilianIdleL), 7);
	cAni->mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->CivilianRunR), IMAGEMANAGER->findImage(IMGCLASS->CivilianRunL), 7);
	cAni->mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->CivilianWalkR), IMAGEMANAGER->findImage(IMGCLASS->CivilianWalkL), 7);
	cAni->mappingStatForImg(eStat::StopNoting, IMAGEMANAGER->findImage(IMGCLASS->CivilianIdleR), IMAGEMANAGER->findImage(IMGCLASS->CivilianIdleL), 7);
	cAni->mappingStatForImg(eStat::WalkNoting, IMAGEMANAGER->findImage(IMGCLASS->CivilianWalkR), IMAGEMANAGER->findImage(IMGCLASS->CivilianWalkL), 7);
	cAni->mappingStatForImg(eStat::FollowToPlayer, IMAGEMANAGER->findImage(IMGCLASS->CivilianRunR), IMAGEMANAGER->findImage(IMGCLASS->CivilianRunL), 7);
	cAni->mappingStatForImg(eStat::Grab, IMAGEMANAGER->findImage(IMGCLASS->CivilianGrabR), IMAGEMANAGER->findImage(IMGCLASS->CivilianGrabL), 7);
	cAni->mappingStatForImg(eStat::Build, IMAGEMANAGER->findImage(IMGCLASS->CivilianBuildR), IMAGEMANAGER->findImage(IMGCLASS->CivilianBuildL), 10);
	cAni->ChangeCurImage(eStat::Idle, mCurDirection);

	Animation* eAni = new Animation;
	eAni->mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleR), IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleL), 7);
	eAni->mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->EngineerRunR), IMAGEMANAGER->findImage(IMGCLASS->EngineerRunL), 7);
	eAni->mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkR), IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkL), 7);
	eAni->mappingStatForImg(eStat::StopNoting, IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleR), IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleL), 7);
	eAni->mappingStatForImg(eStat::WalkNoting, IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkR), IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkL), 7);
	eAni->mappingStatForImg(eStat::FollowToPlayer, IMAGEMANAGER->findImage(IMGCLASS->EngineerRunR), IMAGEMANAGER->findImage(IMGCLASS->EngineerRunL), 7);
	eAni->ChangeCurImage(eStat::Idle, mCurDirection);

	Animation* dAni = new Animation;
	dAni->mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->DiggerIdleR), IMAGEMANAGER->findImage(IMGCLASS->DiggerIdleL), 7);
	dAni->mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->DiggerRunR), IMAGEMANAGER->findImage(IMGCLASS->DiggerRunL), 7);
	dAni->mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->DiggerWalkR), IMAGEMANAGER->findImage(IMGCLASS->DiggerWalkL), 7);
	dAni->mappingStatForImg(eStat::StopNoting, IMAGEMANAGER->findImage(IMGCLASS->DiggerIdleR), IMAGEMANAGER->findImage(IMGCLASS->DiggerIdleL), 7);
	dAni->mappingStatForImg(eStat::WalkNoting, IMAGEMANAGER->findImage(IMGCLASS->DiggerWalkR), IMAGEMANAGER->findImage(IMGCLASS->DiggerWalkL), 7);
	dAni->mappingStatForImg(eStat::FollowToPlayer, IMAGEMANAGER->findImage(IMGCLASS->DiggerRunR), IMAGEMANAGER->findImage(IMGCLASS->DiggerRunL), 7);
	dAni->mappingStatForImg(eStat::Grab, IMAGEMANAGER->findImage(IMGCLASS->DiggerGrabR), IMAGEMANAGER->findImage(IMGCLASS->DiggerGrabL), 7);
	dAni->ChangeCurImage(eStat::Idle, mCurDirection);

	mMAni.insert(make_pair(eType::Civilian, cAni));
	mMAni.insert(make_pair(eType::Digger, dAni));
	mMAni.insert(make_pair(eType::Engineer, eAni));

	mPlayerAbsX = playerAbsX;
	mPlayerAbsY = playerAbsY;

	mPlayerDirection = playerDirection;

	mPlayerStat = playerStat;

	mCurStat = eStat::StopNoting;
	mCurDirection = eDirection::Left;

	mCurAni = mMAni.find(eType::Civilian)->second;

	nothing();
}

void Npc::release(void)
{

}

void Npc::draw()
{
	mCurAni->GetImage()->frameRender(getMemDc(), getRc().left, getRc().bottom - mCurAni->GetImage()->getHeight(), mCurAni->mFrameX, mCurAni->mFrameY);
}

void Npc::animation()
{
	mCurAni->frameUpdate(TIMEMANAGER->getElapsedTime());
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
		float distance = 0.0f;

		if (*mPlayerDirection == eDirection::Left) {
			distance = static_cast<int> (*mPlayerAbsX + (mRank * 80) - getAbsX());
		}
		else if (*mPlayerDirection == eDirection::Right) {
			distance = static_cast<int> (*mPlayerAbsX - (mRank * 80) - getAbsX());
		}

		if (distance > 0) {
			chageImg(eStat::Run, mCurDirection);
			if (*mPlayerStat == Player::eStat::Dash) {
				offsetX(RND->getFromFloatTo(3.0f, 6.0f));
			}
			else {
				offsetX(RND->getFromFloatTo(2.0f, 4.0f));
			}
		}
		else if (distance < 0) {
			chageImg(eStat::Run, mCurDirection);
			if (*mPlayerStat == Player::eStat::Dash) {
				offsetX(-RND->getFromFloatTo(3.0f, 6.0f));
			}
			else {
				offsetX(-RND->getFromFloatTo(2.0f, 4.0f));
			}
		}
		else {
			mCurDirection = *mPlayerDirection;
			chageImg(eStat::Idle, mCurDirection);
		};
	}
	break;
	default:
		break;
	}
}

void Npc::action()
{
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

	if (*mPlayerAbsX - getAbsX() > 0) {
		mCurDirection = eDirection::Right;
	}
	else if (*mPlayerAbsX - getAbsX() < 0) {
		mCurDirection = eDirection::Left;
	};

	changeStat(eStat::FollowToPlayer, mCurDirection);
}

void Npc::orderGrap()
{
	mOrderCount = 500;
	switch (mType)
	{
	case Npc::eType::Civilian:
		changeStat(eStat::Build, *mPlayerDirection);
		break;
	case Npc::eType::Digger:
		changeStat(eStat::Grab, *mPlayerDirection);
		break;
	case Npc::eType::Engineer:
		//�Ұ� �ִϸ��̼�
		break;
	default:
		break;
	}
}

void Npc::orderGetShovel()
{
	changeType(eType::Digger);
}

void Npc::orderGetWrench()
{
	changeType(eType::Engineer);
}

void Npc::changeType(eType type)
{
	mType = type;
	mCurAni = mMAni.find(type)->second;
}

void Npc::nothing()
{
	mNotingStartX = getAbsRc().left;

	if (mCurDirection == eDirection::Left) {
		mNotingToX = mNotingStartX - RND->getFromIntTo(200, 700);
	}
	else if (mCurDirection == eDirection::Right) {
		mNotingToX = mNotingStartX + RND->getFromIntTo(200, 700);
	}

	changeStat(eStat::WalkNoting, mCurDirection);
}

void Npc::changeStat(eStat changeStat, eDirection direction)
{
	if (mCurStat != changeStat)
	{
		mPastStat = mCurStat;
		mCurStat = changeStat;
		mCurAni->ChangeCurImage(mCurStat, direction);
	}
}

void Npc::chageImg(eStat changeStat, eDirection direction)
{
	if (mCurStat != changeStat)
	{
		mCurAni->ChangeCurImage(changeStat, direction);
	}
}
