#include "Graphics.h"
#ifdef _WIN32
Background background; //Backgrounds must be global variables
main() {
	ErrorFunction();
	Window window;
	POINT pos, spritePos, sprite2Pos;
	int style, width, height, background_width, background_height;
	const char* name;
	const char* path = "C:\\Line.bmp"; //Must be a .bmp image file
	const char* path2 = "C:\\Line.bmp"; //Must be a .bmp image file
	style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX; //Set this
	width = 500; //Set this
	height = 500; //Set this
	name = "My Window"; //Set this
	pos.x = 500; //Set this
	pos.y = 500; //Set this
	background_width = 100; //Set this
	background_height = 100; //Set this
	background.load("C:\\Line.bmp", background_width, background_height); //Must be a .bmp image file
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
	background.draw(screen, 0, 0);
}
#endif
