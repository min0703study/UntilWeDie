#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TempBkImg = "�ӽ� ��� ȭ��";

	const char* PlayerIdleR = "�÷��̾� ���� ������ �׼�";
	const char* PlayerIdleL = "�÷��̾� ���� ���� �׼�";
	const char* PlayerWalkR = "�÷��̾� ���������� �ȴ� �׼�";
	const char* PlayerWalkL = "�÷��̾� �������� �ȴ� �׼�";
	const char* PlayerRunL = "�÷��̾� �������� �ٴ� �׼�";
	const char* PlayerRunR = "�÷��̾� ���������� �ٴ� �׼�";
	const char* PlayerCommandCallL = "�÷��̾� �������� ȣ�� ���";
	const char* PlayerCommandCallR = "�÷��̾� ���������� ȣ�� ���";
	const char* PlayerCommandExecL = "�÷��̾� �������� ���� ���";
	const char* PlayerCommandExecR = "�÷��̾� ���������� ���� ���";

	const char* NpcIdleR = "NPC ���� ������ �׼�";
	const char* NpcIdleL = "NPC ���� ���� �׼�";
	const char* NpcWalkR = "NPC ���������� �ȴ� �׼�";
	const char* NpcWalkL = "NPC �������� �ȴ� �׼�";
	const char* NpcRunL = "NPC �������� �ٴ� �׼�";
	const char* NpcRunR = "NPC ���������� �ٴ� �׼�";
	const char* NpcGrabL = "NPC �ݴ� �׼� ����";
	const char* NpcGrabR = "NPC �ݴ� �׼� ������";

	HRESULT init(void);
	virtual void release(void);
};

