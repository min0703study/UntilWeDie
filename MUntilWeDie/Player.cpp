#include "Stdafx.h"
#include "Player.h"
#include "NpcManager.h"
#include "Weapon.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);

	mAni.mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleR), IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleL), 7);
	mAni.mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 7);
	mAni.mappingStatForImg(eStat::Dash, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 7);
	mAni.mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR), IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL), 7);
	mAni.mappingStatForImg(eStat::CommandCall, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallL), 7);
	mAni.mappingStatForImg(eStat::CommandExec, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecL), 7);
	mAni.mappingStatForImg(eStat::Shoot, IMAGEMANAGER->findImage(IMGCLASS->PlayerShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerShootL), 7);
	mAni.mappingStatForImg(eStat::ShootRun, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL), 7);
	mAni.mappingStatForImg(eStat::ShootDash, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL), 7);

	mMStatRank.insert(make_pair(eStat::Idle, 0));
	mMStatRank.insert(make_pair(eStat::Run, 0));
	mMStatRank.insert(make_pair(eStat::Dash, 0));
	mMStatRank.insert(make_pair(eStat::Walk, 0));
	mMStatRank.insert(make_pair(eStat::CommandCall, 3));
	mMStatRank.insert(make_pair(eStat::CommandExec, 3));
	mMStatRank.insert(make_pair(eStat::Shoot, 0));
	mMStatRank.insert(make_pair(eStat::ShootRun, 0));
	mMStatRank.insert(make_pair(eStat::ShootDash, 0));

	mWeapon = new Weapon;
	mWeapon->init("");

	mNpcManager = new NpcManager;
	mNpcManager->init(getAbsPX(), getAbsPY(), &mCurStat, &mCurDirection);

	mCurStat = eStat::Idle;
	mCurDirection = eDirection::Right;

	mIsClickDownDashKey = false;

	mAni.ChangeCurImage(mCurStat, mCurDirection);

	mDashTime = PLAYER_DASH_MAX_DASH_TIME;
}

void Player::release(void)
{
	GameObject::release();

	mWeapon->release();
	mNpcManager->release();
	SAFE_DELETE(mNpcManager);
}

void Player::update(void)
{
	GameObject::update();

	move();
	action();
	mNpcManager->update();
	mWeapon->update();
}
void Player::render(void)
{
	GameObject::render();

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

	mAni.GetImage()->frameRender(getMemDc(), getRc().left, getRc().bottom - mAni.GetImage()->getHeight());
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
		if (mMStatRank.find(mCurStat)->second <= mMStatRank.find(eStat::Run)->second) {
			mCurDirection = eDirection::Left;
			if (mIsClickDownDashKey)
			{
				if (mDashTime >= 0) {
					offsetX(-5.0f);
					CAMERA->offSetX(-5.0f);
					if (mCurStat != eStat::ShootDash && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Dash);
					}
				}
				else {
					offsetX(-3.0f);
					CAMERA->offSetX(-3.0f);
					if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Run);
					}
				}

			}
			else {
				offsetX(-3.0f);
				CAMERA->offSetX(-3.0f);
				if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
					changeStat(eStat::Run);
				}
			}
		}
	}

	if (KEYMANAGER->isStayKeyDown(PLAYER_MOVE_R))
	{
		if (mMStatRank.find(mCurStat)->second <= mMStatRank.find(eStat::Run)->second) {
			mCurDirection = eDirection::Right;
			if (mIsClickDownDashKey)
			{
				if (mDashTime >= 0) {
					offsetX(5.0f);
					CAMERA->offSetX(5.0f);
					if (mCurStat != eStat::ShootDash && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Dash);
					}
				}
				else {
					offsetX(3.0f);
					CAMERA->offSetX(3.0f);
					if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Run);
					}
				}
			}
			else {
				offsetX(3.0f);
				CAMERA->offSetX(3.0f);
				if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
					changeStat(eStat::Run);
				}
			}
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_EXEC))
	{
		if (mMStatRank.find(mCurStat)->second <= mMStatRank.find(eStat::CommandExec)->second) {
			changeStat(eStat::CommandExec);
			mNpcManager->orderExecNpc();
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_CALL))
	{
		if (mMStatRank.find(mCurStat)->second <= mMStatRank.find(eStat::CommandCall)->second) {
			changeStat(eStat::CommandCall);
			orderCallNpc();
		}
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_SHOOT))
	{

		if (mCurStat != eStat::Shoot && mCurStat != eStat::ShootRun && mCurStat != eStat::ShootDash) {
			if (mCurStat == eStat::Run) {
				changeStat(eStat::ShootRun);
			}
			else if(mCurStat == eStat::Dash) {
				changeStat(eStat::ShootDash);
			}
			else {
				changeStat(eStat::Shoot);
			}

			if (mCurDirection == eDirection::Right) {
				mWeapon->shoot(getAbsRc().right, getAbsY() - (mHeight / 2), mCurDirection);
			}
			else {
				mWeapon->shoot(getAbsRc().left, getAbsY() - (mHeight / 2), mCurDirection);
			}
		};
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

	if (mCurStat == eStat::Shoot || mCurStat == eStat::ShootRun || mCurStat == eStat::ShootDash) {
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

RECT Player::getPlayerRc()
{
	return RECT();
}

void Player::isOverGrapObject(int npcIndex)
{
	mNpcManager->changeStat(npcIndex, Npc::eOrderType::Noting);
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
