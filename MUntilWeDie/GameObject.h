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

	float* getAbsX() { return &mX; };
	float* getAbsY() { return &mY; };

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
	

	float mX;
	float mY;

	RECT mRc;
};

