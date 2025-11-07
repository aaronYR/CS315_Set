#include "Game.h"

// Constructor - seeds the random number generator for random math questions
Game::Game() {
	srand(time(NULL));
}

// Validates user input to make sure it is between 1 and 3
int Game::ErrorChecker(int user_input) {
	while (!cin || user_input < 1 || user_input > 3) {
		cin.clear();
		cin.ignore(INT_MAX, '\n');
		cout << "Error. Please enter 1, 2, or 3: ";
		cin >> user_input;
	}
	return user_input;
}

// Prompts the player to choose a difficulty and returns the corresponding number range
int Game::getDifficultyRange() {
	int difficulty;
	cout << "\nSelect difficulty:\n";
	cout << "1 - Easy (1-10)\n";
	cout << "2 - Medium (1-50)\n";
	cout << "3 - Hard (1-100)\n";

	cin >> difficulty;
	difficulty = ErrorChecker(difficulty);

	switch (difficulty) {
	case 1:
		return 10;
	case 2:
		return 50;
	case 3:
		return 100;
	default:
		return 10;
	}
}

// Calculates the player's score based on number correct, time, and difficulty
int Game::calculateScore(int correct, int seconds, int difficulty) {
	int base = 0;

	// Base score depends on selected difficulty
	if (difficulty == 1)
		base = 800;
	else if (difficulty == 2)
		base = 1000;
	else
		base = 1200;

	// Subtract points for time taken; ensures score doesnb
