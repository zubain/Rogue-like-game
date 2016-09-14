/*
This file contains the cconstructor and member routines of the Item Class
*/
#include "item.h"

/*
Item(isTreasure, isPotion, ch) is the constructor for the Item Class
*/
Item::Item(bool isTreasure, bool isPotion, char ch) : GameObject(ch, false, true) {	// create a GameObject since Item is a GameObject
	_isTreasure = isTreasure;		// initialize _isTreasure to be isTreasure
	_isPotion = isPotion;			// initialize _isPotion to be isPotion
}

/*
itemLocation(location) sets Item to be at location
*/
void Item::itemLocation(Cell* location) {
	GameObject::setLocation(location);	// setting location for GameObject since Item is a GameObject
}

/*
isTreasure() returns a boolean value indicating whether or not Item is a Treasure
*/
bool Item::isTreasure() {
	return _isTreasure;
}

/*
isPotion() returns a boolean value indicating whether or not Item is a Potion
*/
bool Item::isPotion() {
	return _isPotion;
}
