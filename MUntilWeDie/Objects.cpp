#include "Stdafx.h"
#include "Objects.h"

void Objects::init(float x, float y, float width, float height)
{
	GameObject::Init("Objects", x, y, width, height);

}

void Objects::release(void)
{
}

void Objects::draw()
{
	RectangleMake(getMemDc(), getRc());
	mAni.GetImage()->frameRender(getMemDc(), getX(), getY());
}

void Objects::animation()
{
}

void Objects::move()
{
}


void Objects::action()
{
}
