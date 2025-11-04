#include "Leaderboard.h"

using namespace std;

// Adds a new player or updates their score if higher
void Leaderboard::addOrUpdatePlayer(const Player& p) {
    set<Player>::iterator existing = find_if(players.begin(), players.end(),
        [&](const Player& pl) { return pl.getName() == p.getName(); });

    // Update only if new score is higher
    if (existing != players.end()) {
        if (p.getScore() > existing->getScore()) {
            players.erase(existing);
            players.insert(p);
        }
    } else {
        players.insert(p);
    }
}


// Displays all players and scores
void Leaderboard::display() const {
	cout << "\n******* Leaderboard *******\n";
	if (players.empty()) {
		cout << "No scores yet. Play a game first!\n";
		return;
	}

	int rank = 1;
	for (const auto& player : players) {
		cout << rank++ << ". " << player.getName()
		     << " (" << player.getScore() << ")\n";
	}
	cout << "***************************\n";
}
