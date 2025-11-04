#include "Player.h"

// Default constructor
Player::Player() : name(""), score(0) {}

// Constructor with name and score
Player::Player(string n, int s) : name(n), score(s) {}

// Get player name
string Player::getName() const {
	return name;
}

// Get player score
int Player::getScore() const {
	return score;
}

// Set player score
void Player::setScore(int s) {
	score = s;
}

// Set player name
void Player::setName(string n) {
	name = n;
}

// Compare players by score (higher first), then by name
bool Player::operator<(const Player& other) const {
	if (score != other.score)
		return score > other.score;
	return name < other.name;
}
