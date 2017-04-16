#include "stdafx.h"
#include "MyFlight.h"


MyFlight::MyFlight(int corX,int corY)
{
	this->corX = corX;
	this->corY = corY;
	myImg = ege::newimage(MY_FLIGHT_WIDTH,MY_FLIGHT_HEIGHT);
	ege::getimage(myImg, "./BMP/FEIJI_100X100.bmp", 0, 0);

}


MyFlight::~MyFlight()
{
	ege::delimage(myImg);
}

void MyFlight::move()
{
	if (ege::kbmsg)
	{
		if (ege::keystate(ege::key_left) && corX > 0)
		{
			corX--;
		}
		if (ege::keystate(ege::key_right) && corX <WINDOW_WIDTH-MY_FLIGHT_WIDTH)
		{
			corX++;
		}
		if (ege::keystate(ege::key_up) && corY > 0)
		{
			corY--;
		}
		if (ege::keystate(ege::key_down) && corY <WINDOW_HEIGHT-MY_FLIGHT_HEIGHT)
		{
			corY++;
		}
	}
}

void MyFlight::reDraw()
{
	ege::putimage_transparent(NULL, myImg, corX, corY, RGB(0,0,0), 0, 0, 0, 0);
}

ege::PIMAGE MyFlight::getMyImg()
{
	return myImg;
}

int MyFlight::getMyFlightCorX()
{
	return corX;
}

int MyFlight::getMyFlightCorY()
{
	return corY;
}