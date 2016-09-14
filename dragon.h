/*
This is the header file for the Dragon Class
*/
#ifndef DRAGON_H
#define DRAGON_H
#include "enemy.h"

class Dragon : public Enemy {
		static const int health = 150, attack = 50, defence = 10;
		static const char ch = 'D';
	public :
		Dragon();
};

#endif
