/*
This is the header file for the Player Class
*/
#ifndef PLAYER_H
#define PLAYER_H
#include "character.h"

class Player : public Character {
		static const char ch = '@';
	public :
		Player(int health, int attack, int defence);
		void tick();
		virtual bool isXHostile() = 0;
		virtual bool isgHostile() = 0;
		virtual bool isMHostile() = 0;
		virtual bool isOHostile() = 0;
		virtual bool isDHostile() = 0;
		virtual void updateXHostility() = 0;
		virtual void updategHostility() = 0;
		virtual void updateMHostility() = 0;
		virtual void updateOHostility() = 0;
		virtual void updateDHostility() = 0;
};

#endif
