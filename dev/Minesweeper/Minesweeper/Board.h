#pragma once
#include <vector>

class Board {
	std::vector<int> values;
	std::vector<int> visible;
public:
	Board();
	Board(int dim, int mCount);
	Board(std::vector<int> v);
	int getAt(int position, bool isVis);
	void setAt(int position, bool isVis, int value);
	void debug(int aeiou);
	std::vector<int> getValues();
	std::vector<int> getVis();
};