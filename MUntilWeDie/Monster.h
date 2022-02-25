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

enum class eMonsterType
{
	Normal,
	//Shield,
	Suicide,
	Frog,
	Cannon
};

enum class eTargetType
{
	Player,
	NPC,
	Building,
	Generator
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
	PosF search;
	PosF attack;
	float maxHp;
	float currentHp;
	float speed;
} MonStatus;

typedef struct tagEgg
{
	PosF pos;
	int currentStep;
	int maxStep;
} MonEgg;

class Monster :	public GameObject
{
public:
	void init(const char* key, eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int finalX, int finalY);
	void release(void);
	void update(void) {
		move();
		search();
		action();
	};
	void render(void) {
		draw();
		animation();
	};

	void draw();
	void animation();
	void move();
	void search();
	void action();

	Monster();
	~Monster();
private:
	ImageBase* mImage;
	MonStatus mStatus;
	eMonsterType mMonType;
	RECT mSearchRange;
	RECT mAttackRange;
	RECT mCollideRange;

private:
	POINT mFinalTarget;
	eTargetType mTargerType;
	bool mbIsTargetOn;
	//¿¹ºñ
	RECT mPlayerRect;

	int mAnimationTime;
};

