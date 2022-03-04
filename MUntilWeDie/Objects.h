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

		int mPlayCount;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;
			mPlayCount = 0;

			mDebrisImg[0] = IMAGEMANAGER->findImage(IMGCLASS->Object_Debris);
			mDebrisImg[1] = IMAGEMANAGER->findImage(IMGCLASS->Object_Debris2);

		}

		void frameUpdate(float elapsedTime)
		{
			if (elapsedTime < 0) return;
			mElapsedSec += elapsedTime;

			if (mElapsedSec >= mFrameUpdateSec) {
				mElapsedSec = 0;
				mDebrisImg[RND->getInt(2)]->offsetX(0, false);
				if (mDebrisImg[RND->getInt(2)]->getFrameX() > mDebrisImg[RND->getInt(2)]->getMaxFrameX()) {
					mPlayCount++;
					SAFE_DELETE(mDebrisImg[RND->getInt(2)]);
				}
			}
		}

		inline ImageBase* GetImage() const { return mDebrisImg[RND->getInt(2)]; }
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

	Debris() {};
	~Debris() {};
protected:
	Animation mDebrisAni;
};
