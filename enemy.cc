/*
This file contains the constructor for the Enemy Class
*/
#include "enemy.h"

/*
Enemy(ch, health, attack, defence) is the constructor for the Enemy Class
*/
Enemy::Enemy(char ch, int health, int attack, int defence) : Character(ch, health, attack, defence) {}	// creates a Character since Enemy is a Character
