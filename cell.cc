/*
This file includes the constructor, destructor and member routines for the Cell Class
*/
#include "cell.h"
#include "gameobject.h"

TextDisplay* Cell::_thedisplay;						// static variable

/*
notifyDisplay() notifies the display about changes in the state of the Cell
*/
void Cell::notifyDisplay() {
	if (_isObject) {						// the Cell contains a GameObject ?
		Cell::_thedisplay->notify(_x, _y, contents_display);	// notify _thedisplay to change its state into the char of the GameObject
	}
	else {								// the Cell does not contain a GameObject ?
		Cell::_thedisplay->notify(_x, _y, _display);		// notify _thedisplay to set its state as the char of the Cell itself
	} // if
}

/*
Cell() is the constructor of the Cell Class
*/
Cell::Cell() : _isObject(false) {}					// initialize _isObject to be false since the intial state of the Cell does not contain any GameObject

/*
setCellVal(x, y, ch) sets the coordinates of the Cell to be x and y and 
	also the char of the Cell to be ch
*/
void Cell::setCellVal(int x, int y, char ch) {
	_x = x;								// set _x to be x
	_y = y;								// set _y to be y
	_display = ch;							// set _display to be ch
}

/*
x() returns the x-coordinate of the Cell
*/
int Cell::x() const {
	return _x;
}

/*
y() returns the y-coordinate of the Cell
*/
int Cell::y() const {
	return _y;
}

/*
display() returns the current char the Cell is storing
*/
char Cell::display() const {
	if (_isObject) {						// the Cell contains a GameObject?
		return contents_display;				// return the char of that GameObject
	}
	else {								// the Cell does not contain a GameObject ?
		return _display;					// return the char of the Cell itself
	} // if
}

/*
isObject() returns a boolean value which indicates whether the Cell
	contains a GameObject or not
*/
bool Cell::isObject() {
	return _isObject;
}

/*
addObject(contents) adds the GameObject contents onto the Cell
*/
void Cell::addObject(GameObject* contents) {
	_contents = contents;						// set _contents to be contents
	contents_display = _contents->display();			// set contents_display to be the char of contents
	_isObject = true;						// _isObject is now true
	notifyDisplay();						// notify the display about this change
}

/*
removeObject() removes the GameObject from the Cell
*/
void Cell::removeObject() {
	_contents = NULL;						// _contents now point to NULL
	_isObject = false;						// Cell no longer contains a GameObject
	notifyDisplay();						// notify the display about this change
}

/*
addDisplay(display) assigns display to _thedisplay
*/
void Cell::addDisplay(TextDisplay* display) {
	Cell::_thedisplay = display;
}


