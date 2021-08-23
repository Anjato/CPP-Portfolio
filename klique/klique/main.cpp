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
	cout << "1 = OSRS Fletching" << endl;
	cout << "2 = RS3 Clockwork Suits" << endl;
	cout << "3 = RS3 2t Divination" << endl;
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
		int funcOSfletch = OSfletch();
	}

	if (i == 2)
	{
		system("cls");
		int funcRS3clockwork = RS3clockwork();
	}

	if (i == 3)
	{
		system("cls");
		int funcRS32tDiv = RS32tDiv();
	}

	else
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	system("cls");
	cout << "Invalid value, please try again." << endl;

	Sleep(1500);

	goto start;


	return 0;
}