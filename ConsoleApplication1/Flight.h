#pragma once

#include "stdafx.h"

class Flight
{
public:
	Flight();
	virtual ~Flight();
	virtual void move() = 0;
	virtual void reDraw() = 0;

protected:
	int corX;
	int corY;
};

