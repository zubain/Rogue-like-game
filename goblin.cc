/*
This file contains the code for constructor for the Goblin Class
*/
#include "goblin.h"

const char Goblin::ch;						//static constant
const int Goblin::health, Goblin::attack, Goblin::defence;	//static constant

/*
Goblin() is the constructor for the Goblin Class
*/
Goblin::Goblin() : Enemy(ch, health, attack, defence) {}	// creates an Enemy since Goblin is a Enemy
