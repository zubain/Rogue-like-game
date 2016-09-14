/*
This is the header file for the Item Class
*/
#ifndef ITEM_H
#define ITEM_H
#include "cell.h"
#include "gameobject.h"

class Item : public GameObject {
		bool _isTreasure, _isPotion;
	public :
		Item(bool isTreasure, bool isPotion, char ch);
		void itemLocation(Cell* location);
		bool isTreasure();
		bool isPotion();
};

#endif
