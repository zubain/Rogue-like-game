/*
This is the header file for the Orc Class
*/
#ifndef ORC_H
#define ORC_H
#include "enemy.h"

class Orc : public Enemy {
		static const int health = 120, attack = 30, defence = 30;
		static const char ch = 'O';
	public :
		Orc();
};

#endif
