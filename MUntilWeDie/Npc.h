#pragma once
#include "GameObject.h"
#include "Player.h"

class Npc: public GameObject
{
public:
	enum class eStat {
		Idle,
		Walk,
		Run,
		StopNoting,
		WalkNoting,
		FollowToPlayer,
		Grab,
		Build,
		CantUnderstand,
		RunOver
	};

	enum class eType {
		Civilian,
		Digger,
		Engineer,
		Fighter
	};

	enum class eOrderType {
		Nothing,
		Grap
	};

	typedef	struct tagAnimation {
		float mFrameUpdateSec;
		int mPlayCount;

		Npc::eStat mCurImgStat;

		ImageBase* mCurImage;
		float mElapsedSec;

		float mFrameX;
		float mFrameY;

		map<Npc::eStat, ImageBase*> mImgRMap;
		map<Npc::eStat, ImageBase*> mImgLMap;
		map<Npc::eStat, float> mFrameUpdateSecMap;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mFrameX = 1;
			mFrameY = 1;

			mCurImage = nullptr;
			mCurImgStat = Npc::eStat::Idle;
		}

		void ChangeCurImage(eStat changeStat, eDirection curDirection) {
			//if (mCurImgStat == changeStat) return;
			mCurImgStat = changeStat;

			mPlayCount = 0;
			
			mFrameX = 1;
			mFrameY = 1;

			if (curDirection == eDirection::Left) {
				auto key = mImgLMap.find(changeStat);
				if (key != mImgLMap.end())
				{
					mCurImage = key->second;
				}
			}
			else if (curDirection == eDirection::Right) {
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
				mFrameX++;
				if (mFrameX > mCurImage->getMaxFrameX()) {
					mPlayCount++;
					mFrameX = 0;
				}
			}
		}

		inline ImageBase* GetImage() const { 
			return mCurImage; 
		
		}

		void mappingStatForImg(Npc::eStat stat, ImageBase* rightImg, ImageBase* leftImg, float frameUpdateSec) {
			mImgRMap.insert(make_pair(stat, rightImg));
			mImgLMap.insert(make_pair(stat, leftImg));
			mFrameUpdateSecMap.insert(make_pair(stat, 1.0f / frameUpdateSec));
		}
	} Animation;

	void init(float * playerAbsX, 
		float * playerAbsY, 
		eDirection * playerDirection, 
		Player::eStat* playerStat,
		float width, float height);

	void release(void);

	void update(void) {
		move();
		action();
	};

	void render(void) {
		draw();
		animation();
	};

	void draw();
	void animation();
	void move();
	void action();

	//npc 행동
	void orderCall(int rank);
	bool orderGrap(float xPos);
	void orderBuild();
	void orderGetShovel();
	void orderGetWrench();

	void orderGetGun();

	void changeType(eType type);
	void nothing();

	//getter setter
	void setRank(int rank) { mRank = rank; }
	void runDiffDirection();
	int getRank() { return mRank; }
	eType getType() const { return mType; }

	inline bool isActivated() { return mCurStat == eStat::FollowToPlayer; }

	Npc() {};
	~Npc() {};
private:
	map<eType, Animation*> mMAni;
	map<eType, Animation*>::iterator mMiAni;

	eStat mCurStat;
	eStat mPastStat;
	eDirection mCurDirection;
	eType mType;

	Animation* mCurAni;

	int mRank;
	int mId;

	//Player 데이터
	Player::eStat* mPlayerStat;
	float* mPlayerAbsX;
	float* mPlayerAbsY;

	float mToXToGrab;

	//nothing 상태에서 사용되는 멤버 변수
	int mNotingStopCount;
	int mNotingToX;
	int mNotingStartX;

	//명령 수행 시간
	int mOrderCount;

	void changeStat(eStat changeStat, eDirection direction);
	void chageImg(eStat changeStat, eDirection direction);

	eDirection* mPlayerDirection;

};


