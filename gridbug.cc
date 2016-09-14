/*
This file contains the constructor for the GridBug Class
*/
#include "gridbug.h"
const char GridBug::ch;							// static constant
const int GridBug::health, GridBug::attack, GridBug::defence;		// static constant

/*
GridBug() is the constructor for the GridBug Class
*/
GridBug::GridBug() : Enemy(ch, health, attack, defence) {}		// creates a Enemy since GridBug is a Enemy
