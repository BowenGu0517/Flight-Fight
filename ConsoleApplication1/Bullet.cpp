#include "stdafx.h"
#include "Bullet.h"

int Bullet::curNum = 0;

Bullet::Bullet(MyFlight  &myFlight)
{
	this->corXLeft = myFlight.getMyFlightCorX()+20;
	this->corYLeft = myFlight.getMyFlightCorY();
	this->corXRight = myFlight.getMyFlightCorX() + MY_FLIGHT_WIDTH - BULLET_WIDTH - 20;
	this->corYRight = myFlight.getMyFlightCorY();
	bulletImgLeft = ege::newimage(BULLET_WIDTH, BULLET_HEIGHT);
	ege::getimage(bulletImgLeft, "./BMP/ZIDAN_20X35.bmp", 0, 0);
	bulletImgRight = ege::newimage(BULLET_WIDTH, BULLET_HEIGHT);
	ege::getimage(bulletImgRight, "./BMP/ZIDAN_20X35.bmp", 0, 0);
	isHit = false;
	curNum++;
}


Bullet::~Bullet()
{
	cleardevice(bulletImgLeft);
	cleardevice(bulletImgRight);
	ege::delimage(bulletImgLeft);
	ege::delimage(bulletImgRight);
	curNum--;
}

void Bullet::move()
{
	corYLeft -= 5;
	corYRight -= 5;
}

void Bullet::reDraw()
{
	ege::putimage_transparent(NULL, bulletImgLeft, corXLeft, corYLeft, RGB(0, 0, 0), 0, 0, 0, 0);
	ege::putimage_transparent(NULL, bulletImgRight, corXRight, corYRight, RGB(0, 0, 0), 0, 0, 0, 0);
}

bool Bullet::isOver()
{
	if (corYLeft + BULLET_HEIGHT < 0 || isHit)
	{
		return true;
	}
	return false;
}

int Bullet::getCorXLeft()
{
	return corXLeft;
}

int Bullet::getCorXRight()
{
	return corXRight;
}

int Bullet::getCorYLeft()
{
	return corYLeft;
}

int Bullet::getCorYRight()
{
	return corYRight;
}

//void Bullet::isBulletHit(std::vector<EnemyFlight*> enemyFlightVec)
//{
//	for (int i = 0; i < enemyFlightVec.size(); i++)
//	{
//		if (((corXLeft >= enemyFlightVec[i]->getCorX && corXLeft <= enemyFlightVec[i]->getCorX + ENEMY_FLIGHT_WIDTH)
//			&& (corYLeft <= enemyFlightVec[i]->getCorY && corYLeft >= enemyFlightVec[i]->getCorY + ENEMY_FLIGHT_HEIGHT))
//			|| ((corXRight >= enemyFlightVec[i]->getCorX && corXRight <= enemyFlightVec[i]->getCorX + ENEMY_FLIGHT_WIDTH)
//			&& (corYRight <= enemyFlightVec[i]->getCorY && corYRight >= enemyFlightVec[i]->getCorY + ENEMY_FLIGHT_HEIGHT)))
//		{
//			isHit = true;
//			return;
//		}
//	}
//}