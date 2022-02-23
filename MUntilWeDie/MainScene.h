#pragma once
#include "GameNode.h"

class Player;

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
	ImageBase* mTempBkImg; //임시로 추가
	ImageBase* mTempBkImg1; //임시로 추가
};

