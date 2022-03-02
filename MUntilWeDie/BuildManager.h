#pragma once
#include "GameNode.h"
#include "IBuilding.h"

class ShovelShop;

struct BuildRect
{
	RECT rc;
	float x, y;
	float width;
	float height;
};

class BuildManager : public GameNode, public IBuilding
{
public:
	HRESULT init(float x, float y, float width, float height);
	void release(void);
	void update(void);
	void render(void);

	//iterface
	RECT getBuildingRc() override;

	BuildManager() {}
	~BuildManager() {}

private:
	ShovelShop* mShovelShop;
};