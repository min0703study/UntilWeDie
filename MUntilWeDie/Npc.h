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
				case eStat::Idle: case eStat::StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcIdleL);
					break;
				case eStat::Walk: case eStat::WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcWalkL);
					break;
				case eStat::Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcRunL);
					break;
				case eStat::Grab:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcGrabL);
					break;
				default:
					//Do Nothing
					break;
				}
				break;
			case eDirection::Right:
				switch (changeStat) {
				case eStat::Idle: case eStat::StopNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcIdleR);
					break;
				case eStat::Walk:case eStat::WalkNoting:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcWalkR);
					break;
				case eStat::Run:
					mCurImage = IMAGEMANAGER->findImage(IMGCLASS->NpcRunR);
					break;
				case eStat::Grab:
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

	//npc �ൿ
	void orderCall(int rank);
	void orderGrap();

	void nothing();

	inline bool isActivated() { return mCurStat == eStat::FollowToPlayer; }

	Npc() {};
	~Npc() {};
private:
	eStat mCurStat;
	eStat mPastStat;
	eDirection mCurDirection;

	Animation mAni;

	int mRank;

	//Player ������
	Player::eStat* mPlayerStat;
	float* mPlayerAbsX;
	float* mPlayerAbsY;

	//nothing ���¿��� ���Ǵ� ��� ����
	int mNotingStopCount;
	int mNotingToX;
	int mNotingStartX;

	//��� ���� �ð�
	int mOrderCount;

	void changeStat(eStat changeStat, eDirection direction);

	eDirection* mPlayerDirection;

};


