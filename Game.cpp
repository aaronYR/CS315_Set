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

	// Subtract points for time taken; ensures score does not go below zero
	int score = (correct * base) - (seconds * 50);
	return max(0, score);
}

// Ensures the name only contains alphabetic characters
string getValidName() {
	string name;
	bool valid = false;

	while (!valid) {
		cout << "Please enter your name: ";
		cin >> name;

		valid = true;

		// regular for loop version
		for (int i = 0; i < name.length(); i++) {
			if (!isalpha(name[i])) {
				valid = false;
				break;
			}
		}

		if (!valid) {
			cout << "Invalid name. Please use letters only (no numbers or symbols).\n";
		}
	}

	return name;
}


// Ensures a numeric-only input for math answers
int getValidNumberInput() {
	int num;
	while (true) {
		cin >> num;
		if (!cin.fail()) {
			return num;
		} else {
			cin.clear();
			cin.ignore(INT_MAX, '\n');
			cout << "Invalid input. Please enter a number: ";
		}
	}
}

// Runs one full round of the math quiz for a single player
Player Game::playRound() {
	string name = getValidName();

	int rangeMax = getDifficultyRange();
	int correct = 0;

	// Determine difficulty level based on chosen range
	int difficulty;

	if (rangeMax == 10) {
		difficulty = 1;
	}
	else if (rangeMax == 50) {
		difficulty = 2;
	}
	else {
		difficulty = 3;
	}

	cout << "\nGet ready for 5 math questions!\n";
	cout << "You get more points for being fast and accurate.\n\n";

	// Wait for the player to press Enter before starting
	cout << "Press Enter to start...\n";
	cin.ignore();
	cin.get();

	// Start timing after player presses Enter
	auto start = chrono::high_resolution_clock::now();

	// Ask five math questions
	for (int i = 1; i <= 5; i++) {
		int a = rand() % rangeMax + 1;
		int b = rand() % rangeMax + 1;
		char ops[] = { '+', '-', '*' };
		char op = ops[rand() % 3];
		int answer;

		switch (op) {
		case '+':
			answer = a + b;
			break;
		case '-':
			answer = a - b;
			break;
		case '*':
			answer = a * b;
			break;
		}

		cout << "Q" << i << ": " << a << " " << op << " " << b << " = ";

		int userAnswer = getValidNumberInput();

		if (userAnswer == answer) {
			cout << "b Correct!\n";
			correct++;
		} else {
			cout << "b Wrong! The correct answer was " << answer << ".\n";
		}
	}

	// Stop timer after all 5 questions
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::seconds>(end - start).count();

	// Calculate final score
	int score = calculateScore(correct, duration, difficulty);

	cout << "\nYou got " << correct << "/5 correct in " << duration << " seconds.\n";
	cout << "Your final score is: " << score << "\n";

	if (score >= 4500)
		cout << "p% Amazing speed and accuracy!\n";
	else if (score >= 2500)
		cout << "p* Great work!\n";
	else if (score > 0)
		cout << "Keep practicing!\n";
	else
		cout << "Better luck next time!\n";

	return Player(name, score);
}

// Displays the main menu loop allowing player to play, view leaderboard, or exit
void Game::menu() {
	int choice;
	bool running = true;

	while (running) {
		cout << "\nWhat would you like to do?\n";
		cout << "1 - Play the game\n";
		cout << "2 - Show the leaderboard\n";
		cout << "3 - Exit\n";
		cin >> choice;

		// Validate input
		choice = ErrorChecker(choice);

		switch (choice) {
		case 1: {
			Player p = playRound();
			leaderboard.addAttempt(p);
			break;
		}
		case 2: {
			leaderboard.display();
			break;
		}
		case 3: {
			cout << "Saving all attempts to 'all_scores.txt'...\n";
			leaderboard.saveAllAttemptsToFile("all_scores.txt");
			cout << "Thanks for playing! Goodbye!\n";
			running = false;
			break;
		}
		}
	}
}

