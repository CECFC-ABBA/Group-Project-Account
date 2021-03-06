/*
 * Author: Alexander Marsh
 * Last Edit Date: 10/8/2019
 * Usage: Provides a background class that allows you to set window backgrounds easily
 * ~~Change Log~~
 * Oct. 8, 2019 - Completed basic windows support.
 */
#pragma once
#ifdef _WIN32
#include "STD.h"
class Background {
protected:
	HDC hdc;
	HBITMAP bmp;
	HBITMAP lastbmp;
	int width;
	int height;
public:
	void load(const char* path, int w, int h, HINSTANCE hInst) {
		hdc = CreateCompatibleDC(0);
		//bmp = LoadBitmap(NULL, path);
		bmp = (HBITMAP)LoadImageA(NULL, path, IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
		lastbmp = (HBITMAP)SelectObject(hdc, bmp);
		width = w;
		height = h;
	}
	void draw(HDC screen, int x, int y) {
		BitBlt(screen, x, y, width, height, hdc, 0, 0, SRCCOPY);
	}
};
#endif
