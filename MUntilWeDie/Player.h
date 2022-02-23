#pragma once
#include "GameObject.h"

class Player : public GameObject
{
public:

	enum eStat {
		Idle,
		WalkR,
		WalkL,
		RunR,
		RunL,
		ShootR,
		ShootL,
		ShootRun,
		CommandCall,
		CommandExec
	};

	typedef	struct tagAnimation {

		unordered_map<eStat, ImageBase*> mImageList;
		unordered_map<eStat, ImageBase*>::iterator mItImageList;

		float mFrameUpdateSec;	// �ʴ� ������ ������Ʈ ��
		float mElapsedSec;		// �����Ӱ� ������ ������ �ð�

		ImageBase* mCurImage;

		tagAnimation() {
			mFrameUpdateSec = 1.0f / 10;
			mElapsedSec = 0;

			mCurImage = nullptr;
		}

		void SetStatImage(eStat stat, ImageBase* image) {
			mImageList.insert(make_pair(stat, image));
		}

		void ChangeCurImage(eStat changeStat) {
			auto itFindImage = mImageList.find(changeStat);
			
			if (itFindImage != mImageList.end())
			{
				mCurImage = itFindImage->second;
			}
		}

		void frameUpdate(float elapsedTime)
		{
			if (elapsedTime < 0) return;
			mElapsedSec += elapsedTime;

			if (mElapsedSec >= mFrameUpdateSec) {
				mElapsedSec = 0;
				mCurImage->offsetX(1, true);
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
	Animation mAni;

	void changeStat(eStat changeStat);

};

