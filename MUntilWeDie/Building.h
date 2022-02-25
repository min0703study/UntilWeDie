#pragma once
#include "GameObject.h"

class Building : public GameObject
{
public:
	enum eStat
	{
		off_1,
		off_2,
		open,
		stand,
		close
	};

	typedef	struct tagAnimation 
	{
		float mFrameUpdateSec;
		float mElapsedSec;

		ImageBase* mCurImage;

		int mPlayCount;

		tagAnimation()
		{
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mCurImage = nullptr;
		}

		void ChangeCurImage(eStat changeStat)
		{
			mPlayCount = 0;
			switch (curDirection)
			{
			case Left:
				switch (changeStat)
				{
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
					break;
				}
				break;
			
			default:
				break;
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
	} Animation;

	Building() {}
	~Building() {}

private:
	eStat mCurStat;
	eStat mPastStat;

	Animation mAni;

	void changeStat(eStat changeStat);
};

