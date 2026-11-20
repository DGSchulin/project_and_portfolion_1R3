#include "Game.h"
#include "Keeper.h"
#include <string>
#include <iostream>

int main()
{
	std::string input;
	int input2;
	int input3;
	bool running = true;
	bool runningCreation = true;
	Keeper keep = Keeper();

	while (running == true) {
		std::cout << "1: Generate game.\n2: Show controls.\n3: View stats.\n4: End program.\n\n";
		std::cin >> input;
		std::cout << "\n";
		if (input == "1") {
			std::cout << "\033[2J\033[HHow large should the board be? Ex: 4 = 4x4 board.\n\n";
			while (runningCreation) {
				std::cin >> input2;
				if (input2 > 59) {
					std::cout << "\nGiven size too large, please try again.\n\n";
				}
				else if (input2 <= 1) {
					std::cout << "\nGiven size too small, please try again.\n\n";
				}
				else {
					runningCreation = false;
				}
			}
			runningCreation = true;
			std::cout << "\nHow many mines should be present? Make sure to not add an amount of mines equal to or greater than the total board size.\n\n";
			while (runningCreation) {
				std::cin >> input3;
				if (input3 <= 0) {
					std::cout << "\nGiven amount too small, please try again.\n\n";
				}
				else if (input3 >= input2 * input2) {
					std::cout << "\nGiven amount too large for the board size, please try again.\n\n";
				}
				else {
					runningCreation = false;
				}
			}
			std::cout << "\033[2J\033[H";
			bool fairGame = true;
			if ((input2 * input2) - input3 <= 1 || input3 == (input2 * input2) - 1 || input3 <= (input2 * input2) * 0.1) {
				fairGame = false;
				std::cout << "Due to the given board parameters being considered too easy, this game of Minesweeper will not be counted for your statistics.\n";
			}
			if (fairGame == true) {
				keep.addGame();
				keep.saveStats();
			}
			std::cout << "\n";
			runningCreation = true;
			Board game = Board(input2, input3);
			Game sweeper = Game(game, input3);
			bool gRun = true;
			bool firstCheck = true;
			std::string input4;
			sweeper.print();
			while (gRun) { 
				std::cin >> input4;
				std::cout << "\033[2J\033[H";
				if (input4 == "w" || input4 == "W") {
					sweeper.moveUp();
				}
				if (input4 == "a" || input4 == "A") {
					sweeper.moveLeft();
				}
				if (input4 == "s" || input4 == "S") {
					sweeper.moveDown();
				}
				if (input4 == "d" || input4 == "D") {
					sweeper.moveRight();
				}
				if (input4 == "e" || input4 == "E") {
					int t = sweeper.reveal(firstCheck);
					
					if (fairGame == true) {
						for (int i = 0; i < t; i++) {
							keep.addTile();
						}
						keep.saveStats();
					}

					firstCheck = false;
				}
				if (input4 == "f" || input4 == "F") {
					sweeper.flag();
				}
				
				int e = sweeper.autoClear();
				if (fairGame == true) {
					for (int i = 0; i < e; i++) {
						keep.addTile();
					}
					keep.saveStats();
				}
				
				sweeper.print();
				if (input4 == "exit" || input4 == "EXIT") {
					gRun = false;
				}
				std::cout << "\n\n";
				if (sweeper.isMineTriggered() == true || input4 == "debuglose") {
					gRun = false;
					std::cout << "You revealed a mine! You lose!\n\n\n\n";
					if (fairGame == true) {
						keep.addLoss();
						keep.saveStats();
					}
				}
				else if (sweeper.isComplete() == true || input4 == "debugwin") {
					gRun = false;
					std::cout << "You cleared the board! You win!\n\n\n\n";
					if (fairGame == true) {
						keep.addWin();
						keep.saveStats();
					}
				}
			}
		}

		if (input == "2") {
			std::cout << "\033[2J\033[HUse WASD to move your cursor.\nPress E to reveal a square.\nPress F to flag or unflag a square.\nEnter exit to exit the game.\n\n\n";
		}

		if (input == "3") {
			std::cout << "\033[2J\033[HTotal wins: " << keep.getTotal() << "\nTotal losses: " << keep.getLosses() << "\nTotal games played: " << keep.getTotalGames() << "\nCurrent streak: " << keep.getStreak() << "\nTotal tiles revealed: " << keep.getTiles();
			std::cout << "\n\n\nType back to go back.\nType clear to clear all stats.\n\n";
			bool helpmenu = true;
			while (helpmenu == true) {
				std::cin >> input;
				if (input == "back" || input == "BACK") {
					helpmenu = false;
					std::cout << "\n\n";
				}
				if (input == "clear" || input == "CLEAR") {
					keep.reset(true);
					std::cout << "\nStats cleared!\n\n";
					keep.saveStats();
					helpmenu = false;
				}
			}
		}

		if (input == "4") {
			std::cout << "\033[2J\033[HThank you for playing!";
			running = false;
			keep.saveStats();
		}
	}
}
