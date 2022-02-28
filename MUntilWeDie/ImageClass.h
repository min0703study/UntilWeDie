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
	const char* PlayerShootL = "�÷��̾� �������� ����";
	const char* PlayerShootR = "�÷��̾� ���������� ����";
	const char* PlayerRunShootL = "�÷��̾� �ٸ鼭 �������� ����";
	const char* PlayerRunShootR = "�÷��̾� �ٸ鼭 ���������� ����";

	const char* CivilianIdleR = "�ΰ��� ���� ������ �׼�";
	const char* CivilianIdleL = "�ΰ��� ���� ���� �׼�";
	const char* CivilianWalkR = "�ΰ��� ���������� �ȴ� �׼�";
	const char* CivilianWalkL = "�ΰ��� �������� �ȴ� �׼�";
	const char* CivilianRunL = "�ΰ��� �������� �ٴ� �׼�";
	const char* CivilianRunR = "�ΰ��� ���������� �ٴ� �׼�";
	const char* CivilianGrabL = "�ΰ��� �ݴ� �׼� ����";
	const char* CivilianGrabR = "�ΰ��� �ݴ� �׼� ������";
	const char* CivilianBuildL = "�ΰ��� �ǹ� ���� ����";
	const char* CivilianBuildR = "�ΰ��� �ǹ� ���� ������";

	const char* DiggerIdleR = "�� NPC ���� ������ �׼�";
	const char* DiggerIdleL = "�� NPC ���� ���� �׼�";
	const char* DiggerWalkR = "�� NPC ���������� �ȴ� �׼�";
	const char* DiggerWalkL = "�� NPC �������� �ȴ� �׼�";
	const char* DiggerRunL = "�� NPC �������� �ٴ� �׼�";
	const char* DiggerRunR = "�� NPC ���������� �ٴ� �׼�";
	const char* DiggerGrabL = "�� NPC �ݴ� �׼� ����";
	const char* DiggerGrabR = "�� NPC �ݴ� �׼� ������";

	const char* EngineerIdleR = "�����Ͼ� NPC ���� ������ �׼�";
	const char* EngineerIdleL = "�����Ͼ� NPC ���� ���� �׼�";
	const char* EngineerWalkR = "�����Ͼ� NPC ���������� �ȴ� �׼�";
	const char* EngineerWalkL = "�����Ͼ� NPC �������� �ȴ� �׼�";
	const char* EngineerRunL = "�����Ͼ� NPC �������� �ٴ� �׼�";
	const char* EngineerRunR = "�����Ͼ� NPC ���������� �ٴ� �׼�";

	HRESULT init(void);
	virtual void release(void);
};

