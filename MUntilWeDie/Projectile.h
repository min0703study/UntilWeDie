#pragma once
#include "GameObject.h"

enum class eMonsterType;
enum class eDirection;

typedef struct tagProjectile
{
	eMonsterType type;
	eDirection dir;
	float speed;
	float angle;
} AttackStatus;

class Projectile : public GameObject
{
public:
	void init(eMonsterType type, eDirection dir, float x, float y, float width, float height, float distanceX, float distanceY);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);
	void animation(void);

	void setSpeedX(float spd) { mSpeedX = spd; }
	void setSpeedY(float spd) { mSpeedY = spd; }

	Projectile() {}
	~Projectile() {}
private:
	ImageBase* mImage;
	AttackStatus mAtkStatus;
	
	float mGravity;
	float mSpeedX;
	float mSpeedY;
	float mDeltaTime;
	float mFrameUpdateSec;
	float mElapsedSec;
	int mCurrentFrameX;
};

