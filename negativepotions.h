/*
This is the header file for the NegPotion Class
*/
#ifndef NEGATIVEPOTIONS_H
#define NEGATIVEPOTIONS_H
#include "potion.h"

class NegPotion : public Potion {
		bool isPH, isWA, isWD;
	public :
		NegPotion(bool PH, bool WA, bool WD);
		void effectsPotion(Character* object);
		std::string potionType();
};

#endif
