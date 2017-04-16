#pragma once
#include "Flight.h"
#include "Bullet.h"

class EnemyFlight :
	public Flight
{
public:
	EnemyFlight();
	~EnemyFlight();
	virtual void move();
	virtual void reDraw();
	ege::PIMAGE getEnemyImg();
	bool isEnemyOver();
	void isAttacked(std::vector<Bullet*> bulletVec);
	static int getCurNum();
	int getCorX();
	int getCorY();
	

protected:
	ege::PIMAGE enemyImg;
	ege::PIMAGE enemyAttackImg;
	bool isOver;
	bool isUnderAttack;
	static int curNum;
	int HP;
};

