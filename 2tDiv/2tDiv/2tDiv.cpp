// 2tDiv.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <Windows.h>

using namespace std;

int main()
{
    LPCWSTR window_title = L"Untitled - Paint";
    HWND hWND = FindWindow(NULL, window_title);
    while (true) {
        Sleep(50);
        if (GetAsyncKeyState(VK_NUMPAD0)) {
            Sleep(1000);
            return 0;

        }
        if (GetAsyncKeyState(VK_NUMPAD1)) {//Mouseposition
            POINT p;
            GetCursorPos(&p);
            ScreenToClient(hWND, &p);
            cout << "x-position: " << p.x << " | y-position: " << p.y << endl;
            Sleep(1000);
        }

        if (GetAsyncKeyState(VK_NUMPAD2)) {
            INPUT iNPUT = { 0 };
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
            SendInput(1, &iNPUT, sizeof(iNPUT));
            ZeroMemory(&iNPUT, sizeof(iNPUT));
            iNPUT.type = INPUT_MOUSE;
            iNPUT.mi.dwFlags = MOUSEEVENTF_LEFTUP;
            SendInput(1, &iNPUT, sizeof(iNPUT));


        }
    }

}