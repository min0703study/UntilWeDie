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

	float getAbsX() { return mX; };
	float getAbsY() { return mY; };

	inline float getX() { return mX - CANERA->getX();};
	inline float getY() { return mY - CANERA->getY();};

	float offsetX(float x) { return mX += x; };
	float offsetY(float y) { return mY += y; };

	GameObject() {};
	virtual ~GameObject() {};
private:
	string mId;
	
	float mWidth;
	float mHeight;

	float mX;
	float mY;
};

