/*
This file contains the constructor and member routines code for the Treasure Class 
*/
#include "treasure.h"

const char Treasure::ch;		// static constant

/*
Treasure(isDragonHoard) is the constructor for the Treasure Class
*/
Treasure::Treasure(bool isDragonHoard) : Item(true, false, ch) {	// creates a Item since Treasure is a Item
	_isDragonHoard = isDragonHoard;					// set _isDragonHoard to isDragonHoard
	if (_isDragonHoard) {						// Treasure is a dragon hoard ?
		_worth = 50;						// its _worth is 50
	}
	else {								// Treasure is not a dragon hoard ?
		_worth = 10;						// its _worth is 10
	} // if
}

/*
isDragonHoard() returns a boolean value indicating whether or not Treasure is
	a dragon hoard
*/
bool Treasure::isDragonHoard() {
	return _isDragonHoard;
}

/*
worth() returns the _worth of the Treasure
*/
int Treasure::worth() {
	return _worth;
}
