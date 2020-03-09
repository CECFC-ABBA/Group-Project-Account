/*
 * Author: Alexander Marsh
 * Last Edit Date: 10/8/2019
 * Usage: Provides an easy-to-use way to update an Window object that allows you to do this without knowledge of WINAPI, etc.
 * ~~Change Log~~
 * Oct. 8, 2019 - Completed basic windows support.
 */
#pragma once
#include "STD.h"
#ifdef _WIN32
void paintRoutine(HDC painting_DC, HWND hWnd);
void startMethod();
void eraseMethod();
void destructionMethod(HWND hWnd);
void invalidWindowMethod();
void moveMethod();
void charPressMethod(WPARAM wParam);
void resizeMethod();
void windowDisplayMethod();
void leftMouseClickMethod();
void rightMouseClickMethod();
void defaultMethod();
void drawBack(HDC painting_DC);
#define onPaint() void paintRoutine(HDC painting_DC, HWND hWnd)
#define get_DC() painting_DC
#define onStart() void startMethod()
#define onErase() void eraseMethod()
#define onClose() void destructionMethod(HWND hWnd)
#define ifInvalidWindow() void invalidWindowMethod()
#define onMove() void moveMethod()
#define onCharPress() void charPressMethod(WPARAM wParam)
#define GetCharPressed() wParam
#define onResize() void resizeMethod()
#define onShow() void windowDisplayMethod()
#define onLClick() void leftMouseClickMethod()
#define onRClick() void rightMouseClickMethod()
#define onNothing() void defaultMethod()
#define drawBackground() void drawBack(HDC painting_DC)
#define get_WND() hWnd
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam) {
	HDC painting_DC;
	switch (message) {
	case WM_CHAR:
		charPressMethod(wParam);
		break;
	case WM_CREATE:
		startMethod();
		break;
	case WM_CLOSE:
		exit(1);
		break;
	case WM_QUIT:
	case WM_DESTROY:
		destructionMethod(hWnd);
		break;
	case WM_ERASEBKGND:
		eraseMethod();
		break;
	case WM_LBUTTONDOWN:
		leftMouseClickMethod();
		break;
	case WM_RBUTTONDOWN:
		rightMouseClickMethod();
		break;
	case WM_MOVE:
		moveMethod();
		break;
	case WM_NULL:
		invalidWindowMethod();
		break;
	case WM_PAINT:
		PAINTSTRUCT ps;
		painting_DC = BeginPaint(hWnd, &ps);
		InvalidateRect(hWnd, 0, true);//clear screen WITHOUT FLASHING...
		drawBack(painting_DC);
		paintRoutine(painting_DC, hWnd);
		EndPaint(hWnd, &ps);
		break;
	case WM_SHOWWINDOW:
		windowDisplayMethod();
		break;
	case WM_SIZE:
		resizeMethod();
		break;
	default:
		defaultMethod();
	}
	return DefWindowProc(hWnd, message, wParam, lParam);
}
#endif
