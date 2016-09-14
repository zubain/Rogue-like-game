/*
This is the header file for the PosPotion Class
*/
#ifndef POSITIVEPOTIONS_H
#define POSITIVEPOTIONS_H
#include "potion.h"

class PosPotion : public Potion {
		bool isRH, isBA, isBD;
	public :
		PosPotion(bool RH, bool BA, bool BD);
		void effectsPotion(Character* object);
		std::string potionType();
};
#endif
