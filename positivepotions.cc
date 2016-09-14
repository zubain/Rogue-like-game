/*
This file contains the code for the constructor and member routines of the
	PosPotion Class
*/
#include "positivepotions.h"

/*
PosPotion(RH, BA, BD) is the constructor for the PosPotion Class
*/
PosPotion::PosPotion(bool RH, bool BA, bool BD) : Potion(true) {	// creates a Potion since PosPotion is a Potion	
	isRH = RH;							// initializes isRH to RH
	isBA = BA; 							// initializes isBA to BA
	isBD = BD;							// initializes isBD to BD
}

/*
effectsPotion(object) applies the effects of PosPotion to object
*/
void PosPotion::effectsPotion(Character* object) {
	if (isRH) {							// Potion is RH ?
		int new_health = object->health() + 30;			// add 30 to object's _health
		int max_health = object->max_health();			// retrieve object's _max_health
		if (new_health > max_health) {				// new_health is more than _max_health ?
			object->updateHealth(max_health);		// update object's _health to _max_health
		}
		else {							// new_health is less than max_health ?
			object->updateHealth(new_health);		// update object's _health to new_health
		} // if
	}
	else if (isBA) {						// Potion is BA ?
		int new_attack = object->attack() + 10;			// add 10 to object's _attack;
		object->updateAttack(new_attack);			// update object's _attack to new_attack
	}
	else if (isBD) {						// Potion is BD ?
		int new_defence = object->defence() + 10;		// add 10 to object's _defence
		object->updateDefence(new_defence);			// update object's _defence to new_defence
	} // if
}

/*
potionType() returns a string indicating the PosPotion's type
*/
std::string PosPotion::potionType(){
	std::string type;
	if (isRH){							// Potion is RH?
		type = "Restore Health";				// it is a Restore Health Potion
	}
	else if (isBA){							// Potion is BA?
		type = "Boost Attack";					// it is a Boost Attack Potion
	}
	else if (isBD){							// Potion is BD?
		type = "Boost Defence";					// it is a Boost Defence Potion
	} // if
	return type;
}
