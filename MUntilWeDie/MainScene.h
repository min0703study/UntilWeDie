#pragma once
#include "GameNode.h"
#include "Player.h"
#include "NPC.h"
#include "Map.h"
#include "BuildManager.h"
#include "NpcManager.h"
#include "Monster.h"
#include "MonsterManager.h"

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
	BuildManager* mBuildManager;
	Map* mMap;
	MonsterManager* mMonsterManager;
	
	float mEggRespawnTime;
	float mMonsterRespawnTime;
	bool isOn;

	// ¿¹ºñ
	PosF respPos;
};

