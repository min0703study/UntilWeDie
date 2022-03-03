#pragma once
#define GROUND		800.0f

//맵 길이 46363
namespace MAP{
	namespace POS {
		//자원
		static float MUSHROOM_01_X = 20370; //맵기준
		static float MUSHROOM_02_X = 22742.375; //맵기준
		static float MUSHROOM_03_X = 25242; //맵기준
		static float MUSHROOM_04_X = 28965.875; //맵기준
		static float MUSHROOM_05_X = 33907.625; //맵기준
		static float MUSHROOM_06_X = 38190; //맵기준

		//플레이어 시작 위치
		static float PLAYER_X = 1100; //맵기준
		static float PLAYER_Y = 500; //맵기준

		//건물 위치


		//공용바닥
		static float OBJECT_GROUND = GROUND; //맵기준
	}

	namespace SIZE {
		static float MUSHROOM_W = 233.75; //맵기준
		static float MUSHROOM_H = 87.125; //맵기준

		static int A = 70; //맵기준
		static int PLAYER_Y = 70; //맵기준
	}
}