#pragma once
#include "GameObject.h"
#include "Projectile.h"

class Player;
class IPlayer;

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

enum class eMonsterEffectType
{
	Death,
	Explosion
};

enum class eTargetType
{
	Player,
	NPC,
	Building,
	Generator
};

typedef struct tagTargetInfomation
{
	eTargetType type;
	int arrNum;
} TargetInfo;

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
	int power;
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
	void init(IPlayer* p, eMonsterType type, float posX, float posY, int searchX, int searchY, int attackX, int attackY, int collX, int collY, int imageX, int imageY, int finalX, int finalY);
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
	void addEffect(eMonsterEffectType type);

	float getCurrentHp(void) { return mStatus.currentHp; }
	bool searchTarget(eTargetType type);
	bool attackTarget(eTargetType type);
public:
	IPlayer* getIPlayer() { return mIPlayer; }
	void setIPlayer(IPlayer* p) { if (!mIPlayer) mIPlayer = p; }
	void attackDamage(int damage);
public:
	Monster();
	~Monster();
private:
	vector<RECT> mBuildingAbsRc;
	vector<RECT> mNpcAbsRc;
	vector<float> mNpcAbsX;
	RECT mPlayerAbsRc;
	float mPlayerAbsX;
	IPlayer* mIPlayer;
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
	TargetInfo mTarget;
	bool mbIsTargetOn;

	float mAccrueDistance;
	float mAnimationTime;
	float mAttackCoolTime;
	float mFrameUpdateSec;
	float mElapsedSec;
	float mDeltaTime;

	int mCurrentFrameX;
	int mCurrentFrameY;
	int mAtkStartFrameX;

	bool bIsStop;
	bool bIsMove;
	bool bIsGround;
	bool bIsSuicide;
	bool bInAttackRange;
	bool bIsAttackStart;
	bool bIsAttack;
	bool bIsAttackEnd;
	bool bIsDirLock;
};

