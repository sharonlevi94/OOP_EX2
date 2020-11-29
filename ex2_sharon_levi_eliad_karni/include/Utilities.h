#ifndef _Utilities_H
#define _Utilities_H
#pragma once
//---------------------------- include section -------------------------------
#include <fstream>
#include "Map.h"
#include "Location.h"
//----------------------------- const section --------------------------------
const int KB_ESCAPE = 27;
//--------------------------- prototypes section -----------------------------
void terminate(const std::string&);
int receiveKey();
int handleRegularKey(int c);
int handleSpecialKey();
void moveObject(const Map& map, const Location& init, const Location& dest,
	char symbol);
#endif // !_Utilities_H