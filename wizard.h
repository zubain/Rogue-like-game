/*
This is the header file for the Wizard Class
*/
#ifndef WIZARD_H
#define WIZARD_H
#include "player.h"

class Wizard : public Player {
		 static const int health = 60, attack = 25, defence = 0;
		bool Xhostility;
		bool ghostility;
		bool Mhostility;
		bool Ohostility;
		bool Dhostility;
	public :
		Wizard();
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
