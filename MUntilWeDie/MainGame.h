#pragma once
#include "GameNode.h"

class MainGame: public GameNode
{
private:
public:
	HRESULT init(void);
	virtual void update(void);
	virtual void release(void);
	virtual void render(void);
};

