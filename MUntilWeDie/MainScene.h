#pragma once
#include "GameNode.h"
#include "Player.h"
#include "Map.h"

class MainScene: public GameNode
{
public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);

	MainScene() {};
	~MainScene() {};
private:
	Player* mPlayer;
	Map* mMap;
};

