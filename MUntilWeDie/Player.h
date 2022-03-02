#pragma once
#include "GameObject.h"

class NpcManager;
class Weapon;

class Player : public GameObject
{
public:
	enum class eStat {
		Idle,
		Walk,
		Run,
		Dash,
		Shoot,
		ShootRun,
		CommandCall,
		CommandExec
	}

	typedef	struct tagAnimation
	{

		float mFrameUpdateSec;	// 초당 프레임 업데이트 수
		float mElapsedSec;		// 프레임과 프레임 사이의 시간

		ImageBase* mCurImage;
		float mElapsedSec;
		
		map<Player::eStat, ImageBase*> mImgRMap;
		map<Player::eStat, ImageBase*> mImgLMap;
		map<Player::eStat, float> mFrameUpdateSecMap;

		tagAnimation()
		{
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mCurImage = nullptr;
		}

		void ChangeCurImage(eStat changeStat, eDirection curDirection)
		{
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

			if (mElapsedSec >= mFrameUpdateSec)
			{
				mElapsedSec = 0;
				mCurImage->offsetX(1, true);
				if (mCurImage->getFrameX() > mCurImage->getMaxFrameX())
				{
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

	Player() {};
	~Player() {};

private:
	eStat mCurStat;
	eStat mPastStat;

	eDirection mCurDirection;

	bool mIsClickDownDashKey;

	Animation mAni;
	NpcManager* mNpcManager;

	Weapon* mWeapon;

	float mDashTime;
	float mHp;

	void changeStat(eStat changeStat);
	
	void orderCallNpc();
	void orderExcuteNpc();

};

