#include "Board.h"
#include <iostream>
Board::Board()
{
}

Board::Board(int dim, int mCount)
{
	int boardSize = dim * dim;
	for (int i = 0; i < boardSize; i++) {
		values.push_back(0);
		visible.push_back(-1);
	}

	for (int i = 0; i < mCount; i++) {
		bool running = true;
		while (running) {
			int mLoc = std::rand() % boardSize;
			if (values[mLoc] != 9) {
				values[mLoc] = 9;
				running = false;
			}
		}

	}

	for (int i = 0; i < boardSize; i++) {
		int nearby = 0;
		bool checkLeft = true;
		bool checkRight = true;
		bool checkUp = true;
		bool checkDown = true;

		if (i % dim == 0) {
			checkLeft = false;
		}
		if (i % dim == dim - 1) {
			checkRight = false;
		}
		if (i < dim) {
			checkUp = false;
		}
		if (i + dim >= boardSize) {
			checkDown = false;
		}

		if (checkLeft == true) {
			if (checkUp && values[i - 1 - dim] == 9) {
				nearby++;
			}
			if (values[i - 1] == 9) {
				nearby++;
			}
			if (checkDown && values[i - 1 + dim] == 9) {
				nearby++;
			}
		}

		if (checkRight) {
			if (checkUp && values[i + 1 - dim] == 9) {
				nearby++;
			}
			if (values[i + 1] == 9) {
				nearby++;
			}
			if (checkDown && values[i + 1 + dim] == 9) {
				nearby++;
			}
		}

		if (checkUp && values[i - dim] == 9) {
			nearby++;
		}
		if (checkDown && values[i + dim] == 9) {
			nearby++;
		}
		if (values[i] != 9) {
			values[i] = nearby;
		}
		nearby = 0;
	}
}

Board::Board(std::vector<int> v)
{
	values = v;
	for (int i = 0; i < v.size(); i++) {
		visible.push_back(-1);
	}
}

int Board::getAt(int position, bool isVis)
{
	if (isVis) {
		return visible[position];
	}
	else {
		return values[position];
	}
}

void Board::setAt(int position, bool isVis, int value)
{
	if (isVis) {
		visible[position] = value;
	}
	else {
		values[position] = value;
	}
}

void Board::debug(int aeiou) {
	if (aeiou == 1) {
		for (int i = 0; i < values.size() - 1; i++) {
			visible[i] = values[i];
		}
	}
	if (aeiou == 2) {
		for (int i = 0; i < values.size(); i++) {
			if (i % 4 == 0) {
				std::cout << "\n";
			}
			std::cout << values[i];
		}
	}
	std::cout << "\n";
}

std::vector<int> Board::getValues()
{
	return values;
}

std::vector<int> Board::getVis()
{
	return visible;
}
