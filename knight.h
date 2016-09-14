/*
This is the header file for the Knight Class
*/
#ifndef KNIGHT_H
#define KNIGHT_H
#include "player.h"

class Knight : public Player {
		static const int health = 100, attack = 50, defence = 50;
		bool Xhostility;
		bool ghostility;
		bool Mhostility;
		bool Ohostility;
		bool Dhostility;
	public :
		Knight();
		bool isXHostile();
		bool isgHostile();
		bool isMHostile();
		bool isOHostile();
		bool isDHostile();
		void updateXHostility();
		void updategHostility();
		void updateMHostility();
		void updateOHostility();
		void updateDHostility();
};

#endif
