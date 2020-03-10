#include "Graphics.h"
#include "HELOC.h"
#include "Checking.h"
#include "Savings.h"
#include <vector>
#ifdef _WIN32
vector<Background> backgrounds; //Backgrounds must be global variables
bool onFirstScrn = true, onSavings = false, onChecking = false, onHELOC = false;
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
	//Code what to do when the window paints here:
	DO_NOTHING;
}
onStart() {
	//Code what to do when the window starts here:
	DO_NOTHING;
}
onErase() {
	//Code what to do when the window erases here:
	DO_NOTHING;
}
onClose() {
	//Code what to do when the window closes here:
	DO_NOTHING;
}
ifInvalidWindow() {
	//Code what to do if the window is invalid here:
	DO_NOTHING;
}
onMove() {
	//Code what to do if the user moves the window here:
	DO_NOTHING;
}
onCharPress() {
	char keyPressed = GetCharPressed();
	//Code what to do if the user presses a key here:
	DO_NOTHING;
}
onResize() {
	//Code what to do if the user resizes the window here:
	DO_NOTHING;
}
onShow() {
	//Code what to do when the window is displaying here:
	DO_NOTHING;
}
onLClick() {
	POINT mouse_pos;
	GetCursorPos(&mouse_pos);//This isn't working...
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
	onFirstScrn = false, onHELOC = true;
	//Code what to do when the user clicks the left mouse key
}
onRClick() {
	//Code what to do when the user clicks the right mouse key
	DO_NOTHING;
}
onNothing() {
	//Code what to do if none of the above happen
	DO_NOTHING;
}
drawBackground() {
	HDC screen = get_DC();
	//Add logic to determine what background to draw here
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
			  
			  //HELOC
		  }
		  else if (onSavings == true) {
			  //Savings
		  }
		  else if (onChecking == true) {
			  //Checking
		  }
	  }
}
#endif
