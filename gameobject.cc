/*
This file contains the constructor, destructor and member routines for the 
	GameObject Class
*/
#include "gameobject.h"
#include "cell.h"

/*
x(int i) sets the x-coordinate of the location of the GameObject to be i
*/
void GameObject::x(int i) {
	_x = i;
}

/*
y(int i) sets the y-coordinate of the location of the GameObject to be i
*/
void GameObject::y(int i) {
	_y = i;
}

/*
GameObject(ch, bool, item) is the constructor for the GameObject Class
*/
GameObject::GameObject(char ch, bool character, bool item) {
	_display = ch;					// initialize the _display of the GameObject to be ch
	_isCharacter = character;			// initialize _isCharacter to be character
	_isItem = item;					// initialize _isItem to be item
}

/*
~GameObject() is the destructor of the GameObject Class
*/
GameObject::~GameObject() {}

/*
x() returns the x-coordinate of the location of the GameObject
*/
int GameObject::x() const {
	return _x;
}

/*
y() returns the y-coordinate of the location of the GameObject
*/
int GameObject::y() const {
	return _y;
}

/*
display() returns _display of the GameObject
*/
char GameObject::display() const {
	return _display;
}

/*
isCharacter() returns a boolean value indicating whether or not the GameObject is a Character
*/
bool GameObject::isCharacter() {
	return _isCharacter;
}

/*
isItem() returns a boolean value indicating whether or not the GameObject is a Item
*/
bool GameObject::isItem() {
	return _isItem;
}

/*
setLocation(location) sets the Cell's _location to be location
*/
void GameObject::setLocation(Cell* location) {
	_location = location;			// assign _location to location
	x(_location->x());			// set the x-coordinate of the GameObject
	y(_location->y());			// set the y-coordinate of the GameObject
} 
