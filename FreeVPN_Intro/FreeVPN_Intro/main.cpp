#include <iostream>
#include <windows.h>
#include <mmsystem.h>


int main()
{

	int i;
	i = GetKeyState(0x14); //Capslock

	if (i ==1)
		loopConnect:
	{
		system("cls");
		system("rasdial hideMeFreeVPN shoxxxy Runescape1");
		//system("cls");
		//cout << "Connected";
		PlaySound("C:\\Windows\\Media\\Speech On.wav", NULL, SND_FILENAME);
			goto capPressed2;
	}

	else if (i == 0)
		loopDisconnect:
	{
		system("cls");
		system("rasdial /disconnect");
		system("cls");
		//cout << "Disconnected";
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