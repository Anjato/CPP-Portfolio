#define WINVER 0x0500
#include <process.h>
#include <iostream>
#include <Windows.h>
#include <ctime>
#include "functions.h"



class ScanContents
{

public:
	BITMAP Bm;
	RECT RcWindow;
	RGBQUAD * PPixels;

	ScanContents(BITMAP bm, RECT rcWindow, RGBQUAD * pPixels)
	{
		Bm = bm;
		RcWindow = rcWindow;
		PPixels = pPixels;

	}

};



class MouseCoord
{

public:
	int X;
	int Y;
	MouseCoord(int x, int y)
	{
		X = x;
		Y = y;

	}

};


class AimbotThread
{
public:
	HWND AppWnd;
	std::string GameWindow;
	AimbotThread(HWND appWnd, std::string gameWindow)
	{
		AppWnd = appWnd;
		GameWindow = gameWindow;

	}


};