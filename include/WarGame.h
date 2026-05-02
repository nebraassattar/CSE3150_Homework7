#pragma once
#include "Deck.h"
#include "FileWriter.h"
#include <string>
 
class WarGame {
    Deck playerA_;
    Deck playerB_;
public:
    explicit WarGame(Deck fullDeck);
 
    // Returns 0 on success.
    int run(FileWriter& writer);
};

