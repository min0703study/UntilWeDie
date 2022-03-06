#pragma once
#include "GameNode.h"

class EndScene : public GameNode
{
public:
	HRESULT init(void);
	void update(void);
	void release(void);
	void render(void);
}
