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

	bool isEggRespawn(void); //
	bool isMonsterRespawn(void); //

	MainScene() {};
	~MainScene() {};
private:
	Player* mPlayer;
	MonsterManager* mMonsterMng;
	ImageBase* mTempBkImg; //�ӽ÷� �߰�

	float mEggRespawnTime;
	float mMonsterRespawnTime;
	bool isOn;

	// ����
	PosF respPos;
};

