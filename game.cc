/*
This file contains the code for all constructors, destructors and member routines
	for the Game Class
*/
#include "game.h"
#include <string>
#include <sstream>
#include <string>
#include <map>
		using namespace std;
	PRNG prng;

/*
defaultGameBoard(i, j) takes in two values i and j and determines what character should
	be place in the ith row and jth column of the game grid to intialize the game board
	when no game map is specified by the player
*/
void Game::defaultGameBoard(int i, int j) {
	switch(j) {
		case 0: case 78:
			grid[i][j].setCellVal(i, j, '|');
			break;
		case 1: case 77:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i,j,'-');
			}
			else {
				grid[i][j].setCellVal(i,j,' ');
			}	
			break;
		case 2:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 2 && i <= 7) {
				grid[i][j].setCellVal(i, j, '|');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 3: 
			if (i == 0 || i == 2 || i == 7 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 14 && i <= 22) {
				grid[i][j].setCellVal(i, j, '|');
			}
			else if (i >= 3 && i <= 6) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 4: case 5: case 6: case 7: case 8: case 9: case 10: case 11: case 12:
			if (i == 0 || i == 2 || i == 7 || i == 14 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 3 && i <= 6) || (i >= 15 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 13:
			if (i == 0 || i == 2 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 3 && i <= 6) || (i >= 15 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 7 || i == 14) {
				grid[i][j].setCellVal(i, j, '+');
			}
			else if (i >= 8 && i <= 13) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 14: case 15: case 16: case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24:
			if (i == 0 || i == 2 || i == 7 || i == 14 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
                        else if ((i >= 3 && i <= 6) || (i >= 15 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
			else if (i == 11) {
				grid[i][j].setCellVal(i, j, '#');
			}
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;		
		case 25:
			if (i == 0 || i == 2 || i == 7 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 14 && i <= 22) {
				if (i == 20) {
					grid[i][j].setCellVal(i, j, '+');
				}
				else {
					grid[i][j].setCellVal(i, j, '|');
				}
			}
			else if (i >= 3 && i <= 6) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 11) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 26: case 27: case 28:
			if (i == 0 || i == 2 || i == 7 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 3 && i <= 6) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 11 || i == 20) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 29:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 2 && i <= 7) {
				if (i == 4) {
					grid[i][j].setCellVal(i, j, '+');
				}
				else {
					grid[i][j].setCellVal(i, j, '|');
				}
			}
			else if (i == 11 || i == 20) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 30:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i == 4 || i == 11 || i == 20) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {	
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 31:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i == 4 || (i >= 8 && i <= 20)) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 32: case 34: case 35:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i == 4 || i == 8 || i == 16 || i == 20) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 33:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 4 && i <= 8) || i == 16 || i == 20) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 36:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i == 4 || i == 8 || i == 16) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else if (i >= 18 && i <= 22) {
				if (i == 20) {
					grid[i][j].setCellVal(i, j, '+');
				}
				else {
					grid[i][j].setCellVal(i, j, '|');
				}
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 37:
			if (i == 0 || i == 18 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 9 && i <= 13) {
				grid[i][j].setCellVal(i, j, '|');
			}
			else if (i >= 19 && i <= 21) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 4 || i == 8 || i == 16) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 38:
			if (i == 0 || i == 9 || i == 13 || i == 18 ||i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 2 && i <= 7) {
				if (i == 4) {
					grid[i][j].setCellVal(i, j, '+');
				}
				else {
					grid[i][j].setCellVal(i, j, '|');
				}
			}
			else if ((i >= 10 && i <= 12) || (i >= 19 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 8 || i == 16) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 39: case 40: case 41: case 42:
			if (i == 0 || i == 2 || i == 7 || i == 9 || i == 13 || i == 18 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 3 &&i <= 6) || (i >= 10 && i <= 12) || (i >= 19 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else if (i == 8 || i == 16) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 43:
			if (i == 0 || i == 2 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i == 7 || i == 9 || i == 13 || i == 18) {
				grid[i][j].setCellVal(i, j, '+');
			}
			else if (i == 8 || (i >= 14 && i <= 17)) {
				grid[i][j].setCellVal(i, j, '#');
			}
			else if ((i >= 3 && i <= 6) || (i >= 10 && i <= 12) || (i >= 19 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		 case 44: case 45: case 46: case 47: case 48: case 49:
                        if (i == 0 || i == 2 || i == 7 || i == 9 || i == 13 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 3 &&i <= 6) || (i >= 10 && i <= 12) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else if (i == 16) {
                                grid[i][j].setCellVal(i, j, '#');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 50:
                        if (i == 0 || i == 2 || i == 7 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
			else if (i >= 9 && i <= 13){
				grid[i][j].setCellVal(i, j, '|');
			}
                        else if ((i >= 3 &&i <= 6) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else if (i == 16) {
                                grid[i][j].setCellVal(i, j, '#');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 51: case 52: case 53:
                        if (i == 0 || i == 2 || i == 7 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 3 &&i <= 6) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                       	else if (i == 16) {
                                grid[i][j].setCellVal(i, j, '#');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 54:
                        if (i == 0 || i == 2 || i == 7 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 3 &&i <= 6) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else if (i>= 11 && i <= 16) {
                                grid[i][j].setCellVal(i, j, '#');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 55: case 56: case 57: case 58: case 59:
                        if (i == 0 || i == 2 || i == 7 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 3 &&i <= 6) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                	}                 
		       	else if (i == 11) {
                                grid[i][j].setCellVal(i, j, '#');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break; 
		case 60:
                        if (i == 0 || i == 2 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
			else if (i >= 7 && i <= 13){
				if (i == 11) {
					grid[i][j].setCellVal(i, j, '+');
				}
				else {
					grid[i][j].setCellVal(i, j, '|');
				}
			}
		case 61:
                        if (i == 0 || i == 2 || i == 13 || i == 18 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 3 &&i <= 12) || (i >= 19 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 62:
			if (i == 0 || i == 13 || i == 18 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if (i >= 2 && i <= 4) {
				grid[i][j].setCellVal(i, j, '|');
			}
			else if ((i >= 5 && i <= 12) || (i >= 19 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 63:
			if (i == 0 || i == 4 || i == 13 || i == 18 || i == 22 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 5 && i <= 12) || (i >= 19 && i <= 21)) {
				grid[i][j].setCellVal(i, j, '.');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
		case 64:
                        if (i == 0 || i == 4 || i == 13 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
			else if (i >= 15 && i <= 18) {
				grid[i][j].setCellVal(i, j, '|');
			}
                        else if ((i >= 5 && i <= 12) || (i >= 19 && i <= 21)) { 
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;		
		case 65: case 66: case 67: case 68:
                        if (i == 0 || i == 4 || i == 13 || i == 15 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 5 && i <= 12) || (i >= 16 && i <= 21)) { 
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }                
                        break;
		case 69:
                        if (i == 0 || i == 4 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
			else if (i == 13 || i == 15) {
				grid[i][j].setCellVal(i, j, '+');
			}
			else if (i == 14) {
				grid[i][j].setCellVal(i, j, '#');
			}
                        else if ((i >= 5 && i <= 12) || (i >= 16 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
			break;
		case 70:
                        if (i == 0 || i == 13 || i == 15 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if (i >= 4 && i <= 5) {
                                grid[i][j].setCellVal(i, j, '|');
                        }
                        else if ((i >= 6 && i <= 12) || (i >= 16 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 71: case 72:
                        if (i == 0 || i == 5 || i == 13 || i == 15 || i == 22 || i == 24) {
                           	grid[i][j].setCellVal(i, j, '-');
                      	}
                    	else if ((i >= 6 && i <= 12) || (i >= 16 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 73:
                        if (i == 0 || i == 13 || i == 15 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if (i >= 5 && i <= 6) {
                                grid[i][j].setCellVal(i, j, '|');
                        }
                        else if ((i >= 7 && i <= 12) || (i >= 16 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 74: case 75:
                        if (i == 0 || i == 6 || i == 13 || i == 15 || i == 22 || i == 24) {
                                grid[i][j].setCellVal(i, j, '-');
                        }
                        else if ((i >= 7 && i <= 12) || (i >= 16 && i <= 21)) {
                                grid[i][j].setCellVal(i, j, '.');
                        }
                        else {
                                grid[i][j].setCellVal(i, j, ' ');
                        }
                        break;
		case 76:
			if (i == 0 || i == 24) {
				grid[i][j].setCellVal(i, j, '-');
			}
			else if ((i >= 6 && i <= 13) || (i >= 15 && i <= 22)) {
				grid[i][j].setCellVal(i, j, '|');
			}
			else {
				grid[i][j].setCellVal(i, j, ' ');
			}
			break;
	}
}

/*
setCell(room) randomly generates which part of the room an item or character should be place at and
	mutates row and col accordingly
*/
void Game::setCell(int room) {
	if (room == 0) {				// first room ?
		row = prng(3,6);			// randomly generate from available rows
		col = prng(3,28);			// randomly generate from available columns 
	}
	else if (room == 1) {				// second room ?
		row = prng(3,12);			// randomly generate form available rows
		if (row == 3 || row == 4) {		// row is 3 or 4 ?
			col = prng(39,61);		// randomly generate from available columns
		}
		else if (row == 5) {			// row is 5 ?
			col = prng(39,69);		// randomly generate from available columns
		}	
		else if (row == 6) {			// row is 6 ?
			col = prng(39,72);		// randomly generate from available columns
		}
		else if (row >= 7 && row <= 12) {	// row is between 7 and 12 ?
			col = prng(61, 75);		// randomly generate from available columns
		} // if
	}
	else if (room == 2) {				// third room ?
		row = prng(10,12);			// randomly generate from available rows
		col = prng(38,49);			// randomly generate from available columns
	}
	else if (room == 3) {				// fourth room ?
		row = prng(15,21);			// randomly generate from available row
		col = prng(4,24);			// randomly generate from available columns
	}
	else if (room == 4) {				// fifth room ?
		row = prng(16,21);			// randomly generate from available rows
		if (row >= 16 && row <= 18) {		// rows between 16 and 18 ?
			col = prng(65,75);		// randomly generate from available columns
		}
		else if (row >= 19 && row <= 21) {	// rows between 19 and 21 ?
			col = prng(37,75);		// randomly generate from between available columns
		} // if
	}
	if (grid[row][col].isObject()) {		// rowth row and colth colof grid has a GameObject ?
		setCell(room);				// randomly generate again
	} // if
}

/*
setPlayerLocation() randomly assigns the player's location in the game when the player
	did not specify a game map
*/
void Game::setPlayerLocation() {
	playerRoom = prng(4);				// randomly select a room
	setCell(playerRoom);				// randomly select a spot in the room
	thePlayer->Character::move(&grid[row][col]);	// move the player to that spot
	grid[row][col].addObject(thePlayer);		// add player onto the Cell of that spot
} 

/*
setStairsLocation() randomly assigns the stairs to a room in which the player is not in 
	if the player did not specify a game map
*/
void Game::setStairsLocation() {
	int stairs_room = prng(4);				// randomly select a room
	stairs = new Stairs;					// create a new Stairs
	if (stairs_room == playerRoom) {			// player is in the room selected ?
		delete stairs;					// delete the creates stairs
		Game::setStairsLocation();			// randomly generate a location again
	}
	else {							// player is not in the room selected ?
		setCell(stairs_room);				// randomly select a spot in the room
		stairs->stairsLocation(&grid[row][col]);	// set stairs location to that spot
		grid[row][col].addObject(stairs);		// add stairs onto the Cell of that spot
	}
}

/*
initializaPotions() randomly initializes potion types and also potion locations in the game when
	the player did not specify a game map
*/
void Game::initializePotions() {
	potions = new Potion*[10];				// dynamically allocate an array of pointers to Potion of size 10
	potion_count = 0;					// count potion created
	int set_potion, potion_room;				// variables used for random generation
	while (true) {						// keep looping until enough potions have been created
		if (potion_count == 10) break;			// 10 potions have been created ? break
		potion_room = prng(4);				// randomly select a room for the potion
		set_potion = prng(5);				// randomly select a Potion type
		setCell(potion_room);				// randomly select a spot in the room for the potion to be in
		if (set_potion == 0) {				// set_potion is 0 ?
			potions[potion_count] = new RH;		// create a new RH Potion
		}
		else if (set_potion == 1) {			// set_potion is 1 ?
			potions[potion_count] = new BA;		// create a new BA Potion
		}
		else if (set_potion == 2) {			// set_potion is 2 ?
			potions[potion_count] = new BD;		// create a new BD Potion
		}
		else if (set_potion == 3) {			// set_potion is 3 ?
			potions[potion_count] = new PH;		// create a new PH Potion
		}
		else if (set_potion == 4) {			// set_potion is 4 ?
			potions[potion_count] = new WA;		// create a new WA Potion
		}
		else if (set_potion == 5) {			// set_potion is 5 ?
			potions[potion_count] = new WD;		// create a new WD Potion
		}
		potions[potion_count]->Item::itemLocation(&grid[row][col]);	// set newly created Potion location to be the spot that has just been generated
		grid[row][col].addObject(potions[potion_count]);		// add newly created Potion onto the Cell of that spot
		potion_count += 1;				// increase potion_count by 1
	} // while
}

/*
initializeTreasures() randomly initialized Treasures and also treasure locations in the game when
	the player did not specify a game map
*/
void Game::initializeTreasures() {
	treasures = new Treasure*[10];							// dynamically allocate a new array of pointer to Treasure of size 10
	treasure_count = 0;								// count treasures created
	int set_treasure, treasure_room;						// set variables for random generation
	while (true) {									// keep looping until enough treasures have been created
		if (treasure_count == 10) break;					// 10 treasures have been created ? break
		treasure_room = prng(4);						// randomly select a room for the treasure to be in
		set_treasure = prng(7);							// randomly select the type of treasure to be created
		setCell(treasure_room);							// randomly select a spot in that room for the treasure to be in
		if (!check_surroundings(row,col)) {					// no other GameObject within a one block radius of the selected spot ?
			if (set_treasure >= 0 && set_treasure <= 6) {			// set_treasure is between 0 and 6 ?
				treasures[treasure_count] = new Treasure(false);	// create a new treasure
			}
			else if (set_treasure == 7) {					// set_treasure is 7 ?
				treasures[treasure_count] = new Treasure(true);		// create a dragon hoard
				dragon_count += 1;					// increase the number of dragons needed
			}// if
			treasures[treasure_count]->Item::itemLocation(&grid[row][col]); // set newly created treasure location to be the spot that has just been generated
			grid[row][col].addObject(treasures[treasure_count]);		// add newly created treasure onto the Cell of that spot
			treasure_count += 1;						// increase treasure count by 1
		} // if
	} // while
	if (dragon_count > 0) {								// dragons are needed  ?
		dragons = new Dragon*[dragon_count];					// dynamically allocate a new array of pointers to Dragon of size number of dragons needed
	} // if
}

/*
setDragons() sets a Dragon within a one block radius of a dragon hoard if a player
	did not specify a game map
*/
void Game::setDragons() {
	int set_dragon, x, y, count = 0; 
	dragon_count = 0; 
	while (true) {							// loop until all treasures have been examined
		if (count == treasure_count) break;			// count is equal to the number of treasures available ? break				
		if (treasures[count]->isDragonHoard()) {		// current treasure is a dragon hoard ?
			x = treasures[count]->GameObject::x();		// access x-coordinate of the dragon hoard
			y = treasures[count]->GameObject::y();		// access y-coordinate of the dragon hoard
			set_dragon = prng(7);				// randomly select a spot for the dragon to be at
			switch (set_dragon) {				// check value of the spot
				case 0:					// set_dragon is 0 ?
					x = x-1;			// change coordinates to the top left spot among the one block radius
					y = y-1;
					break;				// exit switch
				case 1:					// set_dragon is 1 ?
					x = x-1;			// change coordinates to the spot one row above the dragon hoard
					break;				// exit switch
				case 2:					// set_dragon is 2 ?
					x = x-1;			// change coordinates to the top right spot among the one block radius
					y = y+1;			
					break;				// exit switch
				case 3:					// set_dragon is 3?
					y = y-1;			// change coordinates to the spot on the left of the dragon hoard
					break;				// exit switch
				case 4:					// set_dragon is 4 ?
					y = y+1;			// change coordinates to the spot on the right of the dragon hoard
					break;				// exit switch
				case 5:					// set_dragon is 5 ?
					x = x+1;			// change coordinates to the bottom left spot among the one block radius
					y = y-1;	
					break;				// exit switch
				case 6:					// set_dragon is 6 ?
					x = x+1;			// change coordinates to the row below the dragon hoard
					break;				// exit switch
				case 7:					// set_dragon is 7 ?
					x = x+1;			// change coordinates to the bottom right spot among the one block radius
					y = y+1;
					break;				// exit switch
			} // switch
			if (grid[x][y].display() == '|' || grid[x][y].display() == '-');	// location generated is a barrier ? do not do anything
			else {									// location generated is not a barrier ?
				dragons[dragon_count] = new Dragon;				// create a new Dragon
				dragons[dragon_count]->Character::move(&grid[x][y]);		// move Dragon to the generated spot
				grid[x][y].addObject(dragons[dragon_count]);			// add Dragon to the Cell of the spot
				dragon_count += 1;						// incrase dragon_count by 1
				count += 1;							// increase count by 1
			} // if
		}
		else {							// treasure not a dragon hoard ?
			count += 1;					// increase count by 1
		} // if
	} // while
}

/*
initializeEnemies() randomly generates enemies and their location in the game when
	the player did not specify a game map
*/
void Game::initializeEnemies() {
	enemies = new Enemy*[20];						// dynamically allocate an array of pointer to Enemy of size 20
	enemy_count = 0;							// count enemies created
	int set_enemies, enemy_room;						// set variables for random generation
	while (true) {								// loop until enough enemies have been created
		if (enemy_count == 20) break;					// 20 enemies have been created ? break
		enemy_room = prng(4);						// randomly generate enemy room
		set_enemies = prng(5);						// randomly decide new enemy type
		setCell(enemy_room);						// randomly decide enemy's spot in the room
		if (set_enemies == 0 || set_enemies == 1) {			// set_enemies is 0 or 1 ?
			enemies[enemy_count] = new GridBug;			// create a new GridBug
		}						
		else if (set_enemies == 2 || set_enemies == 3) {		// set_enemies is 2 or 3 ?
			enemies[enemy_count] = new Goblin;			// create a new Goblin
		}
		else if (set_enemies == 4) {					// set_enemies is 4 ?
			enemies[enemy_count] = new Orc;				// create a new Orc
		}
		else if (set_enemies == 4) {					// set_enemies is 4 ?
			enemies[enemy_count] = new Orc;				// create a new Orc
		}
		else if (set_enemies == 5) {					// set_enemies is 5 ?
			enemies[enemy_count] = new Merchant;			// create a new Merchant
		} // if
		enemies[enemy_count]->Character::move(&grid[row][col]);		// move the enemy to the spot generated
		grid[row][col].addObject(enemies[enemy_count]);			// add enemy to the Cell of the spot
		enemy_count += 1;						// increase enemy count by 1
	} // while
}

/*
SpecifiedFileItems(check) creates items according to the player specified game map
*/
void Game::SpecifiedFileItems(int check) {
	if (check >= 0 && check <= 5) {						// check is between 0 and 5 ?
		potion_count += 1;						// item is a potion, increase potion count by 1
		Potion** potion_arr = new Potion*[potion_count];		// create new array of potions
		if (potion_count > 1) {
			for (int i = 0; i < potion_count-1; i += 1) {			// loop through old array of potions
				potion_arr[i] = potions[i];				// copy potions over to new array
			} // for
			delete [] potions;
		}
		switch (check) {
			case 0 :						// check is 0 ?
				potion_arr[potion_count-1] = new RH;		// create new RH Potion
				break;               				// exit switch
			case 1 :						// check is 1 ?
				potion_arr[potion_count-1] = new BA;		// create new BA Potion
				break;						// exit switch
			case 2 :						// check is 2 ?
				potion_arr[potion_count-1] = new BD;		// create new BD Potion
				break;						// exit switch
			case 3 : 						// check is 3 ?
				potion_arr[potion_count-1] = new PH;		// create new PH Potion
				break;						// exit switch
			case 4 :						// check is 4 ?
				potion_arr[potion_count-1] = new WA;		// create new WA Potion
				break;						// exit switch
			case 5 :						// check is 5 ?
				potion_arr[potion_count-1] = new WD; 		// create new WD Potion
				break;						// exit switch
		} // switch
		potions = potion_arr;						// let potions array equal new potion array
	}
	else if (check == 6 || check == 7) {					// check is either 6 or 7 ?
		treasure_count += 1;						// item is a treasure, increasure treasure count by 1
		Treasure** treasure_arr = new Treasure*[treasure_count];	// create new array of treasure
		if (treasure_count > 1) {
			for (int i = 0; i < treasure_count-1; i += 1) {			// loop through old array of treasures
				treasure_arr[i] = treasures[i];				// copy treasures over to new array
			} // for
			delete [] treasures;
		}
		switch (check) {
			case 6 :							// check is 6 ?
				treasure_arr[treasure_count-1] = new Treasure(false);	// create a new treasure that is not a dragon hoard
				break;							// exit switch
			case 7 :							// check is 7 ?
				treasure_arr[treasure_count-1] = new Treasure(true);	// create a dragon hoard
				break;							// exit switch
		} // switch
		treasures = treasure_arr;						// let treasures array equal new array
	} // if
}

/*
SpecifiedFileCharacter(ch) creates new Characters according to the user specified game map
*/
void Game::SpecifiedFileCharacters(char ch) {
	if (ch == 'D') {							// ch is a 'D' ?
		dragon_count += 1;						// Character is a Dragon
		Dragon** dragon_arr = new Dragon*[dragon_count];		// create new array of dragons
		if (dragon_count > 1) {
			for (int i = 0; i < dragon_count-1; i +=1 ) {			// loop through old array of dragons
				dragon_arr[i] = dragons[i];				// copy dragons over to new array
			} // for
			delete [] dragons;
		}
		dragon_arr[dragon_count-1] = new Dragon;			// create a new Dragon
		dragons = dragon_arr;						// let dragons array equal new dragons array
	}
	else {									// ch not a 'D' ?
		enemy_count += 1;						// Character is another type of enemy
		Enemy** enemy_arr = new Enemy*[enemy_count];			// create new array of enemies
		if (enemy_count > 1) {
			for (int i = 0; i < enemy_count-1; i += 1) {			// loop through old array of enemies
				enemy_arr[i] = enemies[i];				// copy enemies over to new array
			} // for
			delete [] enemies;
		}
		switch(ch) {							
			case 'X' :						// ch is 'X' ?
				enemy_arr[enemy_count-1] = new GridBug;		// enemy is a GridBug
				break;						// exit switch
			case 'g' :						// ch is 'g' ?
				enemy_arr[enemy_count-1] = new Goblin;		//enemy is a Goblin
				break;						// exit switch
			case 'M' :						// ch is a 'M' ?
				enemy_arr[enemy_count-1] = new Merchant;	// enemy is a Merchant
				break;						//exit switch
			case 'O' :						// ch is a 'O' ?
				enemy_arr[enemy_count-1] = new Orc;		// enemy is a Orc
				break;						// exit switch
		} // switch
		enemies = enemy_arr;						// let enemies array equal new enemy array
	} // if
}

/*
Game(player_type) is the constructor of the Game Class where it creates a new Player type
	according to player_type
*/
Game::Game(string player_type) {
	 if (player_type == "w") {
		thePlayer = new Wizard;
                updatePlayer("wizard");
        }
        else if (player_type == "k") {
                thePlayer = new Knight;
                updatePlayer("knight");
        }
        else if (player_type == "s") {
                thePlayer = new Samurai;
                updatePlayer("samurai");
        }
        gold = 0;					// initial gold is zero
	initializeFloorDefault();			// intialize game layout, items and characters
}
		
/*
Game(in, player_type) is a game constructor where in connects to a player
	specified game map and creates a new Player type according to player_type
*/
Game::Game(istream& in, string player_type) {
	if (player_type == "w") {
		thePlayer = new Wizard;
		updatePlayer("wizard");
	}
	else if (player_type == "k") {
		thePlayer = new Knight;
		updatePlayer("knight");
	}
	else if (player_type == "s") {
		thePlayer = new Samurai;
		updatePlayer("samurai");
	}
	gold = 0;					// intial gold is 0
	initializeFloor(in);				// intialize game layout according to player specified game map
}

/*
initializeFloorDefault() initialized the game layout, items and characters when the game
	is started without a palyer specified game map
*/
void Game::initializeFloorDefault() {
	if (floor != 0) {
		// floor is not 0, delete everything that was created from previous floors
                for (int i = 0; i < r; i += 1) {
                        delete [] grid[i];
                }
                delete [] grid;
                for (int i = 0; i < potion_count; i += 1) {
                        delete potions[i];
                }
                delete [] potions;
                for (int i = 0; i < treasure_count; i += 1) {
                        delete treasures[i];
                }
                delete [] treasures;
                for (int i = 0; i < enemy_count; i += 1) {
                        delete enemies[i];
                }
                delete [] enemies;
                for (int i = 0; i < dragon_count; i += 1) {
                        delete dragons[i];
                }
                delete [] dragons;
                delete stairs;
                delete theDisplay;
        }
        else {
		// floor is 0, increase floor by 1
                floor += 1;
        } // if
        turns += 1;								// increase turns by 1
        theDisplay = new TextDisplay;						// create a new display
        grid = new Cell*[r];							// create a new grid
        potion_count = treasure_count = enemy_count = dragon_count = 0;		// reset all items and characters counter
	for (int i = 0; i < r; i += 1) {					// intialize game board
		grid[i] = new Cell[c];
		for (int j = 0; j < c; j += 1) {
			defaultGameBoard(i,j);					// initialize state of the cell
			theDisplay->notify(i, j, grid[i][j].display());		// notify display about changes
			grid[i][j].addDisplay(theDisplay);			// add display to cell
		}
	}
	setPlayerLocation();							// intialize player location
	setStairsLocation();							// initialize stairs location
	initializeTreasures();							// intialize treasures
	setDragons();								// set dragons
	initializePotions();							// intialize potions
	initializeEnemies();							// intialize enemies
}

/*
initializeFloor(in) intializes the game using the the player specified game map from in
*/
void Game::initializeFloor(istream& in) {
	if (floor != 0) {
		// floor is not zero, delete all items and characters created from previous floor
		for (int i = 0; i < r; i += 1) {
			delete [] grid[i];
		}
		delete [] grid;
		for (int i = 0; i < potion_count; i += 1) {
			delete potions[i];
		}
		delete [] potions;
		for (int i = 0; i < treasure_count; i += 1) {
			delete treasures[i];
		}
		delete [] treasures;
		for (int i = 0; i < enemy_count; i += 1) {
			delete enemies[i];
		}
		delete [] enemies;
		for (int i = 0; i < dragon_count; i += 1) {
			delete dragons[i];
		}
		delete [] dragons;
		delete stairs;
		delete theDisplay;
	}
	else {
		// floor is 0, increase floor by 1
		floor += 1;
	}
	turns += 1;								// update turns
	theDisplay = new TextDisplay;						// create new display
	grid = new Cell*[r];							// create new grid
	char ch;								// intialize char to be read in
	potion_count = treasure_count = enemy_count = dragon_count = 0;		// reset counters for items and characters
	string readline, s;							// intialize strings to be read in
	int check;								// check for integers
	for (int i = 0; i < r; i += 1) {					// traverse through every single row of the grid
		grid[i] = new Cell[c];						// create new array of cells						
		getline(in, readline);						// get line from in file
		for (int j = 0; j < c; j += 1) {				// traverse through every column of the line
			ch = readline[j];					// let ch be the character of one particular column
			string s = readline.substr(j,1);			// gets string of ch
			stringstream ss(s);					// connect stringstream with s
			if (ss >> check) {					// is s is an integer
				grid[i][j].setCellVal(i, j, '.');		// intialize cell	
				SpecifiedFileItems(check);			// intialize item
				if (check >= 0 && check <= 5) {
					potions[potion_count-1]->Item::itemLocation(&grid[i][j]);
					grid[i][j].addObject(potions[potion_count-1]);
				}
				else if (check == 6 || check == 7) {
					treasures[treasure_count-1]->Item::itemLocation(&grid[i][j]);
					grid[i][j].addObject(treasures[treasure_count-1]);
				}
			}
			else {							// s not an integer ?
				if (ch == '|' || ch == '-' || ch == '#' || ch == '+' || ch == '.' || ch == ' ') {	// barriers
						grid[i][j].setCellVal(i, j, ch);
				}
				else {								// not barriers
					grid[i][j].setCellVal(i, j, '.');			// intialize cell
					if (ch == '@') {						// ch a player
						thePlayer->Character::move(&grid[i][j]);
						grid[i][j].addObject(thePlayer);
					}
					else if (ch == '>') {					// ch a stairs
						stairs = new Stairs;
						stairs->stairsLocation(&grid[i][j]);
						grid[i][j].addObject(stairs);
					}
					else {							// ch an enemy
						SpecifiedFileCharacters(ch);
						if (ch == 'D') {					// ch a dragon, add to dragons stack
							dragons[dragon_count-1]->Character::move(&grid[i][j]);
							grid[i][j].addObject(dragons[dragon_count-1]);
						}
						else {							// ch other type of enemy, add to enemy stack
							enemies[enemy_count-1]->Character::move(&grid[i][j]);
							grid[i][j].addObject(enemies[enemy_count-1]);
						}
					}
				}
			}
			theDisplay->notify(i, j, grid[i][j].display());				// notify display about changes
			grid[i][j].addDisplay(theDisplay);					// add display to cell
		}
	}
	
}

/*
~Game() is the destructor of the Game Class. It deletes all items and characters that were created
	during the game
*/
Game::~Game() {
	for(int i = 0; i < r; i += 1) {
		delete [] grid[i];
	}
	delete [] grid;
	if (potion_count > 1) {
		for (int i = 0; i < potion_count; i += 1) {
			delete potions[i];
		}
		delete [] potions;
	}
	if (enemy_count > 1) {
		for (int i = 0; i < enemy_count; i += 1) {
			delete enemies[i];
		}
		delete [] enemies;
	}
	if (treasure_count > 1) {
		for (int i = 0; i < treasure_count; i += 1) {
			delete treasures[i];
		}
		delete [] treasures;
	}
	if (dragon_count > 1) {
		for (int i = 0; i < dragon_count; i += 1) {
			delete dragons[i];
		}
		delete [] dragons;
	}
	delete theDisplay;
	delete stairs;
	delete thePlayer;
}

/*
check_surroundings(x,y) checks to see if there is an object within a one block radius of the Cell
	of coordinates x, y
*/
bool Game::check_surroundings(int x, int y) {
	return ((grid[x-1][y-1].isObject()) || (grid[x-1][y].isObject()) ||
		(grid[x-1][y+1].isObject()) || (grid[x][y-1].isObject()) ||
		(grid[x][y+1].isObject()) || (grid[x+1][y-1].isObject()) ||
		(grid[x+1][y].isObject()) || (grid[x+1][y+1].isObject()));
}


// NEED to find precise row/column location where player has been spawned, in order
// to use the grid to check surroundings
char Game::retrieve_surroundings(int x, int y, string in){  // this implementation does not account for 
	// the special characteristics of '$'
	return direction_mapper(x,y,in)->display();
}
/*
getTurns() returns the number of turns the player has used
*/
int Game::getTurns() {
	return turns;
}

/*
getFloor() returns the floor the player is at
*/
int Game::getFloor() {
	return floor;
}

/*
getGold() returns the amount of gold the player has collected
*/
int Game::getGold() {
	return gold;
}

/*
getDefence() returns the defence stats of the Player
*/
int Game::getDefence(){
	return thePlayer->defence();
}

/*
getHealth() returns the health stats of the Player
*/
int Game::getHealth(){
	if (thePlayer->health() <= 0)
		return 0;
	else return thePlayer->health();
}

/*
getAtt_strength() returns the attack stats of the Player
*/
int Game::getAtt_strength(){
	return thePlayer->attack();
}

/*
getMax_health() returns the maximum health of the Player
*/
int Game::getMax_health(){
	return thePlayer->max_health();
}

/*
moveEnemies() controls the enemy movement in the gam
*/
void Game::moveEnemies(){
	for (int i = 0; i < enemy_count; i++){
		//Cell* posArr[8];  // array of positions
		//int countObj = -1;
		if (enemies[i]->health() <= 0){ // if enemy is dead, do nothing
			continue;
		}
		else if (enemies[i]->display() == 'X'){  // if enemy is a grid bug
			// may need an extreme case where each of the 4 possible positions is occupied! 
			repeat_gbroutine:
			int movegb = prng(3);
			int gbx = enemies[i]->x();
			int gby = enemies[i]->y();
			Cell* gbcurr_cell = &grid[gbx][gby];
			switch (movegb) {
				case 0: 
					gbx = gbx-1;  // north
					break;
				case 1:
					gby = gby-1;  // west
					break;
				case 2:
					gby = gby+1;  // east
					break;
				case 3:
					gbx = gbx+1;   // south
					break;
			}
			if (grid[gbx][gby].display() == '|' || grid[gbx][gby].display() == '+' || grid[gbx][gby].display() == '#'
				|| grid[gbx][gby].display() == '-' || grid[gbx][gby].isObject()){
				goto repeat_gbroutine;
			}
			else {
				enemies[i]->move(&grid[gbx][gby]);
				grid[gbx][gby].addObject(enemies[i]);
				gbcurr_cell->removeObject();
			}
		}

		else {   // any other enemy
			// may need an extreme case where each of the 4 possible positions is occupied! 
			repeat_routine:
			int moveto = prng(7);
			int x = enemies[i]->x();
			int y = enemies[i]->y();
			Cell* curr_cell = &grid[x][y];
			// movement algorithm the same as set_dragons functions
			switch (moveto) {
				case 0:
					x = x-1;
					y = y-1;
					break;
				case 1:
					x = x-1;
					break;
				case 2:
					x = x-1;
					y = y+1;
					break;
				case 3:
					y = y-1;
					break;
				case 4:
					y = y+1;
					break;
				case 5:
					x = x+1;
					y = y-1;
					break;
				case 6:
					x = x+1;
					break;
				case 7:
					x = x+1;
					y = y+1;
					break;
			}
			if (enemies[i]->display() == 'g'){    // if enemy is a goblin
				if (grid[x][y].display() == '.'){
					enemies[i]->move(&grid[x][y]);
					grid[x][y].addObject(enemies[i]);
					curr_cell->removeObject();
				}
				else if (grid[x][y].display() == '!'){
					for (int i = 0; i < potion_count; i++){
						int pot_row = potions[i]->x();
						int pot_col = potions[i]->y();
						if (grid[x][y].x() == pot_row && grid[x][y].y() == pot_col){
							// obtain the potion
							potions[i]->effectsPotion(enemies[i]);
							grid[x][y].removeObject();
							if (enemies[i]->health() <= 0){ // if enemy is dead after drinking potion
								curr_cell->removeObject(); // remove enemy from board
							}
							else {   // if goblin is still alive
								enemies[i]->move(&grid[x][y]);
								grid[x][y].addObject(enemies[i]);
								curr_cell->removeObject();
							}
						}
					}
				}
				else {
					// may need to add a special case where all 8 possible spots are occupied
					goto repeat_routine;
				}
			}
			else {    // if enemy is an Orc or merchant
				if (grid[x][y].display() == '|' || grid[x][y].display() == '-' || grid[x][y].display() == '+' 
					|| grid[x][y].display() == '#' || grid[x][y].isObject()){
					goto repeat_routine;
			}
			else {
				enemies[i]->move(&grid[x][y]);
				grid[x][y].addObject(enemies[i]);
				curr_cell->removeObject();
			}
		}
	}
}
}

/*
updatePlayer(new_player) sets play_char to be new_player
*/
void Game::updatePlayer(string new_player){
	play_char = new_player;
}

/*
getPlayer() returns play_char
*/
string Game::getPlayer(){
	return play_char;
}

/*
attackEnemy(x, y, in) controls the attack of the player towards all other enemies
*/
string Game::attackEnemy(int x, int y, string in){
	for (int i = 0; i < enemy_count; i++){
		int en_row = enemies[i]->x();
		int en_col = enemies[i]->y();
		int en_health, en_damage;
		string enemytype, en_statement, sam_hostile_statement, merchant_statement;
		if (direction_mapper(x,y,in)->x() == en_row && direction_mapper(x,y,in)->y() == en_col){
			if (getPlayer() == "Wizard"){
				if (wizardAttack(x,y,in,i) == NULL){
					return "There is nothing to attack!";
				}
				else {
					wizardAttack(x,y,in,i)->removeObject();
					grid[x][y].addObject(thePlayer);
					en_health = enemies[i]->health();
					en_damage = enemies[i]->damage();
					enemytype = character_mapper(direction_mapper(x,y,in)->display());
					en_statement = "You attack the " + enemytype + " with your " + weaponMapper(getPlayer()) +  " for " + to_string(en_damage) + " damage!";
				}
			}
			else {
				thePlayer->attack(enemies[i]);
				if (enemies[i]->display() == 'M' && !thePlayer->isMHostile()){
					thePlayer->updateMHostility();
					merchant_statement = "This is an act of war to every Merchant!";
				}
				if (getPlayer() == "Samurai"){
					if (enemies[i]->display() == 'X' && !thePlayer->isXHostile()){
						thePlayer->updateXHostility();
						sam_hostile_statement = "This is an act of war to every Grid Bug!";
					}
					if (enemies[i]->display() == 'g' && !thePlayer->isgHostile()){
						thePlayer->updategHostility();
						sam_hostile_statement = "This is an act of war to every Goblin!";
					}
				/*if (enemies[i]->display() == 'M' && !thePlayer->isMHostile()){
					thePlayer->updateMHostility();
					sam_hostile_statement = "This is an act of war to every Merchant!";
				}*/
					if (enemies[i]->display() == 'O' && !thePlayer->isOHostile()){
						thePlayer->updateOHostility();
						sam_hostile_statement = "This is an act of war to every Orc!";
					}
				}
				en_health = enemies[i]->health();
				en_damage = enemies[i]->damage();
				enemytype = character_mapper(direction_mapper(x,y,in)->display());
				en_statement = "You attack the " + enemytype + " with your " + weaponMapper(getPlayer()) +  " for " + to_string(en_damage) + " damage!";
			}
			if (en_health <= 0){
				string death_note = "The " + enemytype + " has died.";
				direction_mapper(x,y,in)->removeObject();
				// generate random potion functionality needed if enemy is a Grid Bug
				if (enemytype == "Grid Bug"){
					potion_count += 1;
					Potion** potion_arr = new Potion*[potion_count];
					if (potion_count > 1) {
						for (int i = 0; i < potion_count-1; i += 1) {
							potion_arr[i] = potions[i];
						}
						delete [] potions;
					}
					potions = potion_arr;
					int set_new_potion = prng(5);
					if (set_new_potion == 0) {
						potions[potion_count-1] = new RH;
					}
					else if (set_new_potion == 1) {
						potions[potion_count-1] = new BA;
					}
					else if (set_new_potion == 2) {
						potions[potion_count-1] = new BD;
					}
					else if (set_new_potion == 3) {
						potions[potion_count-1] = new PH;
					}
					else if (set_new_potion == 4) {
						potions[potion_count-1] = new WA;
					}
					else if (set_new_potion == 5) {
						potions[potion_count-1] = new WD;
					}
					potions[potion_count-1]->Item::itemLocation(&grid[en_row][en_col]);
					grid[en_row][en_col].addObject(potions[potion_count-1]);
				}
				else if (enemytype == "Goblin" || enemytype == "Orc" || enemytype == "Merchant"){
					// generate 10GP treasure if enemy is M, O, g
					treasure_count += 1;
					Treasure** treasure_arr = new Treasure*[treasure_count];
					if (treasure_count > 1) {
						for (int i = 0; i < treasure_count-1; i += 1) {
							treasure_arr[i] = treasures[i];
						}
						delete [] treasures;
					}
					treasures = treasure_arr;
					treasures[treasure_count-1] = new Treasure(false);
					treasures[treasure_count-1]->Item::itemLocation(&grid[en_row][en_col]);
					grid[en_row][en_col].addObject(treasures[treasure_count-1]);
				}
				if (!sam_hostile_statement.empty()){
					return sam_hostile_statement+"\n"+en_statement+"\n"+death_note;
				}
				else {
					if (!merchant_statement.empty()){
						return merchant_statement+"\n"+en_statement+"\n"+death_note;
					}
					else return en_statement+"\n"+death_note;
				}
			} 
			else {
				if (!sam_hostile_statement.empty()){
					return sam_hostile_statement+"\n"+en_statement;
				}
				else {
					if (!merchant_statement.empty()){
						return merchant_statement+"\n"+en_statement;
					}
					else return en_statement;
				}
			}
		}
	}
	for (int i = 0; i < dragon_count; i += 1) {
		int dragon_row = dragons[i]->x();
		int dragon_col = dragons[i]->y();
		string sam_dragon_statement;
		if (direction_mapper(x,y,in)->x() == dragon_row && direction_mapper(x,y,in)->y() == dragon_col) {
			thePlayer->attack(dragons[i]);
			if (getPlayer() == "Samurai" && !thePlayer->isDHostile()){
				thePlayer->updateDHostility();
				sam_dragon_statement = "This is an act of war to every Dragon!";
			}
			int dragon_health = dragons[i]->Character::health();
			int dragon_damage = dragons[i]->Character::damage();
			string enemytype = "Dragon";
			string statement = "You attack the " + enemytype + " with your " + weaponMapper(getPlayer()) +  " for " + to_string(dragon_damage) + " damage!";
			if (dragon_health <= 0) {
				string death_note = "The " + enemytype + " has died.";
				direction_mapper(x,y,in)->removeObject();
				return statement + "\n" + death_note;
			}
			else {
				if (!sam_dragon_statement.empty()){
					return sam_dragon_statement+"\n"+statement;
				}
				else return statement;
			}
		}
	}
	return "No enemy was found";
}

	Cell* Game::wizardAttack(int x, int y, string in, int i){
		Cell* curr_cell;
		Cell* new_cell;
	//Cell* treasure_cell;
	//Cell* potion_cell;
		Cell* init_cell = &grid[x][y];
		string message;
	//int potion_tracker = -1;
	//int treasure_tracker = -1;
		int en_row = enemies[i]->x();
		int en_col = enemies[i]->y();
		map<string, int> num_dir;
		num_dir["nw"] = 0;
		num_dir["no"] = 1;
		num_dir["ne"] = 2;
		num_dir["we"] = 3;
		num_dir["ea"] = 4;
		num_dir["sw"] = 5;
		num_dir["so"] = 6;
		num_dir["se"] = 7;

		while(direction_mapper(x,y,in)->x() != en_row && direction_mapper(x,y,in)->y() != en_col){
			if (direction_mapper(x,y,in)->display() == '|' || direction_mapper(x,y,in)->display() == '-' || direction_mapper(x,y,in)->display() == ' '){
				return new_cell = NULL;
			}
			switch(num_dir[in]){
				case 0:
				x = x-1;
				y = y-1;
				break;
				case 1:
				x = x-1;
				break;
				case 2:
				x = x-1;
				y = y+1;
				break;
				case 3:
				y = y-1;
				break;
				case 4:
				y = y+1;
				break;
				case 5:
				x = x+1;
				y = y-1;
				break;
				case 6:
				x = x+1;
				break;
				case 7:
				x = x+1;
				y = y+1;
				break;
			}
			curr_cell = &grid[x][y];
			new_cell = direction_mapper(x,y,in);
		/*if (new_cell->display() == '$'){
			for (int i = 0; i < treasure_count; i++){
				int tr_row = treasures[i]->x();
				int tr_col = treasures[i]->y();
				if (new_cell->x() == tr_row && new_cell->y() == tr_col){
					treasure_tracker = i;
					treasure_cell = &grid[tr_row][tr_col];
					//item_cell->removeObject();
					thePlayer->Character::move(new_cell);
					new_cell->addObject(thePlayer);
					curr_cell->removeObject();
				}
			}
		}
		else if (new_cell->display() == '!'){
			for (int i = 0; i < potion_count; i++){
				int pot_row = potions[i]->x();
				int pot_col = potions[i]->y();
				if (new_cell->x() == pot_row && new_cell->y() == pot_col){
					potion_tracker = i;
					potion_cell = &grid[pot_row][pot_col];
					//item_cell->removeObject();
					thePlayer->Character::move(new_cell);
					new_cell->addObject(thePlayer);
					curr_cell->removeObject();
				}
			}
		}*/
		//else {
			thePlayer->Character::move(new_cell);
			new_cell->addObject(thePlayer);
			curr_cell->removeObject();
		//}
		}
		thePlayer->attack(enemies[i]);
	//new_cell->removeObject();
		init_cell->addObject(thePlayer);
	/*if (potion_count != -1){
		potion_cell->addObject(potions[potion_tracker]);
	}
	if (treasure_count != -1){
		treasure_cell->addObject(treasures[treasure_tracker]);
	}*/
		return new_cell;
	}


/*
getPotion(x, y, in) traverses the Potion stack and applies the effects of the Potion that the Player used onto the Player
*/
string Game::getPotion(int x, int y, string in){
	string pot_type;
	for (int i = 0; i < potion_count; i++){
		int pot_row = potions[i]->x();
		int pot_col = potions[i]->y();
		if (direction_mapper(x,y,in)->x() == pot_row && direction_mapper(x,y,in)->y() == pot_col){
			// obtain the potion
			potions[i]->effectsPotion(thePlayer);
			pot_type = "You chug the " + potions[i]->potionType() + " potion.";
			thePlayer->tick();
			direction_mapper(x,y,in)->removeObject();
		}
	}
	return pot_type;
}

/*
getTreasure(x, y, in) traverses through the treasure stack and gives player the amount of gold he has picked up from the stack
*/
void Game::getTreasure(int x, int y, string in){
	for (int i = 0; i < treasure_count; i++){
		int tr_row = treasures[i]->x();
		int tr_col = treasures[i]->y();
		if (direction_mapper(x,y,in)->x() == tr_row && direction_mapper(x,y,in)->y() == tr_col){
			// obtain the treasure
			updateGold(treasures[i]->worth());
			thePlayer->tick();
			direction_mapper(x,y,in)->removeObject();
		}
			// return some sort of string that can be printed, perhaps?
	}
}

/*
updateTurns() increase turns by 1
*/
void Game::updateTurns() {
	turns += 1;
}

/*
updateGold(new_gold) increases gold by new_gold
*/
void Game::updateGold(int new_gold) {
	gold += new_gold;
}

/*
updateFloor() increases floor by 1
*/
void Game::updateFloor() {
	floor += 1;
}

/*
player() returns a pointer to thePlayer
*/
Player* Game::player() {
	return thePlayer;
}

/*
print() prints the game board and other relevant stats to the screen
*/
void Game::print() {
	theDisplay->print();
	cout << "\tClass: " << getPlayer() << "\tGP: " << getGold() << "\t\tFloor: " << getFloor() << endl;
	cout << "\tHP: " << getHealth() << "/" << getMax_health() << "\tAtk: " << getAtt_strength() << "\t\tDef: " << getDefence() << "%" << "\t\tTurn: " << getTurns() << endl;
	cout << endl;
	cout << "What will you do?" << endl;
}

/*
direction_mapper(x,y,in) maps to cell on the grid using in as a direction from the Cell with x and y coordinates
*/
Cell* Game::direction_mapper(int x, int y, string in){
	map<string, Cell*> dir_mapper;
	dir_mapper["nw"] = &grid[x-1][y-1];
	dir_mapper["no"] = &grid[x-1][y];
	dir_mapper["ne"] = &grid[x-1][y+1];
	dir_mapper["we"] = &grid[x][y-1];
	dir_mapper["ea"] = &grid[x][y+1];
	dir_mapper["sw"] = &grid[x+1][y-1];
	dir_mapper["so"] = &grid[x+1][y];
	dir_mapper["se"] = &grid[x+1][y+1];
	return dir_mapper[in];
}

/*
character_mapper(ch) returns the type of character ch represents
*/
string Game::character_mapper(char ch){
	map<char, string> cha_mapper;
	cha_mapper['@'] = "Player";
	cha_mapper['$'] = "Treasure";
	cha_mapper['!'] = "Potion";
	cha_mapper['X'] = "Grid Bug";
	cha_mapper['D'] = "Dragon";
	cha_mapper['O'] = "Orc";
	cha_mapper['M'] = "Merchant";
	cha_mapper['g'] = "Goblin";
	return cha_mapper[ch]; 
}

/*
weaponMapper(play_char) returns the type of weapon used by the Player
*/
string Game::weaponMapper(string play_char){
	map<string,string> weaponMapper;
	weaponMapper["Knight"] = "Sword of Segfault";
	weaponMapper["Wizard"] = "Infinite Loop Laser";
	weaponMapper["Samurai"] = "Memory Corruption Katana";
	return weaponMapper[play_char];
}

/*
movePlayer(x, y, in) moves the player from the Cell with coordinates x y to the direction in
*/
void Game::movePlayer(int x, int y, string in){
	Cell* curr_cell = &grid[x][y];
	Cell* new_cell = direction_mapper(x,y,in);
	thePlayer->Character::move(new_cell);
	new_cell->addObject(thePlayer);
	curr_cell->removeObject();

}

/*
direction_translator(in) returns the direction in full-forms instead of short forms
*/
string Game::direction_translator(string in){
	map<string, string> direction_translator;
	direction_translator["nw"] = "north-west.";
	direction_translator["no"] = "north.";
	direction_translator["ne"] = "north-east.";
	direction_translator["we"] = "west.";
	direction_translator["ea"] = "east.";
	direction_translator["sw"] = "south-west.";
	direction_translator["so"] = "south.";
	direction_translator["se"] = "south-east.";
	return direction_translator[in];
}

// this routine governs whether and when enemies attack players
string Game::attackPlayer(){
	//return enemyAttack()+dragonAttack();
	return enemyAttack();
}

/*
dragonAttack() controls the dragon's attack movements towards the Player
*/
string Game::dragonAttack(){
	string dragon_statement;
	for (int i = 0; i < dragon_count; i++){    // dragon attack sequence, needs some fixes
		int dr_row = dragons[i]->GameObject::x();
		int dr_col = dragons[i]->GameObject::y();
		if (getPlayer() == "Samurai" && !thePlayer->isDHostile()){
			return dragon_statement;
		}
		if (grid[dr_row-1][dr_col].display() == '@' || grid[dr_row][dr_col-1].display() == '@'
			|| grid[dr_row][dr_col+1].display() == '@' || grid[dr_row+1][dr_col].display() == '@'
			|| grid[dr_row-1][dr_col-1].display() == '@' || grid[dr_row-1][dr_col+1].display() == '@'
			|| grid[dr_row+1][dr_col-1].display() == '@' || grid[dr_row+1][dr_col+1].display() == '@'){
			dragons[i]->Character::attack(thePlayer);
	}
}
int drplayer_damage = thePlayer->damage();
dragon_statement = "\nThe evil dragon strikes you for " + to_string(drplayer_damage) + "damage!";
return dragon_statement;
}

/*
enemyAttack controls the enemy's attack movements towards the Player
*/
string Game::enemyAttack(){
	// for now we assume that only one enemy attacks the player at a time
	string att_statement;
	for (int i = 0; i < enemy_count; i++){
		int en_row = enemies[i]->x();
		int en_col = enemies[i]->y();
		if (enemies[i]->health() <= 0);
		if (enemies[i]->display() == 'M' && !thePlayer->isMHostile()){
			return att_statement;
		}
		else {
			if (enemies[i]->display() == 'X'){   // if enemy is a gridbug (no diagonal attacks)
				if (getPlayer() == "Samurai" && !thePlayer->isXHostile()){
					return att_statement;
				}
				if (grid[en_row-1][en_col].display() == '@'
					|| grid[en_row][en_col-1].display() == '@'
					|| grid[en_row][en_col+1].display() == '@'
					|| grid[en_row+1][en_col].display() == '@'){
					enemies[i]->attack(thePlayer);
				int player_damage = thePlayer->damage();
				att_statement = "The evil " + character_mapper(enemies[i]->display()) + " strikes you for " + to_string(player_damage) + "damage!";
				return att_statement;
			}
		}
			else {  // Orc, Merchant, goblin
				if (getPlayer() == "Samurai" && !thePlayer->isMHostile()){
					return att_statement;
				}
				if (getPlayer() == "Samurai" && !thePlayer->isOHostile()){
					return att_statement;
				}
				if (getPlayer() == "Samurai" && !thePlayer->isgHostile()){
					return att_statement;
				}
				if (!thePlayer->isMHostile()){
					return att_statement;
				}
				if (grid[en_row-1][en_col].display() == '@' || grid[en_row][en_col-1].display() == '@'
					|| grid[en_row][en_col+1].display() == '@' || grid[en_row+1][en_col].display() == '@'
					|| grid[en_row-1][en_col-1].display() == '@' || grid[en_row-1][en_col+1].display() == '@'
					|| grid[en_row+1][en_col-1].display() == '@' || grid[en_row+1][en_col+1].display() == '@'){
					enemies[i]->attack(thePlayer);
				int player_damage = thePlayer->damage();
				att_statement = "The evil " + character_mapper(enemies[i]->display()) + " strikes you for " + to_string(player_damage) + "damage!";
				return att_statement;
			}
		}
	}
}
return att_statement;
}

/*
deathNote() is the message printed out to the screen if the Player loses the game
*/
string Game::deathNote(){
	string death_hymn1 = "You have been bested by the Great Cavernous Chambers. Good luck next time!\n";
	string death_hymn2 = "You achieved a score of " + to_string(getGold()) + ".\n";
	string death_hymn3 = "Play again? (y/n)\n";
	return death_hymn1 + death_hymn2 + death_hymn3;
}









