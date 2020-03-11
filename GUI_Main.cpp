//I didn't have time to make the button click check perfect
#include "Graphics.h"
#include "HELOC.h"
#include "Checking.h"
#include "Savings.h"
#include <vector>
#include <string>
#ifdef _WIN32
vector<Background> backgrounds; //Backgrounds must be global variables
vector<char> chars;
bool onFirstScrn = true, onSavings = false, onChecking = false, onHELOC = false, edit = false, deposit = false, withdraw = false, _new = false, cleared = false;
vector<Checking> checking;
vector<Savings> savings;
vector<HELOC> heloc;
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
	chars.push_back(keyPressed);
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
				onFirstScrn = true, onChecking = false, onSavings = false, onHELOC = false, edit = false;
			}
			else if (mouse_pos.y >= 60 && mouse_pos.y <= 110 && edit == false) {
				onFirstScrn = false, edit = true;
			}
			else if (mouse_pos.y >= 120 && mouse_pos.y <= 145 && edit == true) {
				onFirstScrn = false, edit = false, withdraw = true;
			}
			else if (mouse_pos.y >= 60 && mouse_pos.y <= 110 && edit == true) {
				onFirstScrn = false, edit = false, deposit = true;
			}
			else if (mouse_pos.y >= 155 && mouse_pos.y <= 180 && edit == true) {
				onFirstScrn = false, edit = false, _new = true;
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
		  if (edit == false && withdraw == false && deposit == false) {
			  backgrounds[4].draw(screen, 0, 0);
			  TextOut(screen, 225, 15, L"------------", 13);
			  TextOut(screen, 225, 10, L"Accounts:", 10);
			  backgrounds[1].draw(screen, 0, 0);
			  TextOut(screen, 0, 10, L"Back", 4);
			  backgrounds[2].draw(screen, 0, 35);
			  TextOut(screen, 0, 65, L"Edit", 4);
			  if (onHELOC == true) {
				  int index = 0;
				  for (HELOC h : heloc) {
					  string str = to_string(index + h.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
			  else if (onSavings == true) {
				  int index = 0;
				  for (Savings s : savings) {
					  string str = to_string(index + s.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
			  else if (onChecking == true) {
				  int index = 0;
				  for (Checking c : checking) {
					  string str = to_string(index + c.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
		  }
		  else if (edit == true) {
			  backgrounds[1].draw(screen, 0, 0);
			  TextOut(screen, 0, 10, L"Back", 4);
			  TextOut(screen, 225, 20, L"------------", 13);
			  TextOut(screen, 225, 10, L"Accounts:", 10);
			  backgrounds[2].draw(screen, 0, 35);
			  TextOut(screen, 0, 65, L"Deposit $100", 13);
			  TextOut(screen, 0, 100, L"Withdraw $100", 14);
			  TextOut(screen, 0, 135, L"New", 3);
			  if (onHELOC == true) {
				  int index = 0;
				  for (HELOC h : heloc) {
					  string str = to_string(index + h.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
			  else if (onSavings == true) {
				  int index = 0;
				  for (Savings s : savings) {
					  string str = to_string(index + s.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
			  else if (onChecking == true) {
				  int index = 0;
				  for (Checking c : checking) {
					  string str = to_string(index + c.getBal());
					  TextOut(screen, 255, 35 + 10 * index, wstring(str.begin(), str.end()).c_str(), str.length());
				  }
			  }
		  }
		  else if (withdraw == true || deposit == true) {
			  TextOut(screen, 255, 0, L"Enter Account Number:", 22);
			  if (cleared == false) {
				  chars.clear();
				  cleared = true;
			  }
			  else {
				  string temp;
				  for (char c : chars) {
					  temp.push_back(c);
				  }
				  try {
					  int cur = atoi(temp.c_str());
					  if (onChecking == true && cur < checking.size()) {
						  if (withdraw == true) {
							  string str = checking[cur].Transaction(-100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
						  else {
							  string str = checking[cur].Transaction(100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
					  }
					  else if (onSavings == true && cur < savings.size()) {
						  if (withdraw == true) {
							  string str = savings[cur].Transaction(-100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
						  else {
							  string str = savings[cur].Transaction(100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
					  }
					  else if (onHELOC == true && cur < heloc.size()) {
						  if (withdraw == true) {
							  string str = heloc[cur].Transaction(-100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
						  else {
							  string str = heloc[cur].Transaction(100);
							  TextOut(screen, 200, 100, wstring(str.begin(), str.end()).c_str(), str.length());
						  }
					  }
				  }
				  catch (exception ex) {
					  chars.clear();
				  }
			  }
		  }
		  else {
			  if (onChecking == true) {
				  Checking c;
				  checking.push_back(c);
			  }
			  else if (onSavings == true) {
				  Savings s;
				  savings.push_back(s);
			  }
			  else if (onHELOC == true) {
				  HELOC h;
				  heloc.push_back(h);
			  }
		  }
	  }
}
#endif
