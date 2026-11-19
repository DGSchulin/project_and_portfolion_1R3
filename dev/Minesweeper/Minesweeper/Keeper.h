#pragma once

class Keeper {
	int total;
	int streak;

public:
	Keeper();
	Keeper(int testing, int debug);
	int getTotal();
	int getStreak();
	void addWin();
	void reset(bool isComplete);
	void saveStats();
};