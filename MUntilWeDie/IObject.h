#pragma once
//��ȣ �������̽�
class IObject
{
public:
	virtual RECT getObjectRc() = 0;

	//�ڿ��� player�� �浹�ߴ���?
	//�浹 ������ �ش� index, �ƴϸ� -1 return
	//���� �浹�ϸ� ���ڰŸ��� �ִϸ��̼� �� ������ �ɵ�
	//virtual int isObjectCollisionToPlayer(RECT playerAbsRc) = 0;

	//player �ڿ� ä�� ���� �˸��°�
	//���� player �ڿ� ä�� ������ isOverGrapObject function ȣ������
	//virtual bool startGrapObject(int objectIndex, int npcIndex, OUT int& xPos) = 0;

};

