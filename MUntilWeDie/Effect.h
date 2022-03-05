#pragma once
#include "GameObject.h"

class Effect : public GameObject
{
public:
	void init(char* imageKey, float x, float y, int frameY);
	void update(void);
	void release(void);
	void render(void);

	void draw(void);
	void animation(void);

	bool getIsEnd(void) { return mbIsEnd; }

	Effect() {}
	~Effect() {}
private:
	ImageBase* mImage;
	float mFrameUpdateSec;
	float mElapsedSec;
	int mPlayCount;
	int mCurrentFrameX;
	int mCurrentFrameY;
	bool mbIsEnd;
};

