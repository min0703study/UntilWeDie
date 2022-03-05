#pragma once
#include "SingletonBase.h"
#include "Effect.h"

class EffectManager : public SingletonBase<EffectManager>
{
public:
	HRESULT init(void);
	void addEffect(char* key, float x, float y, int frameY);
	void update(void);
	void release(void);
	void render(void);

	void deleteEffect(void);
private:
	vector<Effect*> mvEffect;
	vector<Effect*>::iterator mviEffect;
};

