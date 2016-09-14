/*
This file contains the code for the constructor and member routines of the 
	NegPotion Class
*/
#include "negativepotions.h"

/*
NegPotion(PH, WA, WD) is the constructor for the NegPotion Class
*/
NegPotion::NegPotion(bool PH, bool WA, bool WD) : Potion(false) {	// creates a Potion since NegPotion is a Potion
	isPH = PH;		// initialize isPH to PH
	isWA = WA;		// initialize isWA to WA
	isWD = WD;		// initialize isWD to WD
}

/*
effectsPotion(object) applies the effects of the NegPotion to object
*/
void NegPotion::effectsPotion(Character* object) {
	if (isPH) {							// NegPotion is PH?
		int new_health = object->health() - 15;			// minus 15 from object's _health
		if (new_health < 0) {					// new_health less than 0 ?
			object->updateHealth(0);			// update object's _health to be 0
		}
		else {							// new_health greater than 0 ?
			object->updateHealth(new_health);		// update object's _health to be new_health
		} // if
	}
	else if (isWA) {						// NegPotion is WA?
		int new_attack = object->attack() - 5;			// minus 5 from object's _attack
		if (new_attack < 0) {					// new_attack less than 0 ?
			object->updateAttack(0);			// update object's _attack to be 0
		}
		else {							// new_attack greater than 0?
			object->updateAttack(new_attack);		// update object's _attack to be new_attack
		} // if
	}
	else if (isWD) {						// NegPotion is WD ?
		int new_defence = object->defence() - 5;		// minus 5 from object's _defence
		if (new_defence < 0) {					// new_defence less than 0 ?
			object->updateDefence(0);			// update object's _defence to be 0
		}
		else {							// new_defence greater than 0?
			object->updateDefence(new_defence);		// update object's _defecen to be new_defence
		} // if
	} // if
}

/*
potionType() returns a string indicating the type of NegPotion
*/
std::string NegPotion::potionType(){
	std::string type;
	if (isPH){							// NegPotion is PH?
		type = "Poison Health";					// it is Poison Health type
	}
	else if (isWA){							// NegPotion is WA ?
		type = "Wound Attack";					// it is Wound Attack type
	}
	else if (isWD){							// NegPotion is WD ?
		type = "Wound Defence";					// it is Wound Defence type
	} // if
	return type;
}
