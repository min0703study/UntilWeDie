#pragma once
#include "GameNode.h"

struct BuildRect
{
	RECT rc;
	float x, y;
	float width;
	float height;
};

class BuildManager : public GameNode
{
public:
	HRESULT init(float x, float y, float width, float height);
	void release(void);
	void update(void);
	void render(void);

	BuildManager() {}
	~BuildManager() {}
};