#include "Game.h"
#include <iostream>

Game::Game(Board board, int count)
{
	gameboard = board;
	cursor = 0;
	mCount = count;
	double size = gameboard.getValues().size();
	sq = std::sqrt(size);
}

void Game::print()
{
	std::vector<int> values = gameboard.getValues();

	std::cout << "   ";
	for (int i = 0; i < sq; i++) {
		std::cout << i + 1;
	}
	std::cout << "\n   ";
	for (int i = 0; i < sq; i++) {
		std::cout << "_";
	}
	for (int i = 0; i < values.size(); i++) {
		if (i % sq == 0) {
			std::cout << "\n" << i / 4 + 1 << " |";
		}
		if (gameboard.getVis()[i] == 9) {
			std::cout << "!";
		}
		else if (gameboard.getVis()[i] == -1) {
			std::cout << "?";
		}
		else if (gameboard.getVis()[i] == -2) {
			std::cout << "F";
		}
		else {
			std::cout << gameboard.getVis()[i];
		}
	}
	std::cout << "\n\nCursor is at: \nX: " << (cursor % sq) + 1 << "\nY: " << (cursor / sq) + 1;
	std::cout << "\n\nMine count: " << mCount << "\n\n";
}

void Game::moveUp()
{
	if (cursor - sq < 0) {
		cursor = cursor + (sq * (sq - 1));
	}
	else {
		cursor = cursor - sq;
	}
}

void Game::moveDown()
{
	if (cursor + sq >= sq * sq) {
		cursor = cursor % sq;
	}
	else {
		cursor = cursor + sq;
	}
}

void Game::moveLeft()
{
	if (cursor % sq == 0) {
		cursor = cursor + (sq - 1);
	}
	else {
		cursor = cursor - 1;
	}
}

void Game::moveRight()
{
	if (cursor % sq == sq - 1) {
		cursor = cursor - (sq - 1);
	}
	else {
		cursor = cursor + 1;
	}
}

void Game::reveal(bool first)
{
	if (gameboard.getAt(cursor, false) == 9 && first == true) {
		bool loop = true;
		while (loop == true) {
			gameboard = Board(sq, mCount);
			if (gameboard.getAt(cursor, false) != 9) {
				loop = false;
			}
		}
	}
	gameboard.setAt(cursor, true, gameboard.getAt(cursor, false));
}

void Game::flag()
{
	gameboard.setAt(cursor, true, -2);
}

bool Game::isMineTriggered()
{
	bool explosion = false;
	for (int i = 0; i < gameboard.getVis().size(); i++) {
		if (gameboard.getAt(i, true) == 9) {
			explosion = true;
		}
	}
	return explosion;
}

bool Game::isComplete()
{
	bool smile = true;
	for (int i = 0; i < gameboard.getVis().size(); i++) {
		if (gameboard.getAt(i, true) < 0 && gameboard.getAt(i, false) != 9) { 
			smile = false;
		}
	}
	return smile;
}
