#pragma once
#include "GameObject.h"

enum class eDirection
{
	LEFT,
	RIGHT
};

enum class eMonsterState
{
	Idle,
	Walk,
	Attack,
	Death,
	Fall
};

typedef struct tagPointToFloat
{
	float x;
	float y;
} PtF, PosF;

typedef struct tagMonsterStatus
{
	PosF pos;
	PosF size;
	float maxHp;
	float currentHp;
	float speed;
} MonStatus;

class Monster :	public GameObject
{
public:
	void init(float x, float y, float width, float height);
	void release(void);
	void update(void) {
		move();
		action();
	};
	void render(void) {
		draw();
		animation();
	};

	void draw();
	void animation();
	void move();
	void action();

	Monster();
	~Monster();
private:
	Image* mImage;
	MonStatus mStatus;
};

