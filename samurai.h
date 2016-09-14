/*
This is the header file for the Samurai Class
*/
#ifndef SAMURAI_H
#define SAMURAI_H
#include "player.h"

class Samurai : public Player {
		static const int health = 80, attack = 50, defence = 15;
		bool Xhostility;
		bool ghostility;
		bool Mhostility;
		bool Ohostility;
		bool Dhostility;
	public :
		Samurai();
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
