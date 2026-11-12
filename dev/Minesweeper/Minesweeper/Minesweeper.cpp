#include "Game.h"
#include <string>
#include <iostream>

int main()
{
	std::string input;
	int input2;
	int input3;
	bool running = true;
	bool runningCreation = true;

	while (running == true) {
		std::cout << "1: Generate game\n2: Show Controls\n3: View stats\n4: End program.\n\n";
		std::cin >> input;
		std::cout << "\n";
		if (input == "1") {
			std::cout << "\nHow large should the board be? Ex: 4 = 4x4 board.\n";
			while (runningCreation) {
				std::cin >> input2;
				if (input2 > 99) {
					std::cout << "\nGiven size too large, please try again.\n";
				}
				else if (input2 <= 1) {
					std::cout << "\nGiven size too small, please try again.\n";
				}
				else {
					runningCreation = false;
				}
			}
			runningCreation = true;
			std::cout << "\nHow many mines should be present? Make sure to not add an amount of mines equal to or greater than the total board size.\n";
			while (runningCreation) {
				std::cin >> input3;
				if (input3 <= 0) {
					std::cout << "\nGiven amount too small, please try again.\n";
				}
				else if (input3 >= input2 * input2) {
					std::cout << "\nGiven amount too large for the board size, please try again.\n";
				}
				else {
					runningCreation = false;
				}
			}
			runningCreation = true;
			Board game = Board(input2, input3);
			Game sweeper = Game(game, input3);
			bool gRun = true;
			bool firstCheck = true;
			std::string input4;
			sweeper.print();
			while (gRun) { 
				std::cin >> input4;

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
					sweeper.reveal(firstCheck);
					firstCheck = false;
				}
				if (input4 == "f" || input4 == "F") {
					sweeper.flag();
				}
				sweeper.print();
				if (input4 == "exit" || input4 == "EXIT") {
					gRun = false;
				}
				std::cout << "\n\n";
				if (sweeper.isMineTriggered() == true || input4 == "debuglose") {
					gRun = false;
					std::cout << "You revealed a mine! You lose!\n\n";
				}
				else if (sweeper.isComplete() == true || input4 == "debugwin") {
					gRun = false;
					std::cout << "You cleared the board! You win!\n\n";
				}
			}
		}

		if (input == "2") {
			std::cout << "Use WASD to move your cursor\nPress E to reveal a square\nPress F to flag a square\nEnter exit to exit the game\n\n";
		}

		if (input == "4") {
			running = false;
			
		}
	}
}
