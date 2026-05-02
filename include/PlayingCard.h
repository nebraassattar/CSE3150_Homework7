#pragma once
#include "Card.h"
 
class PlayingCard : public Card {
    std::string suit_;
    int rank_;
public:
    PlayingCard(const std::string& suit, int rank);
    int value() const override;
    std::string display() const override;
};
