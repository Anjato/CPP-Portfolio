#include "DbD.h"

using std::cout;
using std::cin;
using std::endl;

int DbD()
{

	ShowConsoleCursor(false);


	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	int x;


	int i;
	//CapsLock
	i = GetKeyState(0x14);

	//Enabled
	if (i == 1)

	{
	On:

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "Loading Dead by Daylight switch..." << endl;
		system("powershell New-NetQosPolicy -Name DbD -AppPathNameMatchCondition Steam.exe -ThrottleRateActionBitsPerSecond 200000");
		system("cls");

		SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "DbD Lag [On]" << endl;

		PlaySound("C:\\Windows\\Media\\Speech On.wav", NULL, SND_FILENAME);

		//Disabled
		if (i == 0)
			goto Off;

		else if (i == 1)
			goto KeyPressOn;

	}
	else
	{
	Off:
		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

		cout << "Loading Dead by Daylight switch..." << endl;;
		system("powershell Remove-NetQosPolicy -Name DbD -confirm:$false");
		system("cls");

		SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

		cout << "DbD Lag [Off]";
		//cin >> x;

		//if (x == 0);
		//int funcMain = main();

		PlaySound("C:\\Windows\\Media\\Speech Sleep.wav", NULL, SND_FILENAME);

		if (i == 1)
			goto On;

		else if (i == 0)
			goto KeyPressOff;
	}


KeyPressOn:
	//CapsLock Pressed
	if (GetAsyncKeyState(0x14))
	{
		Beep(600, 200);
		goto Off2;
	}
	else
		goto KeyPressOn;


KeyPressOff:

	if (GetAsyncKeyState(0x14))
	{
		Beep(600, 200);
		goto On2;
	}
	else
		goto KeyPressOff;



On2:
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	system("powershell New-NetQosPolicy -Name DbD -AppPathNameMatchCondition Steam.exe -ThrottleRateActionBitsPerSecond 200000");
	system("cls");

	SetConsoleTextAttribute(hStdOut, FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	cout << "DbD Lag [On]" << endl;

	PlaySound("C:\\Windows\\Media\\Speech On.wav", NULL, SND_FILENAME);

	goto KeyPressOn;


Off2:
	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);

	system("powershell Remove-NetQosPolicy -Name DbD -confirm:$false");
	system("cls");

	SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | FOREGROUND_INTENSITY);

	cout << "DbD Lag [Off]" << endl;

	PlaySound("C:\\Windows\\Media\\Speech Sleep.wav", NULL, SND_FILENAME);

	goto KeyPressOff;


	return 0;

}