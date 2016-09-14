/*
This file includes the constructor, destructor and member routines
for the TextDisplay Class
*/
#include "textdisplay.h"
using namespace std;

/*
TextDisplay() is the constructor for the TextDisplay class
*/
TextDisplay::TextDisplay() {
	_r = 25;					// initialize _r value to be 25
	_c = 79;					// initialize _c value to be 79
	theDisplay = new char*[_r];			// dynamically allocate memory for the theDisplay
	for (int i = 0; i < _r; i += 1) {		// traverse through theDisplay row by row
		theDisplay[i] = new char[_c];		// dynamically allocate memory for each row of theDisplay
	} // for
}

/*
~TextDisplay is the destructor for the TextDisplay class
*/
TextDisplay::~TextDisplay() {
	for (int i = 0; i < _r; i += 1) {		// traverse through each row of theDisplay
		delete [] theDisplay[i];		// free all dynamically allocated memory of each row
	} // for
	delete [] theDisplay;				// free the memory allocated for theDisplay
}

/*
notify(r, c, ch) changes the char stored in rth row and cth column of
	theDisplay into ch
*/
void TextDisplay::notify(int r, int c, char ch) {
	theDisplay[r][c] = ch;				// assign ch to the rth row and cth column of theDisplay
}

/*
print() prints the display onto the screen
*/
void TextDisplay::print() {
	for (int i = 0; i < _r; i += 1) {		// traverse through each row of theDisplay
		for (int j = 0; j < _c; j += 1) {	// traverse through each column of each row of theDisplay
			cout << theDisplay[i][j];	// print the char of that row and column of the theDisplay onto the screen
		} // for
		cout << endl;				// print newline character
	} // for
} 
