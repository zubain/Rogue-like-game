/*
This is the header file for the Goblin Class
*/
#ifndef GOBLIN_H
#define GOBLIN_H
#include "enemy.h"

class Goblin : public Enemy {
		static const int health = 75, attack = 30, defence = 20;
		static const char ch = 'g';
	public :
		Goblin();
};

#endif
