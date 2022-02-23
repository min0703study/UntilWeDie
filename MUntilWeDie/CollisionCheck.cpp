#include "Stdafx.h"
#include "MainGame.h"

void MainGame::collision(void)
{
	for (int i = 0; i < _rocket->getMissile()->getBullet()->size(); i++) {
		for (int j = 0; j < _em->getMinions().size(); j++) {
			RECT rc;
			if (IntersectRect(&rc, &_rocket->getMissile().getBullet()[i].rc,
				&CollisionAreaResizing(_em->getMinions()->[i], 40, 30))
			{
				_rocket->removeMissle(i);
				_em->removeMinion;
				break;
			}
		}
	}
}
