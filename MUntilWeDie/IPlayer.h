#pragma once
class IPlayer
{
public:
	virtual RECT getPlayerRc() = 0;

	//�ڿ� - �ڿ� ������ ������ ȣ������
	virtual void isOverGrapObject(int npcIndex) = 0;
};

