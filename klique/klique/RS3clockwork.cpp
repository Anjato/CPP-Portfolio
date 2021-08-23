#include "RS3clockwork.h"


int RS3clockwork()
{

	ShowConsoleCursor(false);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	bool klique = false;

	int i;
	i = GetKeyState(0x2E); //DELETE


resPos:
	POINT initPos;
	GetCursorPos(&initPos);
	int x2 = initPos.x;
	int y2 = initPos.y;


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
			printf("\33[2KEnabled [RS3 Clockwork Suits]\n\n");
			//	std::cout << "Mouse X: " << x <<  std::endl;
			//	std::cout << "Mouse Y: " << y <<  std::endl;
			printf("\33[2KMouse X: %d\n", x);
			printf("\33[2KMouse Y: %d\n\n", y);


			SetCursorPos(initPos.x, initPos.y);
			mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);
			mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);


			//Sleep(rand() % 40 + 220);
			Sleep(rand() % 40 + 200);


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

	std::cout << "Disabled [RS3 Clockwork Suits]\n" << std::endl;
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