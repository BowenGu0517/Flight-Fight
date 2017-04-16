#pragma once
#include "Flight.h"
class MyFlight :
	public Flight
{
public:
	MyFlight(int corX=(WINDOW_WIDTH-MY_FLIGHT_WIDTH)/2, int corY=(WINDOW_HEIGHT-MY_FLIGHT_HEIGHT-10));
	~MyFlight();
	virtual void move();
	virtual void reDraw();
	int getMyFlightCorX();
	int getMyFlightCorY();
	ege::PIMAGE getMyImg();
	

protected:
	ege::PIMAGE myImg;
};

