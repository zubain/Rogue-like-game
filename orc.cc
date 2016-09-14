/*
This file contains the code for the constructor of the Orc Class
*/
#include "orc.h"

const char Orc::ch;					// static constant
const int Orc::health, Orc::attack, Orc::defence;	// static constant

/*
Orc() is the constructor of the Orc Class
*/
Orc::Orc() : Enemy(ch, health, attack, defence) {}	// creates a Enemy since Orc is a Enemy
