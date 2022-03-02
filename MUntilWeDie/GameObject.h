#pragma once
#include "GameNode.h"

class Camera;

class GameObject: public GameNode
{
public:
	void Init(string id, float x, float y, float width, float height);

	virtual void draw(void);
	virtual void animation(void);
	virtual void move(void);
	virtual void action(void);

	float getWidth() { return mWidth; }
	float getHeight() { return mHeight; }

	float getHalfWidth() { return mWidth * 0.5f; }
	float getHalfHeight() { return mHeight * 0.5f; }

	float getCenterX() { return (mX + mWidth * 0.5f) - CAMERA->getX(); }
	float getCenterY() { return (mY + mHeight * 0.5f) - CAMERA->getY(); }

	inline float getAbsX() { return mX; };
	inline float getAbsY() { return mY; };

	float* getAbsPX() { return &mX; };
	float* getAbsPY() { return &mY; };
	
	void setAbsX(float x) { 
		mRc.left = x;
		mRc.right = x + mWidth;
		mX = x;
	};
	void setAbsY(float y) { 
		mY = y; 
		mRc = RectMake(mX, mY, mWidth, mHeight);
	};


	inline float getX() { return mX - CAMERA->getX();};
	inline float getY() { return mY - CAMERA->getY();};

	inline RECT getRc() {
		RECT cRc = CAMERA->getRc();
		return {
			mRc.left - cRc.left,
			mRc.top - cRc.top,
			mRc.right - cRc.left,
			mRc.bottom - cRc.top };
	};

	inline RECT getAbsRc() {
		return mRc;
	};


	RECT getCenterRc() {
		RECT cRc = CAMERA->getRc();
		return 
		{
			(mRc.left - static_cast<int>(mWidth * 0.5f)) - cRc.left,
			(mRc.top - static_cast<int>(mHeight * 0.5f)) - cRc.top,
			(mRc.right - static_cast<int>(mWidth * 0.5f)) - cRc.left,
			(mRc.bottom - static_cast<int>(mHeight * 0.5f)) - cRc.top
		};
	};

	void offsetX(float x) { 
		mRc.left += x;
		mRc.right += x;
		
		mX += x; 
	};

	void offsetY(float y) {
		mRc.left += y;
		mRc.right += y;

		mY += y; 
	};

	GameObject() {};
	virtual ~GameObject() {};
protected:
	float mWidth;
	float mHeight;
private:
	string mId;

	RECT mRc;
	float mX;
	float mY;
};

