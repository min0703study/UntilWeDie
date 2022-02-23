#pragma once

#include "SingletonBase.h"
class Camera: public SingletonBase<Camera>
{
private:
	float mWidth;
	float mHeight;

	float mX;
	float mY;

	LPRECT mlpRc;
public:
	HRESULT init(float x, float y, float width, float height);
	void release(void);

	inline float getX() const { return mX; }
	inline float getY() const { return mY; }

	inline float getWidth() const { return mWidth; }
	inline float getHeight() const { return mHeight; }

	inline void offSetX(int x) { mX += x; };
	inline void offSetY(int y) { mY += y; };

	Camera() {};
	~Camera() {}
};

