/*
 * Author: Alexander Marsh
 * Last Edit Date: 10/8/2019
 * Usage: Provides a Window class that allows you to create windows easily, and allows updates via "WndProc.h"
 * ~~Change Log~~
 * Oct. 8, 2019 - Completed basic windows support.
 */
#pragma once
#ifdef _WIN32
#ifdef onPaint()
#undef onPaint()
#undef _GUI_NERROR
#define _GUI_ERROR 1
#endif
#ifdef get_DC()
#undef get_DC()
#undef _GUI_NERROR
#define _GUI_ERROR 2
#endif
#ifdef onStart()
#undef onStart()
#undef _GUI_NERROR
#define _GUI_ERROR 3
#endif
#ifdef onErase()
#undef onErase()
#undef _GUI_NERROR
#define _GUI_ERROR 4
#endif
#ifdef onClose()
#undef onClose()
#undef _GUI_NERROR
#define _GUI_ERROR 5
#endif
#ifdef ifInvalidWindow()
#undef ifInvalidWindow()
#undef _GUI_NERROR
#define _GUI_ERROR 6
#endif
#ifdef onMove()
#undef onMove()
#undef _GUI_NERROR
#define _GUI_ERROR 7
#endif
#ifdef onCharPress()
#undef onCharPress()
#undef _GUI_NERROR
#define _GUI_ERROR 8
#endif
#ifdef GetCharPressed()
#undef GetCharPressed()
#undef _GUI_NERROR
#define _GUI_ERROR 9
#endif
#ifdef onResize()
#undef onResize()
#undef _GUI_NERROR
#define _GUI_ERROR 9
#endif
#ifdef onShow()
#undef onShow()
#undef _GUI_NERROR
#define _GUI_ERROR 10
#endif
#ifdef onLClick()
#undef onLClick()
#undef _GUI_NERROR
#define _GUI_ERROR 11
#endif
#ifdef onRClick()
#undef onRClick()
#undef _GUI_NERROR
#define _GUI_ERROR 12
#endif
#ifdef onNothing()
#undef onNothing()
#undef _GUI_NERROR
#define _GUI_ERROR 13
#endif
#ifdef drawBackground()
#undef drawBackground()
#undef _GUI_NERROR
#define _GUI_ERROR 14
#endif
#ifdef get_WND()
#undef get_WND()
#undef _GUI_NERROR
#define _GUI_ERROR 15
#endif
#include "WndProc.h"
#define main() int APIENTRY wWinMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPWSTR lpCmdLine, _In_ int nCmdShow)
#define GetInstance() hInstance
class Window {
protected:
	int width;
	int height;
	int x0;
	int x1;
	int y0;
	int y1;
	HWND createWindow(HINSTANCE hInst, string title, int style, int x0, int y0, int width, int height, HWND parentWindow, HANDLE cursor = LoadCursor(NULL, MAKEINTRESOURCE(IDC_ARROW))) {
		WNDCLASSEX wc = { 0 };
		wc.cbSize = sizeof(WNDCLASSEX);
		wc.hCursor = static_cast<HCURSOR>(cursor);
		wc.hInstance = hInst;
		wc.lpfnWndProc = WndProc;
		wstring temp = wstring(title.begin(), title.end());
		wc.lpszClassName = temp.c_str();
		RegisterClassEx(&wc);
		RECT rc = { 0, 0, 600, 600 };
		AdjustWindowRect(&rc, style, FALSE);
		return CreateWindow(temp.c_str(), temp.c_str(), style, x0, y0, width, height, parentWindow, NULL, hInst, NULL);
	}
public:
	HWND this_window;
	void __INIT__(HINSTANCE hInst, int setWidth, int setHeight, string window_name, POINT pos, int style, bool newCursor = false, string cursorPath = "", HWND parent = NULL) {
		width = setWidth;
		height = setHeight;
		x0 = pos.x;
		x1 = x0 + width;
		y0 = pos.y;
		y1 = y0 + height;
		if (newCursor == true) {
			HANDLE cursor = LoadImage(nullptr, (LPCWSTR)cursorPath.c_str(), IMAGE_CURSOR, 0, 0, LR_LOADFROMFILE);
			this_window = createWindow(hInst, window_name.c_str(), style, x0, y0, width, height, parent, cursor);
		}
		else this_window = createWindow(hInst, window_name.c_str(), style, x0, y0, width, height, parent);
	}
	int update() {
		MSG msg;
		if (PeekMessage(&msg, this_window, 0, 0)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
			return 0;
		}
		else return 1;
	}
};
#endif
