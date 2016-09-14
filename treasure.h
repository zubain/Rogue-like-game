/*
This is the header file for the Treasure Class
*/
#ifndef TREASURE_H
#define TREASURE_H
#include "item.h"

class Treasure : public Item {
		bool _isDragonHoard;
		int _worth;
		static const char ch = '$';
	public :
		Treasure(bool isDragonHoard);
		bool isDragonHoard();
		int worth();
};

#endif
