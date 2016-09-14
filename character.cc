/*
This file contains the constructor and member routines of the Character Class
*/
#include "character.h"
#include "cell.h"
#include <cmath>

/*
Character(ch, health, attack, defence) is the constructor of the Character Class
*/
Character::Character(char ch, int health, int attack, int defence) : GameObject(ch, true, false) {	// create a GameObject
        _health = health;			// initialize _health to be health
        _attack = attack;			// initialize _attack to be attack
        _defence = defence;			// initialize _defence to be defence
        _max_health = health;			// intialize _max_health to be health
}

/*
health() returns the _health of the Character
*/
int Character::health() const {
        return _health;
}

/*
attack() returns the _attack of the Character
*/
int Character::attack() const {
        return _attack;
}

/*
defence() returns the _defence of the Character
*/
int Character::defence() const {
        return _defence;
}

/*
max_health() returns the _max_health of the Character
*/
int Character::max_health() const {
        return _max_health;
}

/*
damage() returns the number of damage the Character has received
*/
int Character::damage() const {
        return _damage;
}

/*
move(location) sets the location of the Character to be at location
*/
void Character::move(Cell* location) {
        GameObject::setLocation(location);	// setting location of GameObject since Character is a GameObject
}

/*
attack(enemy) attacks enemy and calculates the damage done to the enemy
	and updates the enemy's _health
*/
void Character::attack(Character* enemy) { 
        int enemy_def = enemy->defence();			// get enemy's _defence
        int enemy_health = enemy->health();			// get enemy's _health
        int damage = ceil(_attack*(100 - enemy_def)/100);	// formula to calculate damage
        enemy_health = enemy_health - damage;			// assign new enemy_health to enemy_health
        enemy->updateHealth(enemy_health);			// update enemy's health
        enemy->updateDamage(damage);				// update enemy's damage
}

/*
updateHealth(new_health) updates _health to new_health
*/
void Character::updateHealth(int new_health) {
        _health = new_health;
}

/*
updateAttack(new_attack) updates _attack to new_attack
*/
void Character::updateAttack(int new_attack) {
        _attack = new_attack;
}

/*
updateDefence(new_defence) updates _defence to new_defence
*/
void Character::updateDefence(int new_defence) {
        _defence = new_defence;
}

/*
updateDamage(new_damage) updates _damage to new_damage
*/
void Character::updateDamage(int new_damage) {
        _damage = new_damage;
}
