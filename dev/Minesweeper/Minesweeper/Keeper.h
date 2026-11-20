#pragma once

class Keeper {
	int total;
	int losses;
	int gamesPlayed;
	int streak;
	int tilesRevealed;

public:
	Keeper();
	Keeper(int testing, int debug, int thisThing, int isnt, int used);
	int getTotal();
	int getLosses();
	int getTotalGames();
	int getStreak();
	int getTiles();
	void addWin();
	void addLoss();
	void addGame();
	void addTile();
	void reset(bool isComplete);
	void saveStats();
};