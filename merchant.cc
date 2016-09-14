/*
This file contains the code for the constructor of the Merchant Class
*/
#include "merchant.h"

const char Merchant::ch;						// static constant
const int Merchant::health, Merchant::attack, Merchant::defence;	// static constant

/*
Merchant() is the constructor for the Merchant Class
*/
Merchant::Merchant() : Enemy(ch, health, attack, defence) {}		// creates a Enemy since Merchant is a Enemy
