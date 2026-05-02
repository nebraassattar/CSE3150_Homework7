#include "FileReader.h"
#include "FileWriter.h"
#include "Deck.h"
#include <iostream>
#include <string>
 
int main(int argc, char* argv[]) {
    if (argc != 3) {
        std::cerr << "Usage: war_game <input.csv> <output.csv>\n";
        return 1;
    }
 
    std::string inputPath = argv[1];
    std::string outputPath = argv[2];
 
    // Read and validate deck
    Deck fullDeck;
    try {
        fullDeck = FileReader::readDeckFromCSV(inputPath);
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << "\n";
        return 1;
    }
 
    if (fullDeck.size() < 2) {
        std::cerr << "Error: Deck must have at least 2 cards.\n";
        return 1;
    }
 
    // Split deck between two players
    Deck playerA, playerB;
    bool toA = true;
    while (!fullDeck.empty()) {
        auto card = fullDeck.drawFromTop();
        if (toA) playerA.addToBottom(std::move(card));
        else      playerB.addToBottom(std::move(card));
        toA = !toA;
    }
 
    FileWriter writer(outputPath);
 
    std::cout << "Starting War\n";
 
    int round = 1;
    while (!playerA.empty() && !playerB.empty()) {
        std::cout << "Round " << round << "\n";
 
        auto cardA = playerA.drawFromTop();
        auto cardB = playerB.drawFromTop();
 
        std::cout << "Player A plays: " << cardA->display() << "\n";
        std::cout << "Player B plays: " << cardB->display() << "\n";
 
        int va = cardA->value();
        int vb = cardB->value();
 
        if (va > vb) {
            // Player A wins the round
            playerA.addToBottom(std::move(cardA));
            playerA.addToBottom(std::move(cardB));
            std::cout << "Player A wins round " << round << "\n";
        } else if (vb > va) {
            // Player B wins the round
            playerB.addToBottom(std::move(cardB));
            playerB.addToBottom(std::move(cardA));
            std::cout << "Player B wins round " << round << "\n";
        } else {
            // Tie: each keeps their card back
            playerA.addToBottom(std::move(cardA));
            playerB.addToBottom(std::move(cardB));
            std::cout << "Tie in round " << round << "\n";
        }
 
        writer.writeRound(round, playerA, playerB);
        ++round;
 
        // Safety valve against infinite loops
        if (round > 10000) break;
    }
 
    std::cout << "Game Over\n";
 
    if (playerA.empty() && playerB.empty()) {
        std::cout << "It's a tie!\n";
    } else if (playerA.empty()) {
        std::cout << "Player B wins!\n";
    } else if (playerB.empty()) {
        std::cout << "Player A wins!\n";
    } else {
        // Reached round limit
	// Compare sizes
        if (playerA.size() > playerB.size())
            std::cout << "Player A wins!\n";
        else if (playerB.size() > playerA.size())
            std::cout << "Player B wins!\n";
        else
            std::cout << "It's a tie!\n";
    }
 
    return 0;
}
