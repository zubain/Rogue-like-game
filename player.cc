/*
This file contains the constructor and member routines of the the Player Class
*/
#include "player.h"
#include <cmath>

const char Player::ch;			// static constant

/*
Player(health, attack, defence) is the constructor of the Player Class
*/
Player::Player(int health, int attack, int defence) :  Character(ch, health, attack, defence) {} // creating a Character since Player is a Character

/*
tick() updates the Player's health by adding 5 health points to _health, but will not let
	_health exceed the Player's _max_health 
*/
void Player::tick() {
	int new_health = Character::health() + 5;	// add 5 to the Player's current _health
	int max_health = Character::max_health();	// retrieve Player's _max_health
	if (new_health > max_health) {			// new_health is more than max_health ?
		Character::updateHealth(max_health);	// update Player's _health with max_health
	}
	else {						// new_health is less than max_health ?
		Character::updateHealth(new_health);	// update Player's _health with new_health
	} // if
}

