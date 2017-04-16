#include "stdafx.h"
#include "EnemyFlight.h"

int EnemyFlight::curNum = 0;

EnemyFlight::EnemyFlight()
{
	unsigned int initX= ege::random(WINDOW_WIDTH - 2 * ENEMY_FLIGHT_WIDTH);
	this->corX = initX;
	this->corY = 0;
	enemyImg = ege::newimage(ENEMY_FLIGHT_WIDTH, ENEMY_FLIGHT_HEIGHT);
	ege::getimage(enemyImg, "./BMP/DIJI_100X100.bmp", 0, 0);
	enemyAttackImg = ege::newimage(ENEMY_FLIGHT_WIDTH, ENEMY_FLIGHT_HEIGHT);
	ege::getimage(enemyAttackImg, "./BMP/Attack_100X100.bmp", 0, 0);
	isOver = false;
	isUnderAttack = false;
	HP=100;
	curNum++;
}


EnemyFlight::~EnemyFlight()
{
	cleardevice(enemyImg);
	ege::delimage(enemyImg);
	cleardevice(enemyAttackImg);
	ege::delimage(enemyAttackImg);
	curNum--;
}

void EnemyFlight::move()
{
	corY++;
}

void EnemyFlight::reDraw()
{
	if (corY < WINDOW_HEIGHT)
	{
		if (!isUnderAttack)
		{
			ege::putimage_transparent(NULL, enemyImg, corX, corY, RGB(0, 0, 0), 0, 0, 0, 0);
		}
		else
		{
			ege::putimage_transparent(NULL, enemyAttackImg, corX, corY, RGB(255, 255, 255), 0, 0, 0, 0);
		}
	}
	else
	{
		isOver = true;
	}
}

int EnemyFlight::getCurNum()
{
	return curNum;
}

bool EnemyFlight::isEnemyOver()
{
	return isOver;
}

ege::PIMAGE EnemyFlight::getEnemyImg()
{
	return enemyImg;
}

void EnemyFlight::isAttacked(std::vector<Bullet*> bulletVec)
{
	for (int i = 0; i < bulletVec.size(); i++)
	{
		if (((bulletVec[i]->getCorXLeft() >= corX+20 && bulletVec[i]->getCorXLeft() <= corX + ENEMY_FLIGHT_WIDTH-30)
			&& (bulletVec[i]->getCorYLeft() <= corY && bulletVec[i]->getCorYLeft() >= corY - ENEMY_FLIGHT_HEIGHT))
			|| ((bulletVec[i]->getCorXRight() >= corX+15 && bulletVec[i]->getCorXRight() <= corX + ENEMY_FLIGHT_WIDTH-20)
			&& (bulletVec[i]->getCorYRight() <= corY && bulletVec[i]->getCorYRight() >= corY - ENEMY_FLIGHT_HEIGHT)))
		{
			HP -= 1;
			isUnderAttack = true;
			if (HP <= 0)
			{
				isOver = true;
			}
			return;
		}
	}
	isUnderAttack = false;
}

int EnemyFlight::getCorX()
{
	return corX;
}

int EnemyFlight::getCorY()
{
	return corY;
}

