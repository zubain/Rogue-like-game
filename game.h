#ifndef GAMECC3K_H
#define GAMECC3K_H
#include "textdisplay.h"
#include "cell.h"
#include "gameobject.h"
#include "item.h"
#include "treasure.h"
#include "potion.h"
#include "character.h"
#include "player.h"
#include "enemy.h"
#include "dragon.h"
#include "stairs.h"
#include "PRNG.h"
#include "wizard.h"
#include "rhpotion.h"
#include "bapotion.h"
#include "bdpotion.h"
#include "phpotion.h"
#include "wapotion.h"
#include "wdpotion.h"
#include "gridbug.h"
#include "goblin.h"
#include "merchant.h"
#include "orc.h"
#include "knight.h"
#include "wizard.h"
#include "samurai.h"
#include <iostream>

extern PRNG prng;

class Game {
		Cell** grid;
		TextDisplay* theDisplay;
		int turns = 0, floor = 0, gold, playerRoom, r = 25, c = 79, row, col;
		int potion_count, treasure_count, enemy_count, dragon_count;
		Player* thePlayer;
		Stairs* stairs;
		Potion** potions;
		Treasure** treasures;
		Enemy** enemies;
		Dragon** dragons;
		std::string play_char;
		void defaultGameBoard(int i, int j);
		void setCell(int room);
		//bool check_surroundings(int x, int y);
		//char retrieve_surroundings(int x, int y, std::string in);
		void setPlayerLocation();
		void setStairsLocation();
		void initializePotions();
		void initializeTreasures();
		void setDragons();
		void initializeEnemies();
		void SpecifiedFileItems(int check);
		void SpecifiedFileCharacters(char ch);
		Cell* wizardAttack(int x, int y, std::string in, int i);
	public :
		Game(std::string player_type);
		Game(std::istream& in, std::string player_type);
		void initializeFloorDefault();
		void initializeFloor(std::istream& in);
		~Game();
		bool check_surroundings(int x, int y);
		char retrieve_surroundings(int x, int y, std::string in);			
		int getTurns();
		int getFloor();
		int getGold();
		int getDefence();
		int getHealth();
		int getAtt_strength();
		int getMax_health();
		void moveEnemies();
		void updatePlayer(std::string play_char);
		std::string getPlayer();
		std::string attackEnemy(int x, int y, std::string in);
		std::string getPotion(int x, int y, std::string in);
		void getTreasure(int x, int y, std::string in);
		void updateTurns();
		void updateGold(int new_gold);
		void updateFloor();
		Player* player();
		void print();
		Cell* direction_mapper(int x, int y, std::string in);
		std::string character_mapper(char ch);
		std::string weaponMapper(std::string play_char);
		void movePlayer(int x, int y, std::string in);
		std::string direction_translator(std::string in);
		std::string attackPlayer();
		std::string dragonAttack();
		std::string enemyAttack();
		std::string deathNote();
};

#endif
