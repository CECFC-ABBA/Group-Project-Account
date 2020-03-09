#include "Graphics.h"
#include <vector>
#ifdef _WIN32
vector<Background> backgrounds; //Backgrounds must be global variables
main() {
	ErrorFunction();
	Window window;
	POINT pos;
	int style, width, height, background_width, background_height;
	const char* name = "Bank Accounts";
	style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX; //Set this
	width = 500; //Let's try a 500x500 window
	height = 500;
	pos.x = 500; //Start near the centre of the screen
	pos.y = 500; //
  Background background;
	background_width = 500; //Main background same size as screen
	background_height = 500;
	background.load("Background.bmp", background_width, background_height); //Must be a .bmp image file
  backgrounds.push_back(background);
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
	//Code what to do when the user clicks the left mouse key
	DO_NOTHING;
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
	DO_NOTHING;
  for (Background background : backgrounds) {
	  background.draw(screen, 0, 0);
  }
}
#endif
