#pragma once

//정호 인터페이스
class IObject
{
public:
	virtual RECT getObjectRc() = 0;

	//자원에 player가 충돌했는지?
	//충돌 했으면 해당 index, 아니면 -1 return
	//만약 충돌하면 깜박거리는 애니메이션 등 넣으면 될듯
	//virtual int isObjectCollisionToPlayer(RECT playerAbsRc) = 0;

	//player 자원 채취 시작 알리는거
	//만약 player 자원 채취 끝나면 isOverGrapObject function 호출해줘
	//virtual bool startGrapObject(int objectIndex, int npcIndex, OUT int& xPos) = 0;

};

