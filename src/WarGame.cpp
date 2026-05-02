#include "WarGame.h"
#include <iostream>
 
WarGame::WarGame(Deck fullDeck) {
    bool toA = true;
    while (!fullDeck.empty()) {
        auto card = fullDeck.drawFromTop();
        if (toA) playerA_.addToBottom(std::move(card));
        else      playerB_.addToBottom(std::move(card));
        toA = !toA;
    }
}
 
int WarGame::run(FileWriter& writer) {
    std::cout << "Starting War\n";
 
    int round = 1;
    while (!playerA_.empty() && !playerB_.empty()) {
        std::cout << "Round " << round << "\n";
 
        auto cardA = playerA_.drawFromTop();
        auto cardB = playerB_.drawFromTop();
 
        std::cout << "Player A plays: " << cardA->display() << "\n";
        std::cout << "Player B plays: " << cardB->display() << "\n";
 
        int va = cardA->value();
        int vb = cardB->value();
 
        if (va > vb) {
            playerA_.addToBottom(std::move(cardA));
            playerA_.addToBottom(std::move(cardB));
            std::cout << "Player A wins round " << round << "\n";
        } else if (vb > va) {
            playerB_.addToBottom(std::move(cardB));
            playerB_.addToBottom(std::move(cardA));
            std::cout << "Player B wins round " << round << "\n";
        } else {
            playerA_.addToBottom(std::move(cardA));
            playerB_.addToBottom(std::move(cardB));
            std::cout << "Tie in round " << round << "\n";
        }
 
        writer.writeRound(round, playerA_, playerB_);
        ++round;
 
        if (round > 10000) break;
    }
 
    std::cout << "Game Over\n";
 
    if (playerA_.empty() && playerB_.empty()) {
        std::cout << "It's a tie!\n";
    } else if (playerA_.empty()) {
        std::cout << "Player B wins!\n";
    } else if (playerB_.empty()) {
        std::cout << "Player A wins!\n";
    } else {
        if (playerA_.size() > playerB_.size())
            std::cout << "Player A wins!\n";
        else if (playerB_.size() > playerA_.size())
            std::cout << "Player B wins!\n";
        else
            std::cout << "It's a tie!\n";
    }
 
    return 0;
}
