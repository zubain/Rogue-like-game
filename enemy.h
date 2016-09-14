/*
This is the header file for the Enemy Class
*/
#ifndef ENEMY_H
#define ENEMY_H
#include "character.h"

class Enemy : public Character {
	public :
		Enemy(char ch, int health, int attack, int defence);
};

#endif
