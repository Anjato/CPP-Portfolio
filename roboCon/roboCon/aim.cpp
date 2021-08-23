// roboCon.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "ScanContents.h"


bool TakeScreenshot(std::string WindowToFind, BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot,
	HBITMAP & hbitmapOld, HWND &hwnd);


void SetupBitmapInfo(BITMAPINFO &bmi, int bWidth, int bHeight, int bitsPerPixel);
bool CompareColor(RGBQUAD * pPixels, int height, int width, int x, int y);
void ScanBMP(ScanContents * scan);
bool Aim_Bot(HWND appWnd, std::string GameWindow);
bool Aim_BotThread(AimbotThread * aimthr);

MouseCoord CurrentMouseXY(0, 0);


int aim()
{

	std::string GameWindow = "RuneLite";
	//HWND appWnd = FindWindow(_T("MSPaintApp"), NULL); //paint debug testing
	HWND appWnd = FindWindow(_T("SunAwtFrame"), NULL); //OSBuddy

	while (!appWnd)
	{
		system("cls");
		//HWND appWnd = FindWindow(_T("MSPaintApp"), NULL); //Photos debug testing
		HWND appWnd = FindWindow(_T("SunAwtFrame"), NULL); //OSBuddy
		std::cout << "Unable to find " << GameWindow.c_str() << std::endl;
		Sleep(500);
	}

	POINT currentPos;
	GetCursorPos(&currentPos);
	CurrentMouseXY.X = currentPos.x;
	CurrentMouseXY.Y = currentPos.y;

	//int funcSecondary = Secondary();

	AimbotThread aimThr1(appWnd, GameWindow);
	_beginthread((void(*)(void*))Aim_BotThread, 0, (void*)&aimThr1);

	AimbotThread aimThr2(appWnd, GameWindow);
	_beginthread((void(*)(void*))Aim_BotThread, 0, (void*)&aimThr2);

	AimbotThread aimThr3(appWnd, GameWindow);
	_beginthread((void(*)(void*))Aim_BotThread, 0, (void*)&aimThr3);


	Aim_Bot(appWnd, GameWindow);
	system("pause");


	return 0;
}


bool TakeScreenshot(std::string WindowToFind, BITMAP &bm, HBITMAP &hbmap, BITMAPINFO &bmi, HDC &hdcShot,
	HBITMAP & hbitmapOld, HWND &hwnd)
{

	RECT rc;
	GetWindowRect(hwnd, &rc);

	hdcShot = CreateCompatibleDC(0);
	hbmap = CreateCompatibleBitmap(GetDC(0), rc.right - rc.left, rc.bottom - rc.top);
	SelectObject(hdcShot, hbmap);

	BitBlt(hdcShot, 0, 0, rc.right - rc.left, rc.bottom - rc.top, GetDC(0), rc.left, rc.top, SRCCOPY);

	if (!GetObject(hbmap, sizeof(BITMAP), (LPSTR)&bm))
		return false;

	int bitsPerPixel = bm.bmBitsPixel;

	if (bitsPerPixel != 32 || bm.bmPlanes != 1)
		return false;

	SetupBitmapInfo(bmi, bm.bmWidth, bm.bmHeight, bitsPerPixel);
	return true;


}


bool Aim_BotThread(AimbotThread * aimthr)
{

	RECT rcWindow;
	GetWindowRect(aimthr->AppWnd, &rcWindow);
	BITMAP bm;
	HBITMAP hbmap;
	HBITMAP hbmapOld;
	BITMAPINFO bmi;
	HDC hdcShot;
	HDC hdcScreen;

	RGBQUAD * pPixels;

	int TimeTakenScreenAndScan;
	while (true)
	{

		if (!GetAsyncKeyState(0x14))
		{
			TimeTakenScreenAndScan = clock();

			if (!TakeScreenshot(aimthr->GameWindow, bm, hbmap, bmi, hdcShot, hbmapOld, aimthr->AppWnd))
				break;


			HBITMAP hbmapNew = CreateCompatibleBitmap(hdcShot, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top);

			HDC hdcShotNew = CreateCompatibleDC(hdcShot);

			HBITMAP OldBmp = (HBITMAP)SelectObject(hdcShotNew, hbmapNew);

			BitBlt(hdcShotNew, 0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top, hdcShot, 0, 0, SRCCOPY);

			pPixels = new RGBQUAD[bm.bmWidth * bm.bmHeight];
			if (!pPixels)return false;

			SelectObject(hdcShotNew, OldBmp);

			if (!GetDIBits(hdcShotNew, hbmapNew, 0, bm.bmHeight, pPixels, &bmi, DIB_RGB_COLORS))
			{
				ReleaseDC(aimthr->AppWnd, hdcShot);
				delete[] pPixels;
				return false;

			}
			ReleaseDC(aimthr->AppWnd, hdcShot);


			ScanContents scanContentsMain(bm, rcWindow, pPixels);

			ScanBMP(&scanContentsMain);

			if (pPixels)
				free(pPixels);
			SelectObject(hdcShot, hbmapOld);
			DeleteObject(hbmap);
			DeleteDC(hdcShot);
			DeleteObject(hbmapNew);
			DeleteObject(OldBmp);
			DeleteDC(hdcShotNew);
			//std::cout << "Out of scan, took " << clock() - TimeTakenScreenAndScan << "milliseconds." << std::endl;
		}

	}




}


bool Aim_Bot(HWND appWnd, std::string GameWindow)
{

	RECT rcWindow;
	GetWindowRect(appWnd, &rcWindow);
	BITMAP bm;
	HBITMAP hbmap;
	HBITMAP hbmapOld;
	BITMAPINFO bmi;
	HDC hdcShot;
	HDC hdcScreen;

	RGBQUAD * pPixels;

	int TimeTakenScreenAndScan;
	while (true)
	{

		if (!GetAsyncKeyState(0x14))
		{
			TimeTakenScreenAndScan = clock();

			if (!TakeScreenshot(GameWindow, bm, hbmap, bmi, hdcShot, hbmapOld, appWnd))
				break;


			HBITMAP hbmapNew = CreateCompatibleBitmap(hdcShot, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top);

			HDC hdcShotNew = CreateCompatibleDC(hdcShot);

			HBITMAP OldBmp = (HBITMAP)SelectObject(hdcShotNew, hbmapNew);

			BitBlt(hdcShotNew, 0, 0, rcWindow.right - rcWindow.left, rcWindow.bottom - rcWindow.top, hdcShot, 0, 0, SRCCOPY);

			pPixels = new RGBQUAD[bm.bmWidth * bm.bmHeight];
			if (!pPixels)return false;

			SelectObject(hdcShotNew, OldBmp);

			if (!GetDIBits(hdcShotNew, hbmapNew, 0, bm.bmHeight, pPixels, &bmi, DIB_RGB_COLORS))
			{
				ReleaseDC(appWnd, hdcShot);
				delete[] pPixels;
				return false;

			}
			ReleaseDC(appWnd, hdcShot);


			ScanContents scanContentsMain(bm, rcWindow, pPixels);

			ScanBMP(&scanContentsMain);

			if (pPixels)
				free(pPixels);
			SelectObject(hdcShot, hbmapOld);
			DeleteObject(hbmap);
			DeleteDC(hdcShot);
			DeleteObject(hbmapNew);
			DeleteObject(OldBmp);
			DeleteDC(hdcShotNew);
			//std::cout << "Out of scan, took " << clock() - TimeTakenScreenAndScan << "milliseconds." << std::endl;
		}

	}


}

void SetupBitmapInfo(BITMAPINFO &bmi, int bWidth, int bHeight, int bitsPerPixel)
{
	bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biWidth = bWidth;
	bmi.bmiHeader.biHeight = bHeight;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = bitsPerPixel;
	bmi.bmiHeader.biCompression = BI_RGB;
	bmi.bmiHeader.biSizeImage = 0;
}


void ClickBot(int x, int y)
{
	mouse_event(MOUSEEVENTF_LEFTDOWN, x, y, 0, 0);
	mouse_event(MOUSEEVENTF_LEFTUP, x, y, 0, 0);
}


void ScanBMP(ScanContents * scan)
{
	for (int y = (scan->RcWindow.bottom - scan->RcWindow.top) / 4;
		y < ((scan->RcWindow.bottom - scan->RcWindow.top) - (scan->RcWindow.bottom - scan->RcWindow.top) / 3.5);
		y++)

	{
		for (int x = (scan->RcWindow.right - scan->RcWindow.left) / 4;
			x < ((scan->RcWindow.right - scan->RcWindow.left) - (scan->RcWindow.right - scan->RcWindow.left) / 4);
			x++)
		{
			//SetCursorPos(x + scan->RcWindow.left, (y + 4) + scan->RcWindow.top); //use this to test scanning

			if (CompareColor(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, x, y))
			{

				int z = x;
				while (z >(int)((scan->RcWindow.right - scan->RcWindow.left) - (scan->RcWindow.right - scan->RcWindow.left) / 4));
				{

					if (!CompareColor(scan->PPixels, scan->Bm.bmHeight, scan->Bm.bmWidth, z, y))
					{

						break;

					}
					z++;

				}

				SetCursorPos((z - (z - x) / 2) + scan->RcWindow.left, (y + 4) + scan->RcWindow.top);

				POINT currentPos;
				GetCursorPos(&currentPos);


				if (currentPos.x < CurrentMouseXY.X + 3 && currentPos.x > CurrentMouseXY.X - 3 && currentPos.y < CurrentMouseXY.Y + 3 && currentPos.y > CurrentMouseXY.Y - 3)
				{
					ClickBot(x + scan->RcWindow.left, y + scan->RcWindow.top);

					int funcMain = main();

				}


				CurrentMouseXY.X = currentPos.x;
				CurrentMouseXY.Y = currentPos.y;
				return;

			}


		}


	}


}


bool CompareColor(RGBQUAD * pPixels, int height, int width, int x, int y)
{

	int p = (height - y - 1) * width + x;

	//std::cout << (int)pPixels[p].rgbBlue << ", " << (int)pPixels[p].rgbGreen << ", " << (int)pPixels[p].rgbRed << std::endl; //debug pixel color
	//Sleep(10);

	if ((int)pPixels[p].rgbRed == 255 && (int)pPixels[p].rgbGreen == 110 && (int)pPixels[p].rgbBlue == 255)
	{
		//system("pause"); //debugging
		return true;
	}

	if (GetAsyncKeyState(VK_ESCAPE))
	{
		//system("pause"); //debugging
		exit(0);
	}
	return false;
}