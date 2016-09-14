/*
This is the header file for the Character Class
*/
#ifndef CHARACTER_H
#define CHARACTER_H
#include "gameobject.h"

class Character : public GameObject {
    	int _health, _attack, _defence, _max_health, _damage;
    public:
        Character(char ch, int health, int attack, int defence);

        int health() const;
        int attack() const;
        int defence() const;
	int max_health() const;
        int damage() const;

        //virtual void tick() ;    // override from GameObject

        virtual void move(Cell* location);
        virtual void attack(Character* enemy);
        //virtual void attack(char ch);

        void updateHealth(int new_health);
	void updateAttack(int new_attack);
	void updateDefence(int new_defence);
    	void updateDamage(int new_damage);
};

#endif
