#ifndef main_h
#define main_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <MMSystem.h>
#include <random> //deviation
#include <string> //deviation
#include "OSfletch.h"
#include "RS3clockwork.h"
#include "RS32tDiv.h"


using namespace std;

int main();


static void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


static void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

#endif