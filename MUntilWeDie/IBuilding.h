#pragma once
class IBuilding
{
public:
	virtual RECT getBuildingRc() = 0;

	//지혁
	//enum class eBuildingType { 건물 종류 별로 } -> 건물 종류별로 enum 선언
	//virtual vector<RECT, eBuildingType> getVectorBuildingRc() = 0; -> 건물 렉트 정보
	//virtual attackDamage(int damage) = 0; -> 데미지 내가 줄거, 각 건물 init 할때 hp 만들어줘
	//ㄴ 벽, 발전기는 적당하게, 나머지는 그냥 지나간다고 했으니까 필요없고
};

