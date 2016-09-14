/*
This file contains the constructor and member routines for the Samurai Class
*/
#include "samurai.h"
const int Samurai::health, Samurai::attack, Samurai::defence;		// static constant

/*
Samurai() is the constructor of the Samurai Class
*/
Samurai::Samurai() : Player(health, attack, defence) {			// creates a Player since Samurai is a Player
	Xhostility = ghostility = Mhostility = Ohostility = Dhostility = false; 	// all enemies are not hostile to Samurai
}

/*
isXHostile() returns a boolean value indicating whether Gridbug is hostile to Samurai
*/
bool Samurai::isXHostile(){
	return Xhostility;
}

/*
isgHostile() returns a boolean value indicating whether Goblin is hostile to Samurai
*/
bool Samurai::isgHostile(){
	return ghostility;
}

/*
isMHostile() returns a boolean value indicating whether Merchant is hostile to Samurai
*/
bool Samurai::isMHostile(){
	return Mhostility;
}

/*
isOHostile() returns a boolean value indicating whether Orc is hostile to Samurai
*/
bool Samurai::isOHostile(){
	return Ohostility;
}

/*
isDHostile() returns a boolean value indicating whether Dragon is hostile to Samurai
*/
bool Samurai::isDHostile(){
	return Dhostility;
}

/*
updateXHostility() updates Xhostility to true
*/
void Samurai::updateXHostility(){
	Xhostility = true;
}

/*
updategHostility() updates ghostility to true
*/
void Samurai::updategHostility(){
	ghostility = true;
}

/*
updateMHostility() updates Mhostility to true
*/
void Samurai::updateMHostility(){
	Mhostility = true;
}

/*
updateOHostility() updates Ohostility to true
*/
void Samurai::updateOHostility(){
	Ohostility = true;
}

/*
updateDHostility() updates Dhostility to true
*/
void Samurai::updateDHostility(){
	Dhostility = true;
}
