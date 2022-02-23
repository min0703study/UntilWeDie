#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* TempBkImg = "�ӽ� ��� ȭ��";

	const char* PlayerIdle = "�÷��̾� ���� �׼�";

	const char* PlayerWalkR = "�÷��̾� ���������� �ȴ� �׼�";
	const char* PlayerWalkL = "�÷��̾� �������� �ȴ� �׼�";

	const char* PlayerRunL = "�÷��̾� �������� �ٴ� �׼�";
	const char* PlayerRunR = "�÷��̾� ���������� �ٴ� �׼�";

	const char* PlayerCommandCall = "�÷��̾� ȣ�� ���";
	const char* PlayerCommandExec = "�÷��̾� ���� ���";

	HRESULT init(void);
	virtual void release(void);
};

