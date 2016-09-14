/*
Purpose: Implements the game of CC3K (Chamber Crawler 3000) where the player can choose between Knight,
	 Wizard and Samurai brave through the chambers and fight with various enemies while collecting
	 gold pile. The player wins the game if he successfully reaches the fifth floor stairs and loses
	 if he gets defeated by in the chamber. His winning points would be the gold piles he collected.
	 There are also potions in the chamber available for use, however, while some potions can help the
	 player, there are also a few that can wound the player.

Commnd Syntax: ./cc3k [ n ] | [ input-file ]  
	n is the seed for the random number generator
	input-file is the game map
	All parameters are optional

Example: ./cc3k 10 cc3k-game-board.txt generates a CC3K game using the game board provided from cc3k-game-board.txt
	and randomly generates using the seed 10

Program ends when the Player decide to quit manually or decides not to play again after either winning or losing the
game
*/
#include "game.h"
#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <fstream>
#include <string>
#include <sstream>
#include <cstring>
#include <map>
using namespace std;

/*
val_direction(in) returns true if in is a valid derection and false otherwise
*/
bool val_direction(string in){
	if (in == "nw" || in == "no" || in == "ne" || in == "we" 
		|| in == "ea" || in == "sw" || in == "so" || in == "se"){
		return true;
	}
	else return false;
}

int main(int argc, char*argv[]) {
	int seed = getpid();							// intialize seed	
	string game_board;							// initialize name of file for player specified game board
	string s, player_type, char_select;					
	string usage = "./cc3k [ seed ] | [ input-file ]";
	string quitmsg = "You have chosen to exit. At least you tried.";
	string inputerr = "Did not recognize input.";
	bool isDefault = true;							// initialize using default game board instead of player specified game baord to be true
	bool stop_death = false;						// not stopdeath
	bool stop_wander = false;						// not stopwonder
	int check;
	try {
		if (argc > 3){							// more than 3 command aruguments ?
			throw usage;						// throw usage message
		}
	}
	catch(string err){							// catch usage message
		cerr << "Usage: " << argv[0] << " " << err << endl;		// print usage message
	} // try

	for (int i = 1; i < argc; i += 1) {					// traverse throught command line arguments 
		s = argv[i];							// take in command line argument
		stringstream arg(s);						// connect stringstream and s
		if (arg >> check) {						// argument an integer ?
			seed = check;						// use the integer as the seed
		}
		else {								// not an integer ?
			game_board = s;						// name of a game board file
			isDefault = false;					// not using default game board
		} 
	}
	prng.seed(seed);							// assign seed to PRNG
	Begin_game: 								// start of the game
	
	cout << "Welcome to ChamberCrawler3000!" << endl;
	cout << "What would you like to play as today?"	<< endl;
	cout << "w) Wizard" << endl;
	cout << "k) Knight" << endl;
	cout << "s) Samurai" << endl;
	cin.exceptions(ios_base::failbit);					// set cin exceptions
	try {
		try {
			for(;;){
				cin >> char_select;				// selecting player
				if (char_select == "w") {
					cout << "You have chosen to play as a Wizard. Good luck." << endl;
					// initialize wizard object
					player_type = "w";
					break;
				}
				else if (char_select == "k") {
					cout << "You have chosen to play as a Knight. Good luck." << endl;
					// initialize knight object
					player_type = "k";
					break;
				}
				else if (char_select == "s") {
					cout << "You have chosen to play as a Samurai. Good luck." << endl;
					// initialize samurai object
					player_type = "s";
					break;
				}
				else {
					cout << inputerr << endl;
				} // if
			} // for
		}catch(ios_base::failure) {					// player decides to exit the game
			throw ios_base::failure("");
		} // try
		istream* infile = &cin;						// set cin as default infile
		infile->exceptions(ios_base::failbit);				// set exceptions for infile
		try {
			if (!isDefault) {					// not using default gameboard
				infile = new ifstream(game_board.c_str());	// open user specified gameboard
				infile->exceptions(ios_base::failbit);		// set exceptions for infile
			}
		}catch(ios_base::failure) {					// fail to open user specified gameboard
			cout << "Problem loading board from map file '" << game_board << "'." << endl;	// print error message
			isDefault = true;					// use default gameboard
		} // try
		Game* new_game;							// intialize new game
		if (isDefault) {						// using default gameboard ?
			new_game = new Game(player_type);			// use default gameboard constructor
		}
		else { 								// not using default gameboard
			new_game = new Game(*infile,  player_type);		// use user specified input file game constructor
		} // if

		Player* new_player = new_game->player();			// access pointer to the player 
		int pl_coordx = new_player->x();				// access x-coordinate of player
		int pl_coordy = new_player->y();				// access y-coordinate of player

		new_game->print();						// print game board to the screen
		try {
			try {
				for(;;){
					string in;
					cin >> in;				// read input into in
					stringstream ss(in);			// connect stringstream with in
					if (in == "stopdeath"){			// player specifies stopdeath
						cout << "Player death can no longer occur." << endl;	
						stop_death = true;		// stop player from dying
						new_game->print();		// print game board to the screen
					}
					else if (in == "stopwander"){		// player specified stopwander
						cout << "Enemy actions that would result in movement now do nothing instead." << endl;
						stop_wander = true;		// stop enemies movement
						new_game->print();		// print game board to the screen
					} 
					else if ((in == "no") || (in == "so") || (in == "ea") || (in == "we") 
						|| (in == "nw") || (in == "ne") || (in == "sw") || (in == "se")) { // player specified direction
						if (new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '>'){
							new_game->updateFloor();	// update floor
							if (new_game->getFloor() > 5){  // floor is larger than 5 ? player wins the game
								cout << "At long last, you have outmatched the Great Cavernous Chambers. Great things await you." << endl;
								cout << "You have achieved a score of " << new_game->getGold() << "." << endl;
								cout << "Play again? (y/n)" << endl;
								cin >> in; 					// ask player if they want to continue playing
								if (in != "y" || in != "n"){			// neither y nor n ?
									cout << "Did not recognize input." << endl;	// does not recognize input
								}
								else if (in == "n"){				// player does not want to continue the game  ?
									delete new_game;			// delete the game
									break;					// exit game
								}
								else if (in == "y"){				// player wants to continue game ?
									delete new_game;			// delete the game
									goto Begin_game;			// go to begin game
								} // if
							}
							else{							// floor not larger than 5
								if (isDefault) {				// using default gameboard
									new_game->initializeFloorDefault();	// intitialize floor using default gameboard function
								}			
								else {						// not using default gameboard
									new_game->initializeFloor(*infile);	// initialize floor using user specified gameboard
								} // if
								pl_coordx = new_player->x();			// retrieve new player x coordinate
								pl_coordy = new_player->y();			// retrieve new player y coordinate
								new_player->tick();				
								cout << "You descend down to floor " << new_game->getFloor() << "." << endl;
								if (!stop_wander){				// stopwander is off
									new_game->moveEnemies();		// enemies continue moving
								} // if
								new_game->print();				// print gameboard to screen
							} // if
						} 
						else if (new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '.' ||  
							new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '+' || 
							new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '#') { // direction specifed is not a barrier
							new_game->movePlayer(pl_coordx,pl_coordy,in);		// move player to the direction
							pl_coordx = new_player->x();				// update player x coordinate
							pl_coordy = new_player->y();				// update player y coordinate
							new_player->tick();
							new_game->updateTurns();				// update turns
							cout << "You move " << new_game->direction_translator(in) << endl;
							if (!stop_wander){					// stopwander off ?
								new_game->moveEnemies();			// enemies continue moving
							} // if
							string player_attacked = new_game->attackPlayer();	// enemies can attack player
							if (!player_attacked.empty()){				// player was attacked
								cout << player_attacked << endl;		// print player attack message
							} // if	
							new_game->print();					// print game board
							if (!stop_death){					// stopdeath is off
								if (new_player->health() <= 0){			// player is dead ?
									cout << new_game->deathNote();		// print deathnote
									string death_input;
									cin >> death_input;
									stringstream ss(death_input);
									if (in == "y"){				// player wants to begin new game
										delete new_game;		// delete this game
										goto Begin_game;		// go to begin game
									}
									else if (in == "n"){			// player does not want to begin new game
										delete new_game;		// delete this game
										throw quitmsg;			// throw quitmsg
									} //if
								} //if
							} //if
						}

						else if (new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '|'
							|| new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '-'
							|| new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == ' '){ // direction specified is a barrier
							cout << "You can't move in that direction." << endl;	// print message
						}
						else if (new_game->direction_mapper(pl_coordx,pl_coordy,in)->display() == '$'){ // direction specified is gold pile
							new_game->getTreasure(pl_coordx,pl_coordy,in);				// player can get treasure
							new_game->updateTurns();
							cout << "You pick up the Gold Pile worth " << new_game->getGold() << "GP." << endl;
							new_game->direction_mapper(pl_coordx,pl_coordy,in)->removeObject();	// remove treasure from Cell
							if (!stop_wander){						// stopwander off
								new_game->moveEnemies();				// enemies continue moving
							} // if
							string player_attacked = new_game->attackPlayer();		// enemies attack player
							if (!player_attacked.empty()){					// if player is atatcked
								cout << player_attacked << endl;			// print message
							} // if
							new_game->print();						// print gameboard
							if (!stop_death){						// stopdeath is off
								if (new_player->health() <= 0){				// player is dead
									cout << new_game->deathNote();			// print death note
									string death_input;
									cin >> death_input;
									stringstream ss(death_input);
									if (in == "y"){					// player wants to continue the game
										delete new_game;			// delete this game
										goto Begin_game;			// go to begin game
									}	
									else if (in == "n"){				// player does not want to continue the game
										delete new_game;			// delete this game
										throw quitmsg;				// throw quit msg
									} // if
								} // if
							} //if
						} // if
						else {
							cout << "You can't move in that direction." << endl;
						} //if
					}
					else if (in == "a"){   // player wishes to attack 
						string inp;								
						cin >> inp;
						stringstream ss(inp);
						if (!val_direction(inp)){						// direction specified is not valid ?
							cout << "Unexpected direction for attack." << endl;
						}
						else if (new_game->getPlayer() == "Samurai" || new_game->getPlayer() == "Knight"){	// player is samurai or knight
							if (!new_game->direction_mapper(pl_coordx,pl_coordy,inp)->isObject()		// direction indicated does not have object
								|| new_game->direction_mapper(pl_coordx,pl_coordy,inp)->display() == '!' // object is potion
								|| new_game->direction_mapper(pl_coordx,pl_coordy,inp)->display() == '$'){ // object is treasure
								cout << "There is nothing there to attack!" << endl; // can't attack
							}
							else {								// otherwise
								string attack_statement = new_game->attackEnemy(pl_coordx, pl_coordy, inp); // attack enemy
								cout << attack_statement << endl;
								new_game->updateTurns();
								new_player->tick();
								if (!stop_wander){						
									new_game->moveEnemies();
								}
								string player_attacked = new_game->attackPlayer();
								if (!player_attacked.empty()){
									cout << player_attacked << endl;
								}
								new_game->print();
								if (!stop_death){
									if (new_player->health() <= 0){
										cout << new_game->deathNote();
										string death_input;
										cin >> death_input;
										stringstream ss(death_input);
										if (in == "y"){
											delete new_game;
											goto Begin_game;
										}
										else if (in == "n"){
											delete new_game;
											throw quitmsg;
										}
									}
								}
							}

						}
						else if (new_game->getPlayer() == "Wizard") {
							string attack_statement = new_game->attackEnemy(pl_coordx, pl_coordy, inp);
							if (attack_statement == "There is nothing to attack!"){    // applies only to wizards
								cout << attack_statement << endl;
								continue;
							}
							else {
								cout << attack_statement << endl;
							}
							new_game->updateTurns();
							new_player->tick();
							if (!stop_wander){
								new_game->moveEnemies();
							}
							string player_attacked = new_game->attackPlayer();
							if (!player_attacked.empty()){
								cout << player_attacked << endl;
							}
							new_game->print();
							if (!stop_death){
								if (new_player->health() <= 0){
									cout << new_game->deathNote();
									string death_input;
									cin >> death_input;
									stringstream ss(death_input);
									if (in == "y"){
										delete new_game;
										goto Begin_game;
									}
									else if (in == "n"){
										delete new_game;
										throw quitmsg;
									}
								}
							}
						}
					}	
					else if (in == "u"){					// user wants to use item
						cin >> in;
						stringstream ss(in);
						char itemtype = new_game->retrieve_surroundings(pl_coordx,pl_coordy,in);
						if (!val_direction(in)){			// direction specified not valid
							cout << "Unexpected direction for use." << endl;
						}
						else if (itemtype != '!' && itemtype != '$') {   // if there is no enemy in the cell that the player
						// wishes to attack
							cout << "There is nothing there to use!" << endl;
						}
						else if (itemtype == '$'){		// item is treasure ?
							new_game->getTreasure(pl_coordx, pl_coordy, in);	// get treasure
							new_game->updateTurns();
							cout << "You pick up the Gold Pile worth " << new_game->getGold() << "GP." << endl;
							new_game->direction_mapper(pl_coordx,pl_coordy,in)->removeObject();
							if (!stop_wander){
								new_game->moveEnemies();
							}
							string player_attacked = new_game->attackPlayer();
							if (!player_attacked.empty()){
								cout << player_attacked << endl;
							}
							new_game->print();
							if (!stop_death){
								if (new_player->health() <= 0){
									cout << new_game->deathNote();
									string death_input;
									cin >> death_input;
									stringstream ss(death_input);
									if (in == "y"){
										delete new_game;
										goto Begin_game;
									}
									else if (in == "n"){
										delete new_game;
										throw quitmsg;
									}
								}
							}
						}
						else if (itemtype == '!'){		// item is potions ?
							string potion_type = new_game->getPotion(pl_coordx, pl_coordy, in); // get potion
							new_game->updateTurns();
							cout << potion_type << endl;
							new_game->direction_mapper(pl_coordx,pl_coordy,in)->removeObject();
							if (!stop_wander){
								new_game->moveEnemies();
							}
							string player_attacked = new_game->attackPlayer();
							if (!player_attacked.empty()){
								cout << player_attacked << endl;
							}
							new_game->print();
							if (!stop_death){
								if (new_player->health() <= 0){
									cout << new_game->deathNote();
									string death_input;
									cin >> death_input;
									stringstream ss(death_input);
									if (in == "y"){
										delete new_game;
										goto Begin_game;
									}
									else if (in == "n"){
										delete new_game;
										throw quitmsg;
									}
								}
							}
						}
					}
					else if (in == "r"){		// player wants to restart the game ?
						cout << "Are you sure you want to restart? (y/n)" << endl;
						cin >> in;
						if (in == "y"){		// player is sure to restart the game ?
							delete new_game;	// delete this game
							goto Begin_game;	// begin new game
						}
						else if (in == "n"){	// player does not want to restart
							new_game->print();	// continue the game
						}	
					}
					else if (in == "q"){		// player wants to quit
						cout << "Are you sure you want to quit? (y/n)" << endl;
						string inp;
						cin >> inp;
						stringstream ss(inp);
						if (inp == "y"){	// player is sure to quit
							delete new_game;	// delete this game
							throw quitmsg;
						}
						else if (inp == "n"){	// player is not sure to quit
							new_game->print();	// continue the game
						} // if
					} // if
					else if (!val_direction(in)){
						cout << "Did not recognize input." << endl;
					}
				}
			}catch(string err) {	// catch an error
				cout << err << endl;	// output error
			} // try
		}catch(ios_base::failure) {	// ios failure
			delete new_game;	// delete the game
			cout << quitmsg << endl;	// output message
		}
		if (infile != &cin) delete infile;	// if input file specified, delete infile
	}catch(ios_base::failure) {}	// end of game
}
