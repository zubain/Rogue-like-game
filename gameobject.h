/*
This is the header file for the GameObject Class
*/
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H
// forward declaration because mutual reference
class Cell;

// add public/private/protected members as necessary
class GameObject {
    	Cell * _location;
	bool _isCharacter, _isItem;
	int _x, _y;
	char _display;	
        void x(int i);  // setters
	void y(int i);
    public:
        GameObject(char ch, bool character, bool item);
	virtual ~GameObject();
        int x() const;  // getters
        int y() const;
	char display() const;
	bool isCharacter();
	bool isItem();
	void setLocation(Cell* location);
};

#endif
