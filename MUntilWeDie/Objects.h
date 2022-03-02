#pragma once
#include "GameObject.h"

class Objects : public GameObject
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

	Objects() {};
	~Objects() {};
protected:
	Animation mAni;

};

