#include "Stdafx.h"
#include "EffectManager.h"

HRESULT EffectManager::init(void)
{
	return S_OK;
}

void EffectManager::addEffect(char* imageKey, float x, float y, int frameY)
{
	Effect* tmpEffect = new Effect;
	tmpEffect->init(imageKey, x, y, frameY);

	mvEffect.push_back(tmpEffect);
}

void EffectManager::update(void)
{
	mviEffect = mvEffect.begin();
	for (; mviEffect != mvEffect.end(); ++mviEffect) {
		(*mviEffect)->update();
	}
	deleteEffect();
}

void EffectManager::release(void)
{
	mviEffect = mvEffect.begin();
	for (; mviEffect != mvEffect.end(); ++mviEffect) {
		(*mviEffect)->release();
		SAFE_DELETE((*mviEffect));
	}
}

void EffectManager::render(void)
{
	mviEffect = mvEffect.begin();
	for (; mviEffect != mvEffect.end(); ++mviEffect) {
		(*mviEffect)->render();
	}
}

void EffectManager::deleteEffect(void)
{
	for (int i = 0; i < mvEffect.size(); i++) {
		if (mvEffect[i]->getIsEnd()) {
			SAFE_DELETE(mvEffect[i]);
			mvEffect.erase(mvEffect.begin() + i);
		}
	}
}
