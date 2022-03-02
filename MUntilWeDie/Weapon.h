#pragma once
#include "GameObject.h"

typedef struct tagBullet
{
	RECT rc;
	float direction;
	float x, y;
	float fireX, fireY;
};


class Weapon: public GameObject
{
private:
	vector<tagBullet> mVBullet;
	vector<tagBullet>::iterator mViBullet;

	eDirection mDirection;
	bool mIsFire;
	float mShootSpeed;
public:
	HRESULT init(const char* imageName);
	void release(void);
	void update(void);
	void render(void);

	void draw(void);
	void move(void);

	void shoot(float x, float y, eDirection direction);
	void removeBullet(int arrNum);

	Weapon(void) {};
	~Weapon(void) {};
};

