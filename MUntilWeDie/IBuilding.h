#pragma once

class IBuilding
{
public:
	virtual RECT getBuildingRc() = 0;

	//채영
	//건물에 player가 충돌했는지?
	//충돌 했으면 해당 index, 아니면 -1 return
	virtual int isBuildingCollisionToPlayer(RECT playerAbsRc, OUT bool & isSuccessBuild) = 0;

	//채영
	//아이템 돌려주는 소스
	virtual void resetShopItem(int shopType) = 0;

	//채영
	//건물 건설 시작
	//건물 건설 시작하면? 건물 시간만큼 타이머가 돈다.
	//건물 시작 타이머가 완료되면 이미지를 바꿔야 겠지
	//내 npc한테 종료됐다고 사인해줘야 된다.
	//건물 상태 업데이트 (1. 빌딩, 2. npc 안으로 들어감 3. npc한테 삽 제공)
	//virtual bool startBuilding(int buildingIndex, int npcIndex, OUT int& xPos) = 0;

	//지혁
	//enum class eBuildingType { 건물 종류 별로 } -> 건물 종류별로 enum 선언
	//virtual vector<RECT, eBuildingType> getVectorBuildingRc() = 0; -> 건물 렉트 정보
	//virtual attackDamage(int damage) = 0; -> 데미지 내가 줄거, 각 건물 init 할때 hp 만들어줘
	//ㄴ 벽, 발전기는 적당하게, 나머지는 그냥 지나간다고 했으니까 필요없고


};

