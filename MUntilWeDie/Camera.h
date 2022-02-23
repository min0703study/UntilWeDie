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

	inline float GetX() const { return mX; }
	inline float GetY() const { return mY; }

	inline float GetWidth() const { return mWidth; }
	inline float GetHeight() const { return mHeight; }

	inline void OffSetX(int x) { mX += x; };
	inline void OffSetY(int y) { mY += y; };

	Camera() {};
	~Camera() {}
};

