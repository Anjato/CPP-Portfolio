#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <cstdlib>
#include <ctime>
#include <time.h>

void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}


void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}


int main()
{
	ShowConsoleCursor(false);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bool klique = false;

	int i;
	i = GetKeyState(0x2E); //DEL

	std::string pwd = "ezpz";
	std::string input;


resPos:
	POINT initPos;
	GetCursorPos(&initPos);
	int x2 = initPos.x;
	int y2 = initPos.y;


jKlique:
	if (i == 1)
	{
	loopEnbld:

		klique = true;

		while (klique == true)
		{


			POINT curPos;
			GetCursorPos(&curPos);
			int x = curPos.x;
			int y = curPos.y;

			gotoxy(0, 0);

			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("\33[2KEnabled\n\n");
			//	std::cout << "Mouse X: " << x <<  std::endl;
			//	std::cout << "Mouse Y: " << y <<  std::endl;
			printf("\33[2KMouse X: %d\n", x);
			printf("\33[2KMouse Y: %d\n\n", y);


			// SetCursorPos(initPos.x + rand() % 2-3, initPos.y + rand() % 3-4); for OSRS ArdyKnight
			// SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7); for OSRS Fletching
			// SetCursorPos(initPos.x, initPos.y); for RS3 2t Divination
			SetCursorPos(initPos.x, initPos.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


			// Sleep(rand() % 200 + 70); for ArdyKnight
			// Sleep(rand() % 150 + 40); for Fletching

			Sleep(rand() % 200 + 70);


			if (GetAsyncKeyState(0x2E)) //DEL
			{
				Beep(600, 200);
				system("cls");
				goto capPressed;
			}
		}



	}

	else if (i != 1)

	{

		klique = false;

		goto capPressed;
	}


capPressed:

	POINT p;
	GetCursorPos(&p);
	int x = p.x;
	int y = p.y;

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

	gotoxy(0, 0);

	std::cout << "Disabled\n" << std::endl;
	//	std::cout << "Mouse X: " << x <<  std::endl;
	//	std::cout << "Mouse Y: " << y <<  std::endl;
	printf("\33[2KMouse X: %d\n", x);
	printf("\33[2KMouse Y: %d\n", y);
	printf("Press *INSERT* to reset initPos\n\n");
	printf("Initial Mouse X: %d\n", x2);
	printf("Initial Mouse Y: %d\n", y2);

	klique = false;

	if (GetAsyncKeyState(0x2D))
	{
		Beep(600, 100);
		Beep(600, 100);
		system("cls");
		goto resPos;
	}

	if (GetAsyncKeyState(0x2E))
	{
		Beep(600, 200);
		system("cls");
		goto loopEnbld;
	}
	else
		goto capPressed;


	return 0;

}