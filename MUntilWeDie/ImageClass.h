#pragma once
#include "SingletonBase.h"

class ImageClass: public SingletonBase<ImageClass>
{
public:
	const char* BgImg = "��� ȭ��";
	const char* BgGrassImg = "��� Ǯ";

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

	const char* Generator_off = "������ ���� ����";
	const char* Generator_01 = "������ 1�ܰ�";


	const char* shovelshop_off = "�� ����ü� ���� ����";
	const char* shovelshop_off_02 = "�� ����ü� ���� ���� �� ����";

	const char* shovelshop_stand = "�� ����ü� �⺻ ����";
	const char* shovelshop_open = "�� ����ü� ����";
	const char* shovelshop_close = "�� ����ü� ���";

	const char* shovelshop_light = "�� ����ü� ����";
	const char* shovelshop_shovel = "��";

	const char* Object_Mushroom = "����";
	const char* Item_shroom = "��������";

	HRESULT init(void);
	virtual void release(void);
};

