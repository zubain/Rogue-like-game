/*
This is the header file for the Cell Class
*/
#ifndef CELL_H
#define CELL_H
#include "textdisplay.h"

// forward declaration because mutual reference
class GameObject;

class Cell {
   	int _x, _y;					// coordinates of the Cell
    	char _display, contents_display;		// original char of the Cell and char of the GameObject the Cell contains
    	GameObject *_contents;				// the GameObject the Cell contains
	static TextDisplay* _thedisplay;
	bool _isObject;
	void notifyDisplay();
    public:
	Cell();
        void setCellVal(int x, int y, char ch);
        int x() const;
        int y() const;
        char display() const;
	bool isObject();
	void addObject(GameObject* contents);
	void removeObject();
	void addDisplay(TextDisplay* newdisplay);
};

#endif
