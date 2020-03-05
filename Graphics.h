/*
 * Author: Alexander Marsh
 * Last Edit Date: 10/8/2019
 * Usage: Provides a mother header that allows you to use "Window.h", "Sprite.h", and "Background.h", and handles exceptions which will be added in the future
 * ~~Change Log~~
 * Oct. 8, 2019 - Not much really.
 */
#pragma once
#define _GUI_NERROR
#include "Window.h"
#include "Background.h"
#ifndef _GUI_NERROR
//Probably make the error handling more useful, lol...
#ifdef _GUI_ERROR 1
#define ErrorFunction() cout << "Error code 1."; exit(1);
#endif
#ifdef _GUI_ERROR 2
#define ErrorFunction() cout << "Error code 2."; exit(1);
#endif
#ifdef _GUI_ERROR 3
#define ErrorFunction() cout << "Error code 3."; exit(1);
#endif
#ifdef _GUI_ERROR 4
#define ErrorFunction() cout << "Error code 4."; exit(1);
#endif
#ifdef _GUI_ERROR 5
#define ErrorFunction() cout << "Error code 5."; exit(1);
#endif
#ifdef _GUI_ERROR 6
#define ErrorFunction() cout << "Error code 6."; exit(1);
#endif
#ifdef _GUI_ERROR 7
#define ErrorFunction() cout << "Error code 7."; exit(1);
#endif
#ifdef _GUI_ERROR 8
#define ErrorFunction() cout << "Error code 8."; exit(1);
#endif
#ifdef _GUI_ERROR 9
#define ErrorFunction() cout << "Error code 9."; exit(1);
#endif
#ifdef _GUI_ERROR 10
#define ErrorFunction() cout << "Error code 10."; exit(1);
#endif
#ifdef _GUI_ERROR 11
#define ErrorFunction() cout << "Error code 11."; exit(1);
#endif
#ifdef _GUI_ERROR 12
#define ErrorFunction() cout << "Error code 12."; exit(1);
#endif
//Add more as they are needed here!
#endif
#ifndef ErrorFunction()
#define ErrorFunction()
#endif
