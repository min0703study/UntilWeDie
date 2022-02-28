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
	};

	enum class eType {
		Civilian,
		Digger,
		Engineer
	};

	enum class eOrderType {
		Grap
	};

	typedef	struct tagAnimation {

		float mFrameUpdateSec;	// 초당 프레임 업데이트 수
		float mElapsedSec;		// 프레임과 프레임 사이의 시간

		ImageBase* mCurImage;

		int mPlayCount;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mCurImage = nullptr;
		}

		void ChangeCurImage(eStat changeStat, eDirection curDirection) {
			mPlayCount = 0;
			switch (curDirection) {
			case eDirection::Left:
				switch (changeStat) {
				case eStat::Idle: case eStat::StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleL);
					break;
				case eStat::Walk: case eStat::WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkL);
					break;
				case eStat::Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerRunL);
					break;
				case eStat::Grab:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->CivilianBuildL);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			case eDirection::Right:
				switch (changeStat) {
				case eStat::Idle: case eStat::StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerIdleR);
					break;
				case eStat::Walk:case eStat::WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerWalkR);
					break;
				case eStat::Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->EngineerRunR);
					break;
				case eStat::Grab:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->DiggerGrabR);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			default:
				//Do Nothing
				break;
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
	void orderGrap();

	void changeType(eType type);
	void nothing();

	inline bool isActivated() { return mCurStat == eStat::FollowToPlayer; }

	Npc() {};
	~Npc() {};
private:
	eStat mCurStat;
	eStat mPastStat;
	eDirection mCurDirection;
	eType mType;

	Animation mAni;

	int mRank;

	//Player 데이터
	Player::eStat* mPlayerStat;
	float* mPlayerAbsX;
	float* mPlayerAbsY;

	//nothing 상태에서 사용되는 멤버 변수
	int mNotingStopCount;
	int mNotingToX;
	int mNotingStartX;

	//명령 수행 시간
	int mOrderCount;

	void changeStat(eStat changeStat, eDirection direction);

	eDirection* mPlayerDirection;

};


