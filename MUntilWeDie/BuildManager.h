#pragma once
#include "GameNode.h"
#include "IBuilding.h"

class ShovelShop;
class engineerShop;
class ShopStalkers;
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
	enum eBuildType {
		tShovelShop,
		tEngineerShop,
		tShopStalkers,
		tGenerator,
		tWorkbanch,
		tNothing
	};

	HRESULT init(float x, float y, float width, float height);
	void release(void);
	void update(void);
	void render(void);

	//iterface
	RECT getBuildingRc() override;

	int isBuildingCollisionToPlayer(RECT playerAbsRc, OUT bool & isSuccessBuild);

	void resetShopItem(int shopType) override;

	BuildManager() {}
	~BuildManager() {}

private:
	ShovelShop* mShovelShop;
	engineerShop* mEngineerShop;
	ShopStalkers* mShopStalkers;
	Generator* mGenerator;
	workbanch* mWorkBanch;
};