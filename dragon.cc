/*
This file contains the code for the constructor for the Dragon Class
*/
#include "dragon.h"

const char Dragon::ch;							// static constant
const int Dragon::health, Dragon::attack, Dragon::defence;		// static constant

/*
Dragon() is the constructor for the Dragon Class
*/
Dragon::Dragon() : Enemy(ch, health, attack, defence) {}		// creates a Enemy since Dragon is a Enemy
