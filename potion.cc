/*
This file includes the code for the constructor and member routines of the Potion Class
*/
#include "potion.h"

const char Potion::ch;			// static constant

/*
Potion(isPos) is the constructor of the Potion Class
*/
Potion::Potion(bool isPos) : Item(false, true, ch) {	// creates a Item since Potion is a Item
	_isPos = isPos;					// initialize _isPos to isPos
}

/*
isPos() returns a boolean value indicating whether or not Potion
	is a positive Potion
*/
bool Potion::isPos() {
	return _isPos;
}

