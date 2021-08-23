#ifndef main_h
#define main_h

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <MMSystem.h>
#include "DbD.h"
#include "PUBG.h"
#include "WW2.h"


int main();


static void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


#endif