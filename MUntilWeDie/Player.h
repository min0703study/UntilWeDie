#pragma once
#include "GameObject.h"

class NpcManager;
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
	};

	typedef	struct tagAnimation {

		float mFrameUpdateSec;	// �ʴ� ������ ������Ʈ ��
		float mElapsedSec;		// �����Ӱ� ������ ������ �ð�

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
				case eStat::Idle:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleL);
					break;
				case eStat::Walk:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkL);
					break;
				case eStat::Run: case eStat::Dash:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunL);
					break;
				case eStat::CommandCall:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallL);
					break;
				case eStat::CommandExec:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecL);
					break;
				case eStat::Shoot:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerShootL);
					break;
				case eStat::ShootRun:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootL);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			case eDirection::Right:
				switch (changeStat) {
				case eStat::Idle:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerIdleR);
					break;
				case eStat::Walk:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerWalkR);
					break;
				case eStat::Run: case eStat::Dash:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunR);
					break;
				case eStat::CommandCall:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandCallR);
					break;
				case eStat::CommandExec:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerCommandExecR);
					break;
				case eStat::Shoot:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerShootR);
					break;
				case eStat::ShootRun:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->PlayerRunShootR);
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

	float mDashTime;
	float mHp;

	void changeStat(eStat changeStat);
	
	void orderCallNpc();
	void orderExcuteNpc();

};

