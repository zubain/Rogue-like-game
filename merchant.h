/*
This is the header file for the Merchant Class
*/
#ifndef MERCHANT_H
#define MERCHANT_H
#include "enemy.h"

class Merchant : public Enemy {
		static const int health = 100, attack = 75, defence = 5;
		static const char ch = 'M';
	public :
		Merchant();
};

#endif
