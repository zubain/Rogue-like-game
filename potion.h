/*
This is the header file for the Potion Class
*/
#ifndef POTION_H
#define POTION_H
#include "item.h"
#include "character.h"

class Potion : public Item {
		bool _isPos;
		static const char ch = '!';
	public :
		Potion(bool isPos);
		bool isPos();
		virtual void effectsPotion(Character* object) = 0;
		virtual std::string potionType() = 0;
};	

#endif
