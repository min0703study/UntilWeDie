#pragma once

//정호 인터페이스
class IObject
{
public:
	virtual RECT getObjectRc() = 0;

	//자원에 player가 충돌했는지?
	//충돌 했으면 해당 index, 아니면 -1 return
	virtual int isObjectCollisionToPlayer(RECT playerAbsRc) = 0;

	//player 자원 채취 시작 알리는거
	//만약 player 자원 채취 끝나면 isOverGrapObject function 호출해줘

	//충돌시 -> 해당 객채의 백터 + 인덱스 
	//타이머 돌리기
	//특정 타이머마다 프레임 깍기/
	//프레임이 최대치보다 높을시 이미지 삭제
	//후 일정 타이머가 지날시 재 생성후 푸시백
	virtual bool startGrapObject(int objectIndex, int npcIndex, OUT float& xPos) = 0;

	virtual int isItemManagerCollisionToPlayer(RECT playerAbsRc) = 0;
};

