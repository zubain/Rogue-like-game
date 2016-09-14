/*
This file contains the constructor and member routines for the Wizard Class
*/
#include "wizard.h"

const int Wizard::health, Wizard::attack, Wizard::defence;	// static constant

/*
Wizard() is the constructor for the Wizard Class
*/
Wizard::Wizard() :  Player(health, attack, defence) {	// creates a Player since Wizard is a Player
	Xhostility = ghostility = Ohostility = Dhostility = true; 	// all enemies beside Merchant is hostile to Wizard
	Mhostility = false; 						// Merchant is not hostile to Wizard
}

/*
isXHostile() returns a boolean value indicating whether or not GridBug is hostile to Wizard
*/
bool Wizard::isXHostile(){
	return Xhostility;
}

/*
isgHostile() returns a boolean value indicating whether or not Goblin is hostile to Wizard
*/
bool Wizard::isgHostile(){
	return ghostility;
}

/*
isMHostile() returns a boolean value indicating whether or not Merchant is hostile to Wizard
*/
bool Wizard::isMHostile(){
	return Mhostility;
}

/*
isOHostile() returns a boolean value indicating whetehr or not Orc is hostile to Wizard
*/
bool Wizard::isOHostile(){
	return Ohostility;
}

/*
isDHostile() returns a boolean value indicating whether or not Dragon is hostile to Wizard
*/
bool Wizard::isDHostile(){
	return Dhostility;
}

/*
updateXHostility() updates Xhostility to true
*/
void Wizard::updateXHostility(){
	Xhostility = true;
}

/*
updategHostility() updates ghostility to true
*/
void Wizard::updategHostility(){
	ghostility = true;
}

/*
updateMHostility() updates Mhostility to true
*/
void Wizard::updateMHostility(){
	Mhostility = true;
}

/*
updateOHostility() updates Ohostility to true
*/
void Wizard::updateOHostility(){
	Ohostility = true;
}

/*
updateDHostility() updates Dhostility to true
*/
void Wizard::updateDHostility(){
	Dhostility = true;
}
