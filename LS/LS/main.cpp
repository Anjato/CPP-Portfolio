#include "main.h"
#include <string>


using std::cout;
using std::cin;
using std::endl;




int main()
{


	ShowConsoleCursor(true);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);



start:

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);

	int i;

	system("cls");
	cout << "1 = CoD: WW2" << endl;
	cout << "2 = Dead by Daylight" << endl;
	cout << "3 = PUBG" << endl;
	cin >> i;

	//Fix for dumbasses entering letters
	while (cin.fail())
	{
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("cls");
		cin.clear(); // clear input buffer to restore cin to a usable state
		cin.ignore(INT_MAX, '\n'); // ignore last input
		cout << "You can only enter numbers!" << endl;
		Sleep(1500);
		goto start;
	}



	if (i == 1)
	{
		system("cls");
		int funcWW2 = WW2();
	}

	if (i == 2)
	{
		system("cls");
		int funcDbD = DbD();
	}

	if (i == 3)
	{
		system("cls");
		int funcPUBG = PUBG();
	}

	else
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
		system("cls");
		cout << "Invalid value, please try again." << endl;

		Sleep(1500);

		goto start;


	return 0;
}