#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Player;

enum class eDirection
{
	Left,
	Right
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
	float moveSpeed;
	float attackSpeed;
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
	void init(eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int imageX, int imageY, int finalX, int finalY);
	void release(void);
	void update(void);
	void render(void);

	void move();
	void search();
	void action();
	void attack();

	void animation();
	void draw();

	void changeAnimation(void);
	void deleteAttack(void);
	void addEffect(void);

	float getCurrentHp(void) { return mStatus.currentHp; }

	Monster();
	~Monster();
public:
	// 예비
	void getPlayerRef(Player* p) { mPlayer = p; }
private:
	//예비
	Player* mPlayer;
private:
	Projectile* mAttack;
	ImageBase* mImage;
	eMonsterType mMonType;
	eMonsterState mMonPrevState;
	eMonsterState mMonCurrState;
	eDirection mMonPrevDir;
	eDirection mMonCurrDir;
	MonStatus mStatus;
	RECT mSearchRange;
	RECT mAttackRange;
	RECT mCollideRange;
	int mImageX;
	int mImageY;
private:
	POINT mFinalTarget;
	eTargetType mTargetType;
	bool mbIsTargetOn;

	float mAccrueDistance;
	float mAnimationTime;
	float mAttackCoolTime;
	int mCurrFrameX;
	int mCurrFrameY;

	bool bIsStop;
	bool bIsMove;
	bool bIsAttack;
	bool bIsGround;
	bool bIsSuicide;
	bool bIsAttackEnd;
};

