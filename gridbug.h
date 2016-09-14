/*
This is the header file for the GridBug Class
*/
#ifndef GRIDBUG_H
#define GRIDBUG_H
#include "enemy.h"

class GridBug : public Enemy {
		static const int health = 50, attack = 20, defence = 10;
		static const char ch = 'X'; 
	public  :
		GridBug();
};

#endif
