#include "Graphics.h"//Todo: add sprite resize + rotation
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

}
onStart() {
	//Code what to do when the window starts here:

}
onErase() {
	//Code what to do when the window erases here:

}
onClose() {
	//Code what to do when the window closes here:

}
ifInvalidWindow() {
	//Code what to do if the window is invalid here:

}
onMove() {
	//Code what to do if the user moves the window here:

}
onCharPress() {
	char keyPressed = GetCharPressed();
	//Code what to do if the user presses a key here:

}
onResize() {
	//Code what to do if the user resizes the window here:

}
onShow() {
	//Code what to do when the window is displaying here:

}
onLClick() {
	//Code what to do when the user clicks the left mouse key

}
onRClick() {
	//Code what to do when the user clicks the right mouse key

}
onNothing() {
	//Code what to do if none of the above happen

}
drawBackground() {
	HDC screen = get_DC();
	//Add logic to determine what background to draw here

	background.draw(screen, 0, 0);
}
#endif
