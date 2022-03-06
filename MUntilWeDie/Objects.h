#pragma once
#include "GameObject.h"

class Mushroom : public GameObject
{
public:

	typedef struct tagAnimation {

		float mFrameUpdateSec;
		float mElapsedSec;

		ImageBase* mShroomImg;

		int mPlayCount;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mShroomImg = IMAGEMANAGER->findImage(IMGCLASS->Object_Mushroom);

		}

		void frameUpdate(float elapsedTime)
		{
			if (elapsedTime < 0) return;
			mElapsedSec += elapsedTime;

			if (mElapsedSec >= mFrameUpdateSec) {
				mElapsedSec = 0;
				mShroomImg->offsetX(1, false);
				if (mShroomImg->getFrameX() > mShroomImg->getMaxFrameX()) {
					mPlayCount++;
					SAFE_DELETE(mShroomImg);
				}
			}
		}

		inline ImageBase* GetImage() const { return mShroomImg; }
	}Animation;

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

	bool isStartMushroomGrap;
	bool isEndMushroomGrap;

	int mCount;
	
	float mShroomFrameX;
	float mShroomFrameY;
	float mTime;

	Mushroom() {};
	~Mushroom() {};
protected:
	Animation mShroomAni;
};

class Debris : public GameObject
{
public:

	typedef struct tagAnimation {

		float mFrameUpdateSec;
		float mElapsedSec;

		ImageBase* mDebrisImg[2];
		int mRndIndex;

		int mPlayCount;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mDebrisImg[0] = IMAGEMANAGER->findImage(IMGCLASS->Object_Debris);
			mDebrisImg[1] = IMAGEMANAGER->findImage(IMGCLASS->Object_Debris2);

			mRndIndex = RND->getInt(2);
		}

		void frameUpdate(float elapsedTime)
		{
			if (elapsedTime < 0) return;
			mElapsedSec += elapsedTime;

			if (mElapsedSec >= mFrameUpdateSec) {
				mElapsedSec = 0;
				mDebrisImg[mRndIndex]->offsetX(0, false);
				if (mDebrisImg[mRndIndex]->getFrameX() > mDebrisImg[mRndIndex]->getMaxFrameX()) {
					mPlayCount++;
					SAFE_DELETE(mDebrisImg[mRndIndex]);
				}
			}
		}

		inline ImageBase* GetImage() const { return mDebrisImg[mRndIndex]; }
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

	bool isStartDebrisGrap;
	bool isEndDebrisGrap;

	int mCount;

	float mDebrisFrameX;
	float mDebrisFrameY;
	float mTime;

	Debris() {};
	~Debris() {};
protected:
	Animation mDebrisAni;
};
