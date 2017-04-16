#pragma once
#include "MyFlight.h"
//#ifndef _ENEMY_FLIGHT_H_
//#define _ENEMY_FLIGHT_H_
//#include "EnemyFlight.h"
//#endif

class Bullet
{
public:
	Bullet(MyFlight &myFlight);
	~Bullet();
	void move();
	void reDraw();
	bool isOver();
	int getCorXLeft();
	int getCorYLeft();
	int getCorXRight();
	int getCorYRight();
	//void isBulletHit(std::vector<EnemyFlight*> enemyFlightVec);

protected:
	int corXLeft;
	int corYLeft;
	int corXRight;
	int corYRight;
	ege::PIMAGE bulletImgLeft;
	ege::PIMAGE bulletImgRight;
	bool isHit;
	static int curNum;
};

