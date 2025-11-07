#include "Leaderboard.h"

// Adds a player's attempt and updates their best score if higher
void Leaderboard::addAttempt(const Player& p) {
    // Add all attempts to the multiset
    allAttempts.insert(p);

    // Maintains topScores (unique players) 
    auto existing = find_if(topScores.begin(), topScores.end(),
                            [&](const Player& pl) { return pl.getName() == p.getName(); });

    if (existing != topScores.end()) {
        if (p.getScore() > existing->getScore()) {
            topScores.erase(existing);
            topScores.insert(p);
        }
    } else {
        topScores.insert(p);
    }
}

// Displays the current leaderboard with ranked player scores
void Leaderboard::display() const {
    cout << "\n******* Leaderboard *******\n";
    if (topScores.empty()) {
        cout << "No scores yet. Play a game first!\n";
        return;
    }

    int rank = 1;
    for (const auto& player : topScores) {
        cout << rank++ << ". " << player.getName()
             << " (" << player.getScore() << ")\n";
    }
    cout << "***************************\n";
}

// Saves all recorded player attempts to a text file
void Leaderboard::saveAllAttemptsToFile(const string& filename) const {
    ofstream out(filename);
    if (!out.is_open()) {
        cerr << "Error: Could not open file " << filename << endl;
        return;
    }

    out << "All Player Attempts:\n";
    for (const auto& p : allAttempts) {
        out << p.getName() << " " << p.getScore() << "\n";
    }

    out.close();
}
