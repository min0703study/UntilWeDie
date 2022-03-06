#pragma once
#include "GameObject.h"
#include "IPlayer.h"
#include "IObject.h"
#include "IMonster.h"

class NpcManager;
class IBuilding;
class Weapon;

class Player : public GameObject, public IPlayer
{
public:
	enum class eStat {
		Idle,
		Walk,
		Run,
		Dash,
		Shoot,
		ShootRun,
		ShootDash,
		CommandCall,
		CommandExec,
		Death
	};

	typedef	struct tagAnimation {
		float mFrameUpdateSec;
		int mPlayCount;

		ImageBase* mCurImage;
		float mElapsedSec;
		
		map<Player::eStat, ImageBase*> mImgRMap;
		map<Player::eStat, ImageBase*> mImgLMap;
		map<Player::eStat, float> mFrameUpdateSecMap;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mCurImage = nullptr;
		}

		void ChangeCurImage(eStat changeStat, eDirection curDirection) {
			mPlayCount = 0;
			if (curDirection == eDirection::Left) {
				auto key = mImgLMap.find(changeStat);
				if (key != mImgLMap.end())
				{
					mCurImage = key->second;
				}
			}
			else {
				auto key = mImgRMap.find(changeStat);
				if (key != mImgRMap.end())
				{
					mCurImage = key->second;
				}
			}

			auto updateSecKey = mFrameUpdateSecMap.find(changeStat);
			if (updateSecKey != mFrameUpdateSecMap.end())
			{
				mFrameUpdateSec = updateSecKey->second;
			}
		}

		void frameUpdate(float elapsedTime)
		{
			if (elapsedTime < 0) return;
			mElapsedSec += elapsedTime;

			if (mElapsedSec >= mFrameUpdateSec) {
				mElapsedSec = 0;
				mCurImage->offsetX(1, true);
				if (mCurImage->getFrameX() > mCurImage->getMaxFrameX()) {
					mPlayCount++;
					mCurImage->setFrameX(0);
				}
			}
		}

		inline ImageBase* GetImage() const { return mCurImage; }

		void mappingStatForImg(Player::eStat stat, ImageBase* rightImg, ImageBase* leftImg, float frameUpdateSec) {
			mImgRMap.insert(make_pair(stat, rightImg));
			mImgLMap.insert(make_pair(stat, leftImg));
			mFrameUpdateSecMap.insert(make_pair(stat, 1.0f/ frameUpdateSec));
		}
	} Animation;

	void init(float x, float y, float width, float height);
	void release(void);

	void update(void);

	void render(void);

	void draw();
	void animation();
	void move();
	void action();

	//interface
	float getPlayerAbsX() override;
	RECT getPlayerRc() override;
	RECT getPlayerAbsRc() override;
	vector<float> getNpcsAbsX() override;
	vector<RECT> getNpcsRc() override;
	vector<RECT> getNpcsAbsRc() override;
	void isOverGrapObject(int npcIndex) override;
	void attackDamageToPlayer(int damage) override;
	void attackDamageToNpc(int damage, int arrNum) override;

	void setIBuilding(IBuilding* iBuilding) {
		mIbuilding = iBuilding;
	};

	void setIObject(IObject* iObject) {
		mIObject = iObject;
	};

	void setIMonster(IMonster* iMonster) {
		mIMonster = iMonster;
	};

	bool isDeath() { return mIsDead; }

	ImageBase* mMushRoomImg;
	ImageBase* mGearImg;

	Player() {};
	~Player() {};
private:
	eStat mCurStat;
	eStat mPastStat;

	map<eStat, int> mMStatRank;

	eDirection mCurDirection;

	bool mIsClickDownDashKey;
	bool mIsDead;

	Animation mAni;
	NpcManager* mNpcManager;

	IBuilding* mIbuilding;
	IObject* mIObject;
	IMonster* mIMonster;
	Weapon* mWeapon;

	int mMushRoomCount;
	int mGearCount;

	float mDashTime;
	float mHp;

	void changeStat(eStat changeStat);
	
	void orderCallNpc();
	void orderExcuteNpc();

	void collsionCheckMonster();

	void collsionCheckObject();

};

