// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MyFlight.h"
#include "EnemyFlight.h"
#include "Background.h"
#include "Bullet.h"


using namespace ege;

int main()
{
	initgraph(WINDOW_WIDTH, WINDOW_HEIGHT);
	mciSendString(L"OPEN ./BMP/BGM.mp3 alias bgm", 0, 0, 0);
	mciSendString(L"play bgm repeat", 0, 0, 0);
	Background backGround;
	MyFlight myFlight;
	std::vector<EnemyFlight*> enemyFlightVec;
	std::vector<Bullet*> bulletVec;
	clock_t timeNow = clock();
	clock_t timePrev = clock();

	while (is_run())
	{
		backGround.reDraw();


		if (EnemyFlight::getCurNum() < MAX_ENEMY_NUM)
		{
			EnemyFlight *enemyFlightTemp = new EnemyFlight;
			enemyFlightVec.push_back(enemyFlightTemp);
		}
		for (int i = 0; i < enemyFlightVec.size(); i++)
		{
			enemyFlightVec[i]->isAttacked(bulletVec);
			if (enemyFlightVec[i]->isEnemyOver())
			{
				delete enemyFlightVec[i];
				enemyFlightVec.erase(enemyFlightVec.begin() + i);
			}
		}
		for (int i = 0; i < enemyFlightVec.size(); i++)
		{
			enemyFlightVec[i]->move();
			enemyFlightVec[i]->reDraw();
		}


		timeNow = clock();
		if (timeNow - timePrev >= 100)
		{
			Bullet *bulletTemp = new Bullet(myFlight);
			bulletVec.push_back(bulletTemp);
			timePrev = timeNow;
		}

		for (int i = 0; i < bulletVec.size(); i++)
		{
			//bulletVec[i]->isBulletHit(enemyFlightVec);
			if (bulletVec[i]->isOver())
			{
				delete bulletVec[i];
				bulletVec.erase(bulletVec.begin() + i);
			}
		}
		for (int i = 0; i < bulletVec.size(); i++)
		{
			bulletVec[i]->move();
			bulletVec[i]->reDraw();
		}

		myFlight.move();
		myFlight.reDraw();

		delay_fps(120);
		cleardevice();
	}
	
	getchar();
	closegraph();
	return 0;
}
