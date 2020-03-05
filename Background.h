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
	void load(const char* path, int w, int h) {
		hdc = CreateCompatibleDC(NULL);
		bmp = (HBITMAP)LoadImageA(NULL, path, NULL, 0, 0, LR_LOADFROMFILE);
		lastbmp = (HBITMAP)SelectObject(hdc, bmp);
		width = w;
		height = h;
	}
	void draw(HDC screen) {
		BitBlt(screen, 0, 0, width, height, hdc, 0, 0, SRCCOPY);
	}
};
#else
#ifdef __APPLE__
#ifdef TARGET_OS_MAC

//Apple computer
#elif TARGET_IPHONE_SIMULATOR

//Apple phone simulator
#elif TARGET_OS_IPHONE

//Apple phone
#else
#ifdef __linux__
#ifndef __ANDROID__

//Linux computer
#else
#ifdef __ANDROID__

//Android
#endif
#endif
#endif
#endif
#endif
#endif