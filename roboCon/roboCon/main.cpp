#include <iostream>
#include "stdafx.h"
#include "ScanContents.h"
#include "functions.h"


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

	bool roboCon = false;

	int i;
	i = GetKeyState(0x14); //Capslock

	POINT initPos;
	GetCursorPos(&initPos);
	int x2 = initPos.x;
	int y2 = initPos.y;



	if (i == 1)
	{

		roboCon = true;

		while (roboCon == true)
		{
			
			
			POINT curPos;
			GetCursorPos(&curPos);
			int x = curPos.x;
			int y = curPos.y;

			gotoxy(0, 0);


			SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
			system("cls");
			printf("\33[2KEnabled\n\n");
			std::cout << "Mouse X: " << x <<  std::endl;
			std::cout << "Mouse Y: " << y <<  std::endl;

			system("pause");

			//initial right click on emtpy table space
			SetCursorPos(initPos.x + rand() % 20, initPos.y + rand() % 10);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

			Sleep(rand() % 400 + 100);

			//left cick
			SetCursorPos(initPos.x + rand() % 15, initPos.y - 150 + rand() % 2);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			Sleep(rand() % 200 + 50);




			//****PLACING TABLE****
			//Keypress
			INPUT ip;

			// Set up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			// Press the "6" key
			ip.ki.wVk = 0x36; // virtual-key code for the "6" key
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the "6" key
			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			SendInput(1, &ip, sizeof(INPUT));



			//second right click on placed table space
			SetCursorPos(initPos.x + rand() % 20, initPos.y + rand() % 10);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

			Sleep(rand() % 400 + 100);

			//left cick
			SetCursorPos(initPos.x + rand() % 15, initPos.y - 150 + rand() % 2);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			Sleep(rand() % 50 + 20);

			//****REMOVING THE TABLE****
			// Set up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			// Press the "1" key
			ip.ki.wVk = 0x31; // virtual-key code for the "1" key
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the "1" key
			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			SendInput(1, &ip, sizeof(INPUT));


			

			//butler returns, second phase
			int funcAim = aim();




			//third right click on empty table space; start of phase 2
			SetCursorPos(initPos.x + rand() % 20, initPos.y + rand() % 10);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

			Sleep(rand() % 400 + 100);

			//left cick
			SetCursorPos(initPos.x + rand() % 15, initPos.y - 150 + rand() % 2);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			Sleep(rand() % 50 + 20);

			
			//fourth right click on empty table space; second of phase 2,  9 emptry inventory spaces
			SetCursorPos(initPos.x + rand() % 20, initPos.y + rand() % 10);
			mouse_event(MOUSEEVENTF_RIGHTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_RIGHTUP, 0, 0, 0, 0);

			Sleep(rand() % 400 + 100);

			//left cick
			SetCursorPos(initPos.x + rand() % 15, initPos.y - 150 + rand() % 2);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);

			Sleep(rand() % 50 + 20);

			//****PLACING TABLE****
			// Set up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			// Press the "6" key
			ip.ki.wVk = 0x36; // virtual-key code for the "6" key
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the "6" key
			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			SendInput(1, &ip, sizeof(INPUT));



			//grab remaining planks from butler, wait, and send him back again with the '1' key for dialoge shortcut
				//int funcaim = aim();

			Sleep(250);

				//int funcaim = aim();


			// Set up a generic keyboard event.
			ip.type = INPUT_KEYBOARD;
			ip.ki.wScan = 0; // hardware scan code for key
			ip.ki.time = 0;
			ip.ki.dwExtraInfo = 0;

			// Press the "1" key
			ip.ki.wVk = 0x31; // virtual-key code for the "1" key
			ip.ki.dwFlags = 0; // 0 for key press
			SendInput(1, &ip, sizeof(INPUT));

			// Release the "1" key
			ip.ki.dwFlags = KEYEVENTF_KEYUP; // KEYEVENTF_KEYUP for key release
			SendInput(1, &ip, sizeof(INPUT));




		}

	}

	while (i!=1)
	{

		std::cout << "Caps Lock DISABLED" << std::endl;
		system("pause");

		if (GetAsyncKeyState(0x14))
		{
			Beep(600, 200);
			main();
		}

	}

}