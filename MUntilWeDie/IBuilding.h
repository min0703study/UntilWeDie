#pragma once
class IBuilding
{
public:
	virtual RECT getBuildingRc() = 0;

	//����
	//enum class eBuildingType { �ǹ� ���� ���� } -> �ǹ� �������� enum ����
	//virtual vector<RECT, eBuildingType> getVectorBuildingRc() = 0; -> �ǹ� ��Ʈ ����
	//virtual attackDamage(int damage) = 0; -> ������ ���� �ٰ�, �� �ǹ� init �Ҷ� hp �������
	//�� ��, ������� �����ϰ�, �������� �׳� �������ٰ� �����ϱ� �ʿ����

	//ä��
	//�ǹ��� player�� �浹�ߴ���?
	//�浹 ������ �ش� index, �ƴϸ� -1 return
	//virtual int isBuildingCollisionToPlayer(RECT playerAbsRc) = 0;
};

