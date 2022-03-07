#include "Stdafx.h"
#include "Player.h"
#include "NpcManager.h"
#include "Weapon.h"
#include "BuildManager.h"
#include "IBuilding.h"

void Player::init(float x, float y, float width, float height)
{
	GameObject::Init("Player", x, y, width, height);
	mMushRoomCount = 0;
	mMushRoomImg = IMAGEMANAGER->findImage(IMGCLASS->PlayerUIMushRoom);
	mGearImg = IMAGEMANAGER->findImage(IMGCLASS->PlayerUIGear);

	mIsDead = false;
	mAni.mappingStatForImg(eStat::Idle, IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleR), IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleL), 7);
	mAni.mappingStatForImg(eStat::Run, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 7);
	mAni.mappingStatForImg(eStat::Dash, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL), 7);
	mAni.mappingStatForImg(eStat::Walk, IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR), IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL), 7);
	mAni.mappingStatForImg(eStat::CommandCall, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallL), 7);
	mAni.mappingStatForImg(eStat::CommandExec, IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecR), IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecL), 7);
	mAni.mappingStatForImg(eStat::Shoot, IMAGEMANAGER->findImage(IMGCLASS->PlayerShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerShootL), 7);
	mAni.mappingStatForImg(eStat::ShootRun, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL), 7);
	mAni.mappingStatForImg(eStat::ShootDash, IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR), IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL), 7);
	mAni.mappingStatForImg(eStat::Death, IMAGEMANAGER->findImage(IMGCLASS->PlayerDeathL), IMAGEMANAGER->findImage(IMGCLASS->PlayerDeathR), 7);

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

	mHp = 200;

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
	mMushRoomImg->render(getMemDc(), 0, 70);
	GDIPLUSMANAGER->drawText(getMemDc(), to_wstring(mMushRoomCount), 110, 80, 36, Gdiplus::Color(255, 255, 255));

	mGearImg->render(getMemDc(), 0, 160);
	GDIPLUSMANAGER->drawText(getMemDc(), to_wstring(mGearCount), 110, 170, 36, Gdiplus::Color(255, 255, 255));
	if (mIsClickDownDashKey) {
		if (mCurDirection == eDirection::Left) {
			GDIPLUSMANAGER->drawCProgressBar(getMemDc(), getRc().right, getRc().top, 5, mDashTime, PLAYER_DASH_MAX_DASH_TIME);

		}
		else {
			GDIPLUSMANAGER->drawCProgressBar(getMemDc(), getRc().left, getRc().top, 5, mDashTime, PLAYER_DASH_MAX_DASH_TIME);
		}
	}

	mAni.GetImage()->frameRender(getMemDc(), getRc().left, getRc().bottom - mAni.GetImage()->getHeight());
}

void Player::animation()
{

	if (mCurStat == eStat::Death) {
		if (mAni.mPlayCount == 0) {
			mAni.frameUpdate(TIMEMANAGER->getElapsedTime());
		};
	}
	else {
		mAni.frameUpdate(TIMEMANAGER->getElapsedTime());
	}
}

void Player::move()
{
	if (mIsDead) return;

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
					offsetX(-PLAYER_SPEED_DASH);
					CAMERA->offSetX(-PLAYER_SPEED_DASH);
					if (mCurStat != eStat::ShootDash && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Dash);
					}
				}
				else {
					offsetX(-PLAYER_SPEED_RUN);
					CAMERA->offSetX(-PLAYER_SPEED_RUN);
					if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Run);
					}
				}

			}
			else {
				offsetX(-PLAYER_SPEED_RUN);
				CAMERA->offSetX(-PLAYER_SPEED_RUN);
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
					offsetX(PLAYER_SPEED_DASH);
					CAMERA->offSetX(PLAYER_SPEED_DASH);
					if (mCurStat != eStat::ShootDash && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Dash);
					}
				}
				else {
					offsetX(PLAYER_SPEED_RUN);
					CAMERA->offSetX(PLAYER_SPEED_RUN);
					if (mCurStat != eStat::Run && mCurStat != eStat::ShootRun) {
						changeStat(eStat::Run);
					}
				}
			}
			else {
				offsetX(PLAYER_SPEED_RUN);
				CAMERA->offSetX(PLAYER_SPEED_RUN);
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
			orderExcuteNpc();
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

			collsionCheckMonster();
		};
	}

	if (KEYMANAGER->isOnceKeyDown(PLAYER_COMMAND_POS_CHANGE))
	{
		mNpcManager->changeNpcPosition();
	}

	if (KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_L) || KEYMANAGER->isOnceKeyUp(PLAYER_MOVE_R)) {
		changeStat(eStat::Idle);
	}

	int returnInt = mIObject->isItemManagerCollisionToPlayer(getAbsRc());
	switch (returnInt)
	{
	case 1:
		mMushRoomCount++;
		break;
	case 2:
		mGearCount++;
		break;
	case -1:
		break;
	default:
		break;
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

float Player::getPlayerAbsX()
{
	return getAbsX();
}

RECT Player::getPlayerRc()
{
	return getRc();
}

RECT Player::getPlayerAbsRc()
{
	return getAbsRc();
}

vector<float> Player::getNpcsAbsX()
{
	return mNpcManager->getNpcsAbsX();
}

vector<RECT> Player::getNpcsRc()
{
	return mNpcManager->getNpcsRc();
}

vector<RECT> Player::getNpcsAbsRc()
{
	return mNpcManager->getNpcsAbsRc();
}

void Player::isOverGrapObject(int npcIndex)
{
	//mNpcManager->changeStat(npcIndex, Npc::eOrderType::Nothing);
}

void Player::attackDamageToPlayer(int damage)
{
	mHp -= damage;
	if (mHp <= 0 && !mIsDead) {
		mNpcManager->orderRunDiffDirection();
		changeStat(eStat::Death);
		mIsDead = true;
	}
}

void Player::attackDamageToNpc(int damage, int arrNum)
{
	/*
	mHp -= damage;
	if (mHp <= 0) {
		changeStat(eStat::Death);
		mIsDead = true;
	}
	*/
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
		callableRc.left -= NPC_CALLABLE_X_SIZE;
	}
	else {
		callableRc.right += NPC_CALLABLE_X_SIZE;
	}

	mNpcManager->orderCallNpc(callableRc);
}

void Player::orderExcuteNpc()
{
	int objectIndex = mIObject->isObjectCollisionToPlayer(getAbsRc());

	if (objectIndex != -1) {
		float xPos = 0;
		mIObject->startGrapObject(objectIndex, 0, xPos);
		mNpcManager->orderExecNpc(xPos);
		return;
	}

	bool isBuildSuccess;
	BuildManager::eBuildType buildCollsion = BuildManager::eBuildType(mIbuilding->isBuildingCollisionToPlayer(getAbsRc(), isBuildSuccess));

	if (!isBuildSuccess) {
		mNpcManager->orderBuildBuilding();
	}
	else {
		if (buildCollsion != BuildManager::eBuildType::tNothing) {
			switch (buildCollsion)
			{
			case BuildManager::eBuildType::tShovelShop:
				mNpcManager->orderGetShovel();
				break;
			case BuildManager::eBuildType::tEngineerShop:
				mNpcManager->orderGetWrench();
				break;
			case BuildManager::eBuildType::tShopStalkers:
				mNpcManager->orderGetGun();
				break;
			case BuildManager::eBuildType::tWorkbanch:
				mIbuilding->resetShopItem(mNpcManager->orderResetType());
				break;
			default:
				//Do Nothing
				break;
			}
		}
	}
}

void Player::collsionCheckMonster() {
	vector<RECT> rects = mIMonster->getMonstersAbsRc();
	vector<tagBullet> bullets = mWeapon->getBullets();
	RECT tempRect;

	int i = 0;
	for (vector<RECT>::iterator iRects = rects.begin(); iRects != rects.end(); iRects++, i++) {
		for (vector<tagBullet>::iterator iBullets = bullets.begin(); iBullets != bullets.end(); iBullets++) {
 			if (IntersectRect(&tempRect, &(*iRects), &(*iBullets).absRc)) {
   				mIMonster->attackDamage(50, i);
				mWeapon->attackSuccess();
				break;
			}
		}
	}
}


void Player::collsionCheckObject() {
	vector<RECT> rects;
	RECT tempRect;
	int i = 0;
	for (vector<RECT>::iterator iRects = rects.begin(); iRects != rects.end(); iRects++, i++) {
		if (IntersectRect(&tempRect, &(*iRects), &getAbsRc())) {
			mMushRoomCount++;
			break;
		}
	}
}
