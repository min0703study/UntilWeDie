#pragma once

//��ȣ �������̽�
class IObject
{
public:
	virtual RECT getObjectRc() = 0;

	//�ڿ��� player�� �浹�ߴ���?
	//�浹 ������ �ش� index, �ƴϸ� -1 return
	virtual int isObjectCollisionToPlayer(RECT playerAbsRc) = 0;

	//player �ڿ� ä�� ���� �˸��°�
	//���� player �ڿ� ä�� ������ isOverGrapObject function ȣ������

	//�浹�� -> �ش� ��ä�� ���� + �ε��� 
	//Ÿ�̸� ������
	//Ư�� Ÿ�̸Ӹ��� ������ ���/
	//�������� �ִ�ġ���� ������ �̹��� ����
	//�� ���� Ÿ�̸Ӱ� ������ �� ������ Ǫ�ù�
	virtual bool startGrapObject(int objectIndex, int npcIndex, OUT int& xPos) = 0;
};

