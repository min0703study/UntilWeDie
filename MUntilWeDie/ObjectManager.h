#pragma once
#include "GameNode.h"
#include "Objects.h"
#include "IObject.h"
#include "ItemManager.h"
#include "IPlayer.h"

class ObjectManager : public GameNode, public IObject
{
public:
	HRESULT init(float x, float y, float width, float height);
	void update(void);
	void release(void);
	void render(void);

	RECT getObjectRc() override;

	int isObjectCollisionToPlayer(RECT playerAbsRc);
	int isItemManagerCollisionToPlayer(RECT playerAbsRc);
	bool startGrapObject(int objectIndex, int npcIndex, OUT float& xPos);

	void setIPlayer(IPlayer* iPlayer) { this->mIPlayer = iPlayer; };

	ObjectManager() {};
	~ObjectManager() {};

private:
	vector<Mushroom*> mMushrooms;
	vector<Mushroom*>::iterator mIterMushrooms;

	vector<Debris*> mDebris;
	vector<Debris*>::iterator mIterDebris;

	ItemManager* mItemManager;

	IPlayer* mIPlayer;
	
	int mShroomCount;
	int mDebrisCount;

	bool isMushRoomGrab;
	bool isDebrisGrab;
};

