#pragma once
#include "GameObject.h"

class Generator : public GameObject
{
public:
	enum class eBuildingType {
		stand,
		open,
		close
	};

	void init(float x, float y, float width, float height);
	void release(void);

	void update(void)
	{
		move();
		action();
	};

	void render(void)
	{
		draw();
		animation();
	};

	void draw();
	void animation();
	void move();
	void action();

	void intoNpc();

	void Monstertrue();

private:
	ImageBase* mImg;

	int mBuildHp;
};