#pragma once

class IBuilding
{
public:
	virtual RECT getBuildingRc() = 0;

	//ä��
	//�ǹ��� player�� �浹�ߴ���?
	//�浹 ������ �ش� index, �ƴϸ� -1 return
	virtual int isBuildingCollisionToPlayer(RECT playerAbsRc) = 0;

	//ä��
	//������ �����ִ� �ҽ�
	virtual void resetShopItem(int shopType) = 0;

	//ä��
	//�ǹ� �Ǽ� ����
	//�ǹ� �Ǽ� �����ϸ�? �ǹ� �ð���ŭ Ÿ�̸Ӱ� ����.
	//�ǹ� ���� Ÿ�̸Ӱ� �Ϸ�Ǹ� �̹����� �ٲ�� ����
	//�� npc���� ����ƴٰ� ��������� �ȴ�.
	//�ǹ� ���� ������Ʈ (1. ����, 2. npc ������ �� 3. npc���� �� ����)
	//virtual bool startBuilding(int buildingIndex, int npcIndex, OUT int& xPos) = 0;

	//����
	//enum class eBuildingType { �ǹ� ���� ���� } -> �ǹ� �������� enum ����
	//virtual vector<RECT, eBuildingType> getVectorBuildingRc() = 0; -> �ǹ� ��Ʈ ����
	//virtual attackDamage(int damage) = 0; -> ������ ���� �ٰ�, �� �ǹ� init �Ҷ� hp �������
	//�� ��, ������� �����ϰ�, �������� �׳� �������ٰ� �����ϱ� �ʿ����
};

