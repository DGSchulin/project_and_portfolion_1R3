#pragma once
#include "Board.h"

class Game {
	Board gameboard;
	int cursor;
	int mCount;
	int sq;
public:
	Game(Board board, int count);
	void print();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	void reveal();
	void flag();
	bool isMineTriggered();
	bool isComplete();
};