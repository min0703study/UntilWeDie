#pragma once
#include "GameObject.h"

class Npc;

class Player : public GameObject
{
public:
	enum eStat {
		Idle,
		Walk,
		Run,
		Shoot,
		ShootRun,
		CommandCall,
		CommandExec
	};

	enum eDirection {
		Left,
		Right
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
			case Left:
				switch (changeStat) {
				case Idle:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleL);
					break;
				case Walk:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL);
					break;
				case Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL);
					break;
				case CommandCall:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallL);
					break;
				case CommandExec:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecL);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			case Right:
				switch (changeStat) {
				case Idle:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleR);
					break;
				case Walk:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR);
					break;
				case Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR);
					break;
				case CommandCall:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallR);
					break;
				case CommandExec:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecR);
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

	void init(float x, float y, float width, float height);
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


	Player() {};
	~Player() {};
private:
	eStat mCurStat;
	eStat mPastStat;

	eDirection mCurDirection;

	Animation mAni;

	void changeStat(eStat changeStat);

};

