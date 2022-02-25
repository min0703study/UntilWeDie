#pragma once
#include "GameNode.h"
#include "Monster.h"

class Player;
class MonsterManager;

class MainScene: public GameNode
{
public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);

	bool isEggRespawn(void);
	bool isMonsterRespawn(void);

	MainScene() {};
	~MainScene() {};
private:
	Player* mPlayer;
	MonsterManager* mMonsterMng;
	ImageBase* mTempBkImg; //임시로 추가

	float mEggRespawnTime;
	float mMonsterRespawnTime;

	// 예비
	PosF respPos;
};

