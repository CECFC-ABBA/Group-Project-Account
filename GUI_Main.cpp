#include "Graphics.h"
#include "HELOC.h"
#include "Checking.h"
#include "Savings.h"
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#ifdef _WIN32
vector<Background> backgrounds;
vector<char> chars;
bool onFirstScrn = true, onSavings = false, onChecking = false, onHELOC = false, edit = false, deposit = false, withdraw = false, _new = false, cleared = false, prnt = false;
string str = "";
int accountSelected = -1, numAccts = -1;
vector<Checking> checking;
vector<Savings> savings;
vector<HELOC> heloc;
ofstream file("Log.txt");
main() {
	//file.open("Log.txt");
	ErrorFunction();
	Window window;
	POINT pos;
	int style, width, height, background_width, background_height;
	const char* name = "Bank Accounts";
	style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX;
	width = 500;
	height = 500;
	pos.x = 500;
	pos.y = 500;
  Background background, background2;
	background_width = 500;
	background_height = 500;
	background.load("D:\\GRP_GUI\\Background.bmp", background_width, background_height, GetInstance());
  backgrounds.push_back(background);
  Background button_one;
  int button_width = 100;
  int button_height = 50;
  button_one.load("D:\\GRP_GUI\\Button1.bmp", button_width, button_height, GetInstance());
  backgrounds.push_back(button_one);
  backgrounds.push_back(button_one);
  backgrounds.push_back(button_one);
  background2.load("D:\\GRP_GUI\\Background2.bmp", background_width, background_height, GetInstance());
  backgrounds.push_back(background2);
	window.__INIT__(GetInstance(), width, height, name, pos, style);
	Checking c;
	Savings s;
	HELOC h;
	c.setBal(0);
	s.setBal(0);
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
				file << "New checking account created\n";
			}
			else if (onSavings == true) {
				Savings s;
				s.setBal(0);
				savings.push_back(s);
				file << "New savings account created\n";
			}
			else if (onHELOC == true) {
				HELOC h;
				h.setLoan(0);
				heloc.push_back(h);
				file << "New HELOC account created\n";
			}
			_new = false, edit = true;
		}
		if (accountSelected > -1) {
			if (onChecking == true) {
				Checking temp = checking[accountSelected];
				if (withdraw == true) {
					double cur_bal = checking[accountSelected].getBal();
					str = temp.Transaction(-100);
					checking[accountSelected].setBal(max(0, checking[accountSelected].getBal() - 100));
					withdraw = false, edit = true;
					file << "Checking " << accountSelected << ": " << cur_bal << " --> " << checking[accountSelected].getBal() << endl;
				}
				else {
					double cur_bal = checking[accountSelected].getBal();
					str = temp.Transaction(100);
					checking[accountSelected].setBal(max(0, checking[accountSelected].getBal() + 100));
					deposit = false, edit = true;
					file << "Checking " << accountSelected << ": " << cur_bal << " --> " << checking[accountSelected].getBal() << endl;
				}
			}
			else if (onSavings == true) {
				Savings temp = savings[accountSelected];
				if (withdraw == true) {
					double cur_bal = savings[accountSelected].getBal();
					str = temp.Transaction(-100);
					savings[accountSelected].setBal(max(0, savings[accountSelected].getBal() - 100));
					withdraw = false, edit = true;
					file << "Savings " << accountSelected << ": " << cur_bal << " --> " << checking[accountSelected].getBal() << endl;
				}
				else {
					double cur_bal = savings[accountSelected].getBal();
					str = temp.Transaction(100);
					savings[accountSelected].setBal(max(0, savings[accountSelected].getBal() + 100));
					deposit = false, edit = true;
					file << "Savings " << accountSelected << ": " << cur_bal << " --> " << checking[accountSelected].getBal() << endl;
				}
			}
			else if (onHELOC == true) {
				HELOC temp = heloc[accountSelected];
				if (withdraw == true) {
					double cur_bal = heloc[accountSelected].getLoan();
					str = temp.Transaction(-100);
					heloc[accountSelected].setLoan(max(0, heloc[accountSelected].getLoan() - 100));
					withdraw = false, edit = true;
					file << "HELOC " << accountSelected << ": " << cur_bal << " --> " << heloc[accountSelected].getBal() << endl;
				}
				else {
					double cur_bal = heloc[accountSelected].getLoan();
					str = temp.Transaction(100);
					heloc[accountSelected].setLoan(max(0, heloc[accountSelected].getLoan() + 100));
					deposit = false, edit = true;
					file << "HELOC " << accountSelected << ": " << cur_bal << " --> " << heloc[accountSelected].getBal() << endl;
				}
			}
			accountSelected = -1;
			numAccts = -1;
			prnt = true;
		}
	} while (window.update() == 0);
	file.close();
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
			if (onChecking == true) {
				numAccts = checking.size();
			}
			else if (onSavings == true) {
				numAccts = savings.size();
			}
			else if (onHELOC == true) {
				numAccts = heloc.size();
			}
			if (mouse_pos.y >= 45) {
				int index = 0;
				while (mouse_pos.y >= 45 + 15 * index) {
					index++;
				}
				while (index > numAccts) {
					index--;
				}
				accountSelected = index - 3;
				while (accountSelected < 0) {
					accountSelected++;
				}
			}
		}
		else {
			if (onFirstScrn == true) {
				if (mouse_pos.x >= 200 && mouse_pos.x <= 300) {
					if (mouse_pos.y >= 235 && mouse_pos.y <= 305) {
						onFirstScrn = false, onSavings = false, onChecking = false, onHELOC = true;
					}
					else if (mouse_pos.y >= 175 && mouse_pos.y <= 225) {
						onFirstScrn = false, onSavings = false, onChecking = true, onHELOC = false;
					}
					else if (mouse_pos.y >= 315 && mouse_pos.y <= 365) {
						onFirstScrn = false, onSavings = true, onChecking = false, onHELOC = false;
					}
				}
			}
			else if (mouse_pos.x >= 0 && mouse_pos.x <= 150) {
				if (mouse_pos.y >= 0 && mouse_pos.y <= 55) {
					onFirstScrn = true, onChecking = false, onSavings = false, onHELOC = false, edit = false;
				}
				else if (mouse_pos.y >= 65 && mouse_pos.y <= 115 && edit == false) {
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
		TextOut(screen, 0, 300, wstring(str.begin(), str.end()).c_str(), str.length());
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
					string Str = to_string(index) + ": $" + to_string(h.getLoan());
					TextOut(screen, 225, 45 + 15 * index, wstring(Str.begin(), Str.end()).c_str(), Str.length() - 4);
					index++;
				}
			}
			else if (onSavings == true) {
				int index = 0;
				for (Savings s : savings) {
					string Str = to_string(index) + ": $" + to_string(s.getBal());
					TextOut(screen, 225, 45 + 15 * index, wstring(Str.begin(), Str.end()).c_str(), Str.length() - 4);
					index++;
				}
			}
			else if (onChecking == true) {
				int index = 0;
				for (Checking c : checking) {
					string Str = to_string(index) + ": $" + to_string(c.getBal());
					TextOut(screen, 225, 45 + 15 * index, wstring(Str.begin(), Str.end()).c_str(), Str.length() - 4);
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
				TextOut(screen, 230, 0, L"Click on target account:", 25);
			}
		}
	}
}
#endif
