/*
This file conains the code for the constructor and member routines of the 
	Stairs Class
*/
#include "stairs.h"

const char Stairs::ch;				// static constant

/*
Stairs() is the constructor for the Stairs Class
*/
Stairs::Stairs() : GameObject(ch, false, false) {}	// creates a GameObject since Stairs is a GameObject

/*
stairsLocation(location) sets stairs to be at location
*/
void Stairs::stairsLocation(Cell* location) {
	GameObject::setLocation(location);		// setting location of GameObject since Stairs is a GameObject 
}	 
