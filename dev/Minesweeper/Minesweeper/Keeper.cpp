#include "Keeper.h"
#include <fstream>
#include <string>

Keeper::Keeper()
{
	std::string envoy;
	std::ifstream read("Records.txt");
	std::getline(read, envoy);
	total = std::stoi(envoy);
	std::getline(read, envoy);
	losses = std::stoi(envoy);
	std::getline(read, envoy);
	gamesPlayed = std::stoi(envoy);
	std::getline(read, envoy);
	streak = std::stoi(envoy);
	std::getline(read, envoy);
	tilesRevealed = std::stoi(envoy);
	read.close();
}

Keeper::Keeper(int to, int st, int lo, int ga, int ti) {
	total = to;
	streak = st;
	losses = lo;
	gamesPlayed = ga;
	tilesRevealed = ti;
}

int Keeper::getTotal()
{
	return total;
}

int Keeper::getLosses() 
{
	return losses;
}

int Keeper::getTotalGames() 
{
	return gamesPlayed;
}

int Keeper::getStreak()
{
	return streak;
}

int Keeper::getTiles() 
{
	return tilesRevealed;
}

void Keeper::addWin()
{
	total++;
	streak++;
}

void Keeper::addLoss() 
{
	streak = 0;
	losses++;
}

void Keeper::addGame() 
{
	gamesPlayed++;
}

void Keeper::addTile() 
{
	tilesRevealed++;
}

void Keeper::reset(bool isComplete)
{
	streak = 0;
	if (isComplete == true) {
		total = 0;
		losses = 0;
		gamesPlayed = 0;
		tilesRevealed = 0;
	}
}

void Keeper::saveStats()
{
	std::ofstream write("temp.txt");
	write << total << "\n";
	write << losses << "\n";
	write << gamesPlayed << "\n";
	write << streak << "\n";
	write << tilesRevealed << "\n";
	write.close();
	std::string name = "Records.txt";
	std::string name2 = "temp.txt";
	std::remove(name.c_str());
	std::rename(name2.c_str(), name.c_str());
}
