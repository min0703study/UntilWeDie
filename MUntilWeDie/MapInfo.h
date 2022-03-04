#pragma once
#define GROUND		800.0f // ������ �̰� ����ɵ� Y��
#define GROUND_OBJECT 820.0f // �̰� �ڿ��� Y��
#define MONSTER_RESPAWN 7729.687f //X��

//�� ���� 46363
namespace MAP{
	namespace POS {
		//�÷��̾� ���� ��ġ
		static float PLAYER_X = 30291.875; //�ʱ���

		static float CAMERA_X = 30291.875 - (1920.0f / 2.0f); //�ʱ���
		static float CAMERA_Y = 0; //�ʱ���

		//�ڿ�
		static float MUSHROOM_01_X = 20370; //�ʱ���
		static float MUSHROOM_02_X = 23220; //�ʱ���
		static float MUSHROOM_03_X = 26070; //�ʱ���
		static float MUSHROOM_04_X = 28920; //�ʱ���
		static float MUSHROOM_05_X = 31770; //�ʱ���
		static float MUSHROOM_06_X = 34620; //�ʱ���

		static float OBJECT_GROUND = GROUND_OBJECT; //�ڿ��� ���

		//�ǹ� ��ġ
		//�ǹ�-�ٸ����̵�
		static float BARRICADE_01_X = 16575;
		static float BARRICADE_02_X = 20187.5;
		static float BARRICADE_03_X = 22391.125;
		static float BARRICADE_04_X = 25419.25;
		static float BARRICADE_05_X = 27076.75;
		static float BARRICADE_06_X = 28368.75;
		static float BARRICADE_07_X = 33179.75;
		static float BARRICADE_08_X = 35277.125;
		static float BARRICADE_09_X = 37453.125;
		static float BARRICADE_10_X = 38728.125;
		static float BARRICADE_11_X = 39684.375;
		static float BARRICADE_12_X = 41157;
		//�ǹ�-�ްԽ�
		static float RESTAREA_01_X = 19082.5;
		static float RESTAREA_02_X = 20867.5;
		static float RESTAREA_03_X = 25978.125;
		static float RESTAREA_04_X = 34584.375;
		static float RESTAREA_05_X = 40401.5625;
		//�ǹ�-��Ʈ
		static float TENT_01_X = 19632.875;
		static float TENT_02_X = 21675;
		static float TENT_03_X = 27651.5625;
		static float TENT_04_X = 36576.5625;
		//�ǹ�-��
		static float GUNBUILDING_X = 33867.1875;
		//�ǹ�-��
		static float SHOVELBUIDLING_X = 31954.6875;
		//�ǹ�-��ġ
		static float RENCHBUILDING_X = 28846.875;
		//�ǹ�-����
		static float RESETBUILDING_X = 29165.625;
		//�ǹ�-������
		static float GENERATOR_X = 30520.3125;
	}

	namespace SIZE {
		static float CAMERA_X = 1920; //�ʱ���
		static float CAMERA_Y = 1080; //�ʱ���

		static float MUSHROOM_W = 233.75; //�ʱ���
		static float MUSHROOM_H = 87.125; //�ʱ���

		static int PLAYER_X = 140; //�ʱ���
		static int PLAYER_Y = 140; //�ʱ���
		static int PLAYER_Y_ACTION = 180; //�ʱ���

		static int NPC_X = 140; //�ʱ���
		static int NPC_Y = 140; //�ʱ���
	}
}