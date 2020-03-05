/**
//Todo: add ***good*** comments to all files

//Todo: Finish Sprite.h, STD.h, Clock.h

#include "Graphics.h"//Todo: add sprite resize + rotation
#ifdef _WIN32//TODO: Add a FileStream usage example
SpriteList all_sprites_list; //All SpriteList objects must be global
vector<vector<int>> spriteUpdateData; //All update lists must be global
Background background; //Backgrounds must be global variables
main() {
	ErrorFunction();
	Window window;
	POINT pos, spritePos, sprite2Pos;
	Sprite sampleSprite, sampleSprite2;
	int style, width, height, background_width, background_height, spriteWidth, spriteHeight, spriteAngle, sprite2Width, sprite2Height, sprite2Angle;
	const char* name;
	const char* path = "C:\\Line.bmp"; //Must be a .bmp image file
	const char* path2 = "C:\\Line.bmp"; //Must be a .bmp image file
	style = WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_VISIBLE | WS_MINIMIZEBOX | WS_MAXIMIZEBOX; //Set this
	sampleSprite.ID = "A";
	sampleSprite2.ID = "B";
	width = 500; //Set this
	height = 500; //Set this
	spritePos.x = 100; //Set this
	sprite2Pos.x = 200; //Set this
	spritePos.y = 100; //Set this
	sprite2Pos.y = 200; //Set this
	name = "My Window"; //Set this
	pos.x = 500; //Set this
	pos.y = 500; //Set this
	background_width = 100; //Set this
	background_height = 100; //Set this
	spriteWidth = 100; //Set this
	sprite2Width = 100; //Set this
	spriteHeight = 100; //Set this
	sprite2Height = 100; //Set this
	spriteAngle = 0; //Set this (degrees, sadly)
	sprite2Angle = 45; //Set this (degrees, sadly)
	sampleSprite.init(path, spritePos, spriteWidth, spriteHeight, spriteAngle);
	sampleSprite2.init(path2, sprite2Pos, sprite2Width, sprite2Height, sprite2Angle);
	all_sprites_list.add(sampleSprite);
	all_sprites_list.add(sampleSprite2); //Note that it will draw, and update the last item added last
	background.load("C:\\Line.bmp", background_width, background_height); //Must be a .bmp image file
	window.__INIT__(GetInstance(), width, height, name, pos, style); //Note that cursor-changing is supported, just needs different parameters
	do {
		//Main Loop Here:

		spriteUpdateData.clear();
		vector<int> spriteData = sampleSprite.fetchData(); //sampleSprite's data
		vector<int> sprite2Data = sampleSprite.fetchData(); //sampleSprite2's data
		spriteUpdateData.push_back(spriteData); //You could modify this data if you wanted
		spriteUpdateData.push_back(sprite2Data); //You could modify this data if you wanted
		all_sprites_list.update(spriteUpdateData);
	} while (window.update() == 0);
	return 0;
}
onPaint() {
	HDC screen = get_DC();
	//Code what to do when the window paints here:

	all_sprites_list.draw(screen);
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
#else
//not supported yet, a.k.a. not windows
#endif**/