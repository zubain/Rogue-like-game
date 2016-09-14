/*
This is the header file for the Stairs Class
*/
#ifndef STAIRS_H
#define STAIRS_H
#include "gameobject.h"

class Stairs : public GameObject {
		static const char ch = '>';
	public :
		Stairs();
		void stairsLocation(Cell* location);
};

#endif
