#pragma once
#include "GameNode.h"

#include "NpcManager.h"
#include "Player.h"
#include "NPC.h"

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
	ImageBase* mTempBkImg; //�ӽ÷� �߰�
};

