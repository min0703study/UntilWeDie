#pragma once
#include "GameObject.h"

class Npc: public GameObject
{
public:
	enum eStat {
		Idle,
		Walk,
		Run,
		RunToPlayer,
		DashToPlayer,
		StopToPlayer,
		StopNoting,
		WalkNoting,
		Grab,
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
				case Idle: case StopToPlayer: case StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcIdleL);
					break;
				case Walk: case WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcWalkL);
					break;
				case Run: case RunToPlayer:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcRunL);
					break;
				case Grab:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcGrabL);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			case eDirection::Right:
				switch (changeStat) {
				case Idle: case StopToPlayer: case StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcIdleR);
					break;
				case Walk:case WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcWalkR);
					break;
				case Run: case RunToPlayer:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcRunR);
					break;
				case Grab:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcGrabR);
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

	void init(float * playerAbsX, float * playerAbsY, eDirection * playerDirection, float width, float height);

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
	void orderFollow();
	void orderStop();
	void orderGrap();

	void nothing();


	Npc() {};
	~Npc() {};
private:
	eStat mCurStat;
	eStat mPastStat;

	eDirection mCurDirection;

	Animation mAni;

	int mRank;

	float* mPlayerAbsX;
	float* mPlayerAbsY;

	//nothing 상태에서 사용되는 멤버 변수
	int mNotingStopCount;
	int mNotingToX;
	int mNotingStartX;

	//명령 수행 시간
	int mActiveCount;

	void changeStat(eStat changeStat, eDirection direction);

	eDirection* mPlayerDirection;

};


