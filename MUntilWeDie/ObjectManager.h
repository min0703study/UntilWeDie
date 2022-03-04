#pragma once
#include "GameNode.h"
#include "Objects.h"
#include "IObject.h"

class ObjectManager : public GameNode, public IObject
{
public:
	HRESULT init(float x, float y, float width, float height);
	void update(void);
	void release(void);
	void render(void);

	RECT getObjectRc() override;

	int isObjectCollisionToPlayer(RECT playerAbsRc);
	bool startGrapObject(int objectIndex, int npcIndex, OUT int& xPos);

	ObjectManager() {};
	~ObjectManager() {};

private:
	vector<Mushroom*> mMushrooms;
	vector<Mushroom*>::iterator mIterMushrooms;

	vector<Debris*> mDebris;
	vector<Debris*>::iterator mIterDebris;
	
	int mShroomCount;
	int mDebrisCount;
};

