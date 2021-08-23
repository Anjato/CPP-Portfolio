#include "PUBG.h"

using std::cout;
using std::cin;
using std::endl;



int PUBG( void )
{


	ShowConsoleCursor(false);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);


	int x;

	int y;

	int i;
	i = GetKeyState(0x14); //Capslock


	if (i == 1)


		loopConnect:
	{

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		system("cls");
		system("rasdial hideMeFreeVPN shoxxxy Runescape1");
		system("cls");

		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "Connected!";
		PlaySound("C:\\Windows\\Media\\Speech On.wav", NULL, SND_FILENAME);
		goto capPressed2;
	}

	else if (i != 1)
		loopDisconnect:
	{
		
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

		system("cls");
		system("rasdial /disconnect");	
		system("cls");
		cout << "Disconnected!";
		PlaySound("C:\\Windows\\Media\\Speech Sleep.wav", NULL, SND_FILENAME);
		goto capPressed1;
	}



capPressed1:
	if (GetAsyncKeyState(0x14))
	{
		Beep(600, 200);
		goto loopConnect;
	}
	else
		goto capPressed1;


capPressed2:
	if (GetAsyncKeyState(0x14))
	{
		Beep(600, 200);
		goto loopDisconnect;
	}
	else
		goto capPressed2;


	return 0;

}