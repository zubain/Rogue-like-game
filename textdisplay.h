/*
This is the header file for the TextDisplay class
*/

#ifndef TEXTDISPLAY_H
#define TEXTDISPLAY_H
#include <iostream>

class TextDisplay {
		char **theDisplay;
		int _r, _c;
	public:
		TextDisplay();
		~TextDisplay();
		void notify(int r, int c, char ch);
		void print();
};

#endif
