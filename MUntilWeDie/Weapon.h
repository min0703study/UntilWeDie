#pragma once
#include "GameObject.h"

typedef struct tagBullet
{
	RECT rc;
	RECT absRc;
	float direction;
	float x, y;
	float fireX, fireY;
	float absX, absY;
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
	void attackSuccess();
	void removeBullet(int arrNum);

	vector<tagBullet> getBullets() { return mVBullet; };

	Weapon(void) {};
	~Weapon(void) {};
};

