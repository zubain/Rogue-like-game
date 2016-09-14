/*
This file contains the constructor and member routines for the Knight Class
*/
#include "knight.h"

const int Knight::health, Knight::attack, Knight::defence;		// static constant

/*
Knight() is the constructor for the Knight Class
*/
Knight::Knight() : Player(health, attack, defence) { 					// creates a Player since Knight is a Player
	Xhostility = ghostility = Ohostility = Dhostility = true;			// all types of enemies besides Merchant are hostile to Knight
	Mhostility = false;								// Merchant is not hostile to Knight
}

/*
isXHostile() returns a boolean value indicating whether or not all GridBug is hostile to Knight
*/
bool Knight::isXHostile(){
	return Xhostility;
}

/*
isgHostile() returns a boolean value indicating whether or not all Goblin is hostile is Knight
*/
bool Knight::isgHostile(){
	return ghostility;
}

/*
isMHostile() returns a boolean value indicating whether or not all Merchant is hostile to Knight
*/
bool Knight::isMHostile(){
	return Mhostility;
}

/*
isOHostile() returns a boolean value indicating whether or not all Orc is hostile to Knight
*/
bool Knight::isOHostile(){
	return Ohostility;
}

/*
isDHostile() returns a boolean value indicating whether or not all Dragon is hostile to Knight
*/
bool Knight::isDHostile(){
	return Dhostility;
}

/*
updateXHostility() updates Xhostility to true
*/
void Knight::updateXHostility(){
	Xhostility = true;
}

/*
updategHostility() updates ghostility to true
*/
void Knight::updategHostility(){
	ghostility = true;
}

/*
updateMHostility() updates Mhostility to true
*/
void Knight::updateMHostility(){
	Mhostility = true;
}

/*
updateOHostility() updates Ohostility to true
*/
void Knight::updateOHostility(){
	Ohostility = true;
}

/*
updateDHostility() updates Dhostility to true
*/
void Knight::updateDHostility(){
	Dhostility = true;
}
