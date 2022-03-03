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
	int power;
} AttackStatus;

class Projectile : public GameObject
{
public:
	void init(eMonsterType type, eDirection dir, float x, float y, float width, float height, float distance);
	void release(void);
	void update(void);
	void render(void);

	void move(void);
	void draw(void);

	void setSpeedX(float spd) { mSpeedX = spd; }
	void setSpeedY(float spd) { mSpeedY = spd; }

	Projectile() {}
	~Projectile() {}
private:
	ImageBase* mImage;
	AttackStatus mAtkStatus;
	
	float mSpeedX;
	float mSpeedY;
	float mDeltaTime;
};

