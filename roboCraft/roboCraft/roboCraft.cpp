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
				std::cout << "Mouse X: " << x <<  std::endl;
				std::cout << "Mouse Y: " << y <<  std::endl;

				srand(static_cast<unsigned int>(time(0)));

				//Clicks needle
				SetCursorPos(initPos.x + rand() % 10, initPos.y + rand() % 15);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

				Sleep(rand() % 150 + 150);


				//Clicks d'hide body below the needle
				SetCursorPos(initPos.x + rand() % 10, initPos.y + 30 + rand() % 15);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

				Sleep(rand() % 200 + 800);


				//Structure for the keyboard event
				INPUT ip;
				//Setup INPUT structure
				ip.type = INPUT_KEYBOARD;
				ip.ki.time = 0;
				ip.ki.wVk = 0;
				ip.ki.dwExtraInfo = 0;
				//Allows hardware scan rather than a virtual keypress
				ip.ki.dwFlags = KEYEVENTF_SCANCODE;
				ip.ki.wScan = 0x02; //scan code to use; 0x02=1 to select d'hide bodies
				SendInput(1, &ip, sizeof(INPUT)); //sending the key press
				Sleep(25);
				ip.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
				SendInput(1, &ip, sizeof(INPUT)); // sending key de-press


				//Crafting wait time + hover bank
				SetCursorPos(initPos.x - 400 - rand() % 50, initPos.y - 50 - rand() % 100);
				Sleep(rand() % 1000 + 14700);


				//Clicks on bank
				SetCursorPos(initPos.x - 400 - rand() % 50, initPos.y - 50 - rand() % 100);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

				Sleep(rand() % 200 + 1500);


				//Deposit d'hide bodies
				SetCursorPos(initPos.x + rand() % 10, initPos.y + 30 + rand() % 15);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
				Sleep(rand() % 100 + 300);

				SetCursorPos(initPos.x - 35 + rand() % 150, initPos.y + 106 + rand() % 2);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(rand() % 100 + 300);


				//Withdraw top-right corner item
				SetCursorPos(initPos.x - 600 + rand() % 10, initPos.y - 550 - rand() % 5);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);
				Sleep(rand() % 100 + 500);
				
				SetCursorPos(initPos.x - 630 + rand() % 100, initPos.y - 475- rand() % 5);
				Sleep(rand() % 50 + 200);
				mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
				mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);
				Sleep(rand() % 50 + 300);


				//Structure for the keyboard event
				INPUT ip2;
				//Setup INPUT structure
				ip2.type = INPUT_KEYBOARD;
				ip2.ki.time = 0;
				ip2.ki.wVk = 0;
				ip2.ki.dwExtraInfo = 0;
				//Allows hardware scan rather than a virtual keypress
				ip2.ki.dwFlags = KEYEVENTF_SCANCODE;
				ip2.ki.wScan = 0x01; //scan code; 0x01=escape to close bank
				SendInput(1, &ip2, sizeof(INPUT)); //sending the key press
				Sleep(25);
				ip2.ki.dwFlags = KEYEVENTF_SCANCODE | KEYEVENTF_KEYUP;
				SendInput(1, &ip2, sizeof(INPUT)); // sending key de-press

				Sleep(rand() % 100 + 800);


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
				craft = true;
				goto on;
			}

		}
	}
	


    return 0;

}

