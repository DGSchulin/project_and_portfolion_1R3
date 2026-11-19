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
	streak = std::stoi(envoy);
	read.close();
}

Keeper::Keeper(int to, int st) {
	total = to;
	streak = st;
}

int Keeper::getTotal()
{
	return total;
}

int Keeper::getStreak()
{
	return streak;
}

void Keeper::addWin()
{
	total++;
	streak++;
}

void Keeper::reset(bool isComplete)
{
	streak = 0;
	if (isComplete == true) {
		total = 0;
	}
}

void Keeper::saveStats()
{
	std::ofstream write("temp.txt");
	write << total << "\n";
	write << streak << "\n";
	write.close();
	std::string name = "Records.txt";
	std::string name2 = "temp.txt";
	std::remove(name.c_str());
	std::rename(name2.c_str(), name.c_str());
}
