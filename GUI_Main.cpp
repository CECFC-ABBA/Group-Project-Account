//I didn't have time to make the button click check perfect yet
//HELOC is weird < temp fix didnt work
//Savings needs temp fix to be set up
//All of em need real transaction to work
#include "Graphics.h"
#include "HELOC.h"
#include "Checking.h"
#include "Savings.h"
#include <vector>
#include <string>
#ifdef _WIN32
vector<Background> backgrounds; //Backgrounds must be global variables
vector<char> chars;
bool onFirstScrn = true, onSavings = false, onChecking = false, onHELOC = false, edit = false, deposit = false, withdraw = false, _new = false, cleared = false, prnt = false;
string str = "";
int accountSelected = -1, numAccts = -1;
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
	Checking c;
	Savings s;
	HELOC h;
	c.setBal(0);
	s.setBal();
	h.setLoan(0);
	checking.push_back(c);
	savings.push_back(s);
	heloc.push_back(h);
	do {
		if (_new == true) {
			if (onChecking == true) {
				Checking c;
				c.setBal(0);
				checking.push_back(c);
			}
			else if (onSavings == true) {
				Savings s;
				s.setBal();
				savings.push_back(s);
			}
			else if (onHELOC == true) {
				HELOC h;
				h.setLoan(0);
				heloc.push_back(h);
			}
			_new = false, edit = true;
		}
		if (accountSelected > -1) {
			if (onChecking == true) {
				if (withdraw == true) {
					str = checking[accountSelected].Transaction(-100);
					//checking[accountSelected].setBal(checking[accountSelected].getBal() - 100);
					withdraw = false, edit = true;
				}
				else {
					str = checking[accountSelected].Transaction(100);
					//checking[accountSelected].setBal(checking[accountSelected].getBal() + 100);
					deposit = false, edit = true;
				}
			}
			else if (onSavings == true) {
				if (withdraw == true) {
					str = savings[accountSelected].Transaction(-100);
					//savings[accountSelected].setBal(savings[accountSelected].getBal() - 100);
					withdraw = false, edit = true;
				}
				else {
					str = savings[accountSelected].Transaction(100);
					//savings[accountSelected].setBal(savings[accountSelected].getBal() + 100);
					deposit = false, edit = true;
				}
			}
			else if (onHELOC == true) {
				if (withdraw == true) {
					str = heloc[accountSelected].Transaction(-100);
					//heloc[accountSelected].setLoan(heloc[accountSelected].getLoan() - 100);
					withdraw = false, edit = true;
				}
				else {
					str = heloc[accountSelected].Transaction(100);
					//heloc[accountSelected].setLoan(heloc[accountSelected].getLoan() + 100);
					deposit = false, edit = true;
				}
			}
			accountSelected = -1;
			numAccts = -1;
			prnt = true;
		}
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
		if (deposit == true || withdraw == true) {
			if (mouse_pos.y >= 45) {
				int index = 0;
				while (mouse_pos.y >= 45 + 15 * index) {
					index++;
				}
				if (index < numAccts) {
					accountSelected = index;
				}
				else if (numAccts == 1) {
					accountSelected = 0;
				}
			}
		}
		else {
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
				else if (mouse_pos.y >= 55 && mouse_pos.y <= 80 && edit == false) {
					onFirstScrn = false, edit = true;
				}
				else if (mouse_pos.y >= 105 && mouse_pos.y <= 130 && edit == true) {
					onFirstScrn = false, edit = false, withdraw = true;
				}
				else if (mouse_pos.y >= 80 && mouse_pos.y <= 105 && edit == true) {
					onFirstScrn = false, edit = false, deposit = true;
				}
				else if (mouse_pos.y >= 130 && mouse_pos.y <= 155 && edit == true) {
					onFirstScrn = false, edit = false, _new = true;
				}
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
	if (prnt == true) {
		backgrounds[0].draw(screen, 0, 0);
		TextOut(screen, 230, 300, wstring(str.begin(), str.end()).c_str(), str.length());
		Sleep(1000);
		prnt = false;
		str = "";
	}
	else {
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
			backgrounds[0].draw(screen, 0, 0);
			if (onHELOC == true) {
				int index = 0;
				for (HELOC h : heloc) {
					string str = to_string(index) + ": $" + to_string(h.getLoan());
					TextOut(screen, 225, 45 + 15 * index, wstring(str.begin(), str.end()).c_str(), str.length() - 4);
					index++;
				}
			}
			else if (onSavings == true) {
				int index = 0;
				for (Savings s : savings) {
					string str = to_string(index) + ": $" + to_string(s.getBal());
					TextOut(screen, 225, 45 + 15 * index, wstring(str.begin(), str.end()).c_str(), str.length() - 4);
					index++;
				}
			}
			else if (onChecking == true) {
				int index = 0;
				for (Checking c : checking) {
					string str = to_string(index) + ": $" + to_string(c.getBal());
					TextOut(screen, 225, 45 + 15 * index, wstring(str.begin(), str.end()).c_str(), str.length() - 4);
					index++;
				}
			}
			TextOut(screen, 225, 30, L"-----------------", 18);
			TextOut(screen, 225, 20, L"Accounts:", 10);
			if (edit == false && withdraw == false && deposit == false) {
				backgrounds[4].draw(screen, 0, 0);
				backgrounds[1].draw(screen, 0, 0);
				TextOut(screen, 0, 10, L"Back", 4);
				backgrounds[2].draw(screen, 0, 35);
				TextOut(screen, 0, 45, L"Edit", 4);
			}
			else if (edit == true) {
				backgrounds[1].draw(screen, 0, 0);
				TextOut(screen, 0, 10, L"Back", 4);
				backgrounds[2].draw(screen, 0, 35);
				backgrounds[3].draw(screen, 0, 60);
				backgrounds[3].draw(screen, 0, 85);
				TextOut(screen, 0, 45, L"Deposit $100", 13);
				TextOut(screen, 0, 80, L"Withdraw $100", 14);
				TextOut(screen, 0, 105, L"New", 3);
			}
			else if (withdraw == true || deposit == true) {
				if (onChecking == true) {
					numAccts = checking.size();
				}
				else if (onSavings == true) {
					numAccts = savings.size();
				}
				else if (onHELOC == true) {
					numAccts = heloc.size();
				}
				TextOut(screen, 230, 0, L"Click on target account:", 25);
			}
		}
	}
}
#endif
