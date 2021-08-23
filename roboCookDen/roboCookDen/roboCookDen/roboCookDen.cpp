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

	// This structure will be used to create the keyboard
	// input event.
	INPUT ip;

	// Pause for 5 seconds.
	Sleep(5000);

	// Set up a generic keyboard event.
	ip.type = INPUT_KEYBOARD;
	ip.ki.wScan = 0; // hardware scan code for key
	ip.ki.time = 0;
	ip.ki.dwExtraInfo = 0;


	ShowConsoleCursor(false);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bool rCD = false;

	int v = 0;

	int i;
	i = GetKeyState(0x14); //Capslock



resPos:
	POINT initPos;
	GetCursorPos(&initPos);
	int x2 = initPos.x;
	int y2 = initPos.y;


start:
	if (i == 1)
	{
	loopEnabled:

		rCD = true;

		while (rCD == true)
		{


			POINT curPos;
			GetCursorPos(&curPos);
			int x = curPos.x;
			int y = curPos.y;

			gotoxy(0, 0);

			v++;

			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("\33[2KEnabled\n\n");
			//	std::cout << "Mouse X: " << x <<  std::endl;
			//	std::cout << "Mouse Y: " << y <<  std::endl;
			printf("\33[2KMouse X: %d\n", x);
			printf("\33[2KMouse Y: %d\n\n", y);
			printf("# of Karambwans: ", v);

			

			//Click Karambwan
			SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


			Sleep(rand() % 150 + 40);

			//Click Fire
			SetCursorPos(initPos.x + 40 + rand() % 5, initPos.y + rand() % 9);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


			Sleep(rand() % 180 + 60);


			if (v >= 28)
				goto bank;


			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				goto capPressed;
			}
		}
	}

		else if (i != 1)

		{
			rCD = false;
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

	rCD = false;

	if (GetAsyncKeyState(0x2D))
	{
		Beep(600, 100);
		Beep(600, 100);
		system("cls");
		goto resPos;
	}

	if (GetAsyncKeyState(0x14))
	{
		Beep(600, 200);
		system("cls");
		goto loopEnabled;
	}
	else
		goto capPressed;






bank:

	//click banker guy
	SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	//click deposit inventory
	SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	//right click raw karambwans
	SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

	//left click withdraw all
	SetCursorPos(initPos.x + rand() % 4, initPos.y + rand() % 7);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);



	//close bank

	// Press the "ESC" key
	ip.ki.wVk = 0x1B; // virtual-key code for the "a" key
	ip.ki.dwFlags = 0; // 0 for key press
	SendInput(1, &ip, sizeof(INPUT));

	// Release the "ESC" key
	ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
	SendInput(1, &ip, sizeof(INPUT));


	//check for caps press during the banking process
	if (rCD = true)
		goto loopEnabled;
	else if (rCD = false)
		goto capPressed;



    return 0;

}

