#pragma once
#include "Card.h"
 
class FaceCard : public Card {
    std::string suit_;
    int rank_;
    std::string name_;
public:
    FaceCard(const std::string& suit, int rank);
    int value() const override;
    std::string display() const override;
};
