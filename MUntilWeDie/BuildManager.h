#pragma once
#include "GameNode.h"
#include "IBuilding.h"

class ShovelShop;
class engineerShop;
class shopStalkers;
class Generator;
class workbanch;

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

	int isBuildingCollisionToPlayer(RECT playerAbsRc) override;

	BuildManager() {}
	~BuildManager() {}

private:
	ShovelShop* mShovelShop;
	engineerShop* mEngineerShop;
	shopStalkers* mshopStalkers;
	Generator* mGenerator;
	workbanch* mWorkBanch;
};