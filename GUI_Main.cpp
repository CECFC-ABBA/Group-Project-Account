#include "Graphics.h"
//#include "HELOC.h"
#include "Checking.h"
//#include "Savings.h"
#include <vector>
#ifdef _WIN32
vector<Background> backgrounds; //Backgrounds must be global variables
bool onFirstScrn = true, onSavings = false, onChecking = false, onHELOC = false;
//vector<Checking> checking;
//vector<Savings> savings;
//vector<HELOC> heloc;
main() {
	ErrorFunction();
	Window window;
	POINT pos;
	int style, width, height, background_width, background_height;
	const char* name = "Bank Accounts";
	style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX; //Set this
	width = 500; //Let's try a 500x500 window
	height = 500;
	pos.x = 500; //Start near the centre of the screen
	pos.y = 500; //
  Background background, background2;
	background_width = 500; //Main background same size as screen
	background_height = 500;
	background.load("D:\\GRP_GUI\\Background.bmp", background_width, background_height, GetInstance()); //Must be a .bmp image file
  backgrounds.push_back(background);
  Background button_one;
  int button_width = 100; //Try 100x50
  int button_height = 50;
  button_one.load("D:\\GRP_GUI\\Button1.bmp", button_width, button_height, GetInstance());
  backgrounds.push_back(button_one);
  backgrounds.push_back(button_one);
  backgrounds.push_back(button_one);
  background2.load("D:\\GRP_GUI\\Background2.bmp", background_width, background_height, GetInstance());
  backgrounds.push_back(background2);
	window.__INIT__(GetInstance(), width, height, name, pos, style); //Note that cursor-changing is supported, just needs different parameters
	do {
		//Main Loop Here:

	} while (window.update() == 0);
	return 0;
}
onPaint() {
	HDC screen = get_DC();
	DO_NOTHING;
}
onStart() {
	DO_NOTHING;
}
onErase() {
	DO_NOTHING;
}
onClose() {
	DO_NOTHING;
}
ifInvalidWindow() {
	DO_NOTHING;
}
onMove() {
	DO_NOTHING;
}
onCharPress() {
	char keyPressed = GetCharPressed();
	DO_NOTHING;
}
onResize() {
	DO_NOTHING;
}
onShow() {
	DO_NOTHING;
}
onLClick() {
	POINT mouse_pos;
	if (GetCursorPos(&mouse_pos)) {
		RECT rc;
		GetWindowRect(hWnd, &rc);
		mouse_pos.x -= rc.left;
		mouse_pos.y -= rc.top;
		if (onFirstScrn == true) {
			if (mouse_pos.x >= 200 && mouse_pos.x <= 300) {
				if (mouse_pos.y >= 225 && mouse_pos.y <= 275) {
					onFirstScrn = false, onSavings = false, onChecking = true, onHELOC = false;
				}
				else if (mouse_pos.y >= 165 && mouse_pos.y <= 215) {
					onFirstScrn = false, onSavings = false, onChecking = false, onHELOC = true;
				}
				else if (mouse_pos.y >= 285 && mouse_pos.y <= 335) {
					onFirstScrn = false, onSavings = true, onChecking = false, onHELOC = false;
				}
			}
		}
		else if (mouse_pos.x >= 0 && mouse_pos.x <= 100) {
			if (mouse_pos.y >= 0 && mouse_pos.y <= 50) {
				onFirstScrn = true, onChecking = false, onSavings = false, onHELOC = false;
			}
			else if (mouse_pos.y >= 60 && mouse_pos.y <= 110) {
				//Edit
			}
		}
	}
}
onRClick() {
	DO_NOTHING;
}
onNothing() {
	DO_NOTHING;
}
drawBackground() {
	HDC screen = get_DC();
	  if (onFirstScrn == true) {
		  backgrounds[0].draw(screen, 0, 0);
		  backgrounds[1].draw(screen, 200, 225);
		  backgrounds[2].draw(screen, 200, 165);
		  backgrounds[3].draw(screen, 200, 285);
		  TextOut(screen, 220, 180, L"Checking", 9);
		  TextOut(screen, 225, 240, L"HELOC", 6);
		  TextOut(screen, 220, 300, L"Savings", 8);
	  }
	  else {
		  backgrounds[4].draw(screen, 0, 0);
		  TextOut(screen, 225, 15, L"------------", 13);
		  TextOut(screen, 225, 10, L"Accounts:", 10);
		  if (onHELOC == true) {
			  //for (HELOC h : heloc) {
				  //Display info
			  //}
			  backgrounds[1].draw(screen, 0, 0);
			  TextOut(screen, 0, 10, L"Back", 4);
			  backgrounds[2].draw(screen, 0, 35);
			  TextOut(screen, 0, 65, L"Edit", 6);
		  }
		  else if (onSavings == true) {
			  //for (Savins s : savings) {
				  //Display info
			  //}
			  backgrounds[1].draw(screen, 0, 0);
			  TextOut(screen, 0, 10, L"Back", 4);
			  backgrounds[2].draw(screen, 0, 35);
			  TextOut(screen, 0, 65, L"Edit", 6);
		  }
		  else if (onChecking == true) {
			  //for (Checking c : checking) {
				  //Display info
			  //}
			  backgrounds[1].draw(screen, 0, 0);
			  TextOut(screen, 0, 10, L"Back", 4);
			  backgrounds[2].draw(screen, 0, 35);
			  TextOut(screen, 0, 65, L"Edit", 6);
		  }
	  }
}
#endif
