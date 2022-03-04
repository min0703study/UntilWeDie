#pragma once
#include "GameObject.h"

class workbanch : public GameObject
{
public:
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

private:
	ImageBase* mImg;
};