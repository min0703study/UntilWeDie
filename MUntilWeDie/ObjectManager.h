#pragma once
#include "GameNode.h"
#include "Objects.h"

class ObjectManager : public GameNode
{
public:
	HRESULT init(float x, float y, float width, float height);
	void update(void);
	void release(void);
	void render(void);

	ObjectManager() {};
	~ObjectManager() {};

private:
	vector<Objects*> mObjects;
	vector<Objects*>::iterator mIterObjects;
	
	int mShroomCount;
};

