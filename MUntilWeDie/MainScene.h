#pragma once
#include "GameNode.h"
#include "BuildManager.h"
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#include "MonsterManager.h"

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
	BuildManager* mBuildManager;
	Map* mMap;
	MonsterManager* mMonsterMng;
	
	float mEggRespawnTime;
	float mMonsterRespawnTime;
	bool isOn;

	// ����
	PosF respPos;
};

