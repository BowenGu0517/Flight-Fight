#include "stdafx.h"
#include "Background.h"


Background::Background()
{
	backImg=ege::newimage(WINDOW_WIDTH, WINDOW_HEIGHT);
	ege::getimage(backImg, "./BMP/MAP_100X100.bmp", 0, 0);
}


Background::~Background()
{
	ege::delimage(backImg);
}

void Background::reDraw()
{
	ege::putimage(0, 0, backImg, SRCCOPY);
}


