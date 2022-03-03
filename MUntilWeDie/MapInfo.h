#pragma once
#define GROUND		800.0f // 나머진 이거 쓰면될듯
#define GROUND_OBJECT 820.0f // 이건 자원만
#define MONSTER_RESPAWN 7729.687f

//맵 길이 46363
namespace MAP{
	namespace POS {
		//자원
		static float MUSHROOM_01_X = 20370; //맵기준
		static float MUSHROOM_02_X = 23220; //맵기준
		static float MUSHROOM_03_X = 26070; //맵기준
		static float MUSHROOM_04_X = 28920; //맵기준
		static float MUSHROOM_05_X = 31770; //맵기준
		static float MUSHROOM_06_X = 34620; //맵기준

		static float OBJECT_GROUND = GROUND_OBJECT; //맵기준 ( 자원 )
		//플레이어 시작 위치
		static float PLAYER_X = 30291.875; //맵기준

		//건물 위치
		//건물-바리케이드
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
		//건물-휴게실
		static float RESTAREA_01_X = 19082.5;
		static float RESTAREA_02_X = 20867.5;
		static float RESTAREA_03_X = 25978.125;
		static float RESTAREA_04_X = 34584.375;
		static float RESTAREA_05_X = 40401.5625;
		//건물-텐트
		static float TENT_01_X = 19632.875;
		static float TENT_02_X = 21675;
		static float TENT_03_X = 27651.5625;
		static float TENT_04_X = 36576.5625;
		//건물-총
		static float GUNBUILDING_X = 33867.1875;
		//건물-삽
		static float SHOVELBUIDLING_X = 31954.6875;
		//건물-렌치
		static float RENCHBUILDING_X = 28846.875;
		//건물-리셋
		static float RESETBUILDING_X = 29165.625;
		//건물-발전기
		static float GENERATOR_X = 30520.3125;

		//공용바닥
		static float COMMONO_GROUND = GROUND; //맵기준 ( 자원 )
	}

	namespace SIZE {
		static float MUSHROOM_W = 233.75; //맵기준
		static float MUSHROOM_H = 87.125; //맵기준

		static int A = 70; //맵기준
		static int PLAYER_Y = 70; //맵기준
	}
}