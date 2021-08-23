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

	bool craft;



resPos:
	POINT initPos;
	GetCursorPos(&initPos);
	int x2 = initPos.x;
	int y2 = initPos.y;


	int i;
	i = GetKeyState(0x14); //Capslock


	if (i == 1)
	{
	on:
		craft = true;

		while (craft == true)

		{
			POINT curPos;
			GetCursorPos(&curPos);
			int x = curPos.x;
			int y = curPos.y;

			gotoxy(0, 0);

			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			printf("\33[2KEnabled\n\n");
			std::cout << "Mouse X: " << x << std::endl;
			std::cout << "Mouse Y: " << y << std::endl;

			srand(static_cast<unsigned int>(time(0)));

			//Clicks where initial position is selected (using insert key)
			SetCursorPos(initPos.x + rand() % 10, initPos.y + rand() % 15);
			Sleep(rand() % 50 + 200);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			Sleep(rand() % 80 + 1450);


			//Structure for the keyboard event
			INPUT ip;
			//Setup INPUT structure
			ip.type = INPUT_KEYBOARD;
			ip.ki.time = 0;
			ip.ki.wVk = 0;
			ip.ki.dwExtraInfo = 0;
			//Allows hardware scan rather than a virtual keypress
			ip.ki.dwFlags = KEYEVENTF_SCANCODE;
			ip.ki.wScan = 0x3E; //scan code for F4 on keyboard; grabs 4th quick slot in bank
			SendInput(1, &ip, sizeof(INPUT)); //sending the key press
			Sleep(25);
			ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT)); // sending key de-press

			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				goto off;
			}

			Sleep(rand() % 60 + 1300);

			
			//Allows hardware scan rather than a virtual keypress
			ip.ki.dwFlags = KEYEVENTF_SCANCODE;
			ip.ki.wScan = 0x02; //scan code for 1 on keyboard; selects uncut gem on the #1 keybind on the hotbar
			SendInput(1, &ip, sizeof(INPUT)); //sending the key press
			Sleep(25);
			ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT)); // sending key de-press

			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				goto off;
			}

			Sleep(rand() % 70 + 1330);



			//Allows hardware scan rather than a virtual keypress
			ip.ki.dwFlags = KEYEVENTF_SCANCODE;
			ip.ki.wScan = 0x39; //scan code for spacebar on keyboard; accepts cutting gems
			SendInput(1, &ip, sizeof(INPUT)); //sending the key press
			Sleep(25);
			ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
			SendInput(1, &ip, sizeof(INPUT)); // sending key de-press

			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				goto off;
			}

			Sleep(rand() % 100 + 18100);




			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				goto off;
			}

		}

	}

	if (i != 1)
	{
	off:
		craft = false;

		while (craft == false)
		{

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

			if (GetAsyncKeyState(0x2D)) //Insert
			{
				Beep(600, 100);
				Beep(600, 100);
				system("cls");
				goto resPos;
			}

			if (GetAsyncKeyState(0x14)) //Capslock
			{
				Beep(600, 200);
				system("cls");
				craft = true;
				goto on;
			}

		}
	}



	return 0;
}