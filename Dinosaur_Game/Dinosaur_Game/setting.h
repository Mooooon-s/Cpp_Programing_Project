#pragma once
const int KEY_ESC = 27;			// ESC 키
const int KEY_SPACE = 32;		// SpaceBar 키

const int MAX_JUMP = 6;			// 최대 점프 높이
const int Y_BASE = 11 ;			// 공룡의 초기 Y축 위치
const int Y_COLLISION = 4;		// Y축의 충돌 기준 위치
const int TREE_COLLISION = 7;	// 나무가 공룡과 충돌 가능한 X축 위치
const int TREE_START = 50;		// 나무가 생성되는 위치
const int TREE_END = -6;		// 나무가 사라지는 위치
const int SLEEP_TIME = 35;		// 게임 갱신 주기
const int TREE_BOTTOM_Y = 20;	//나무의 초기 Y축 위치