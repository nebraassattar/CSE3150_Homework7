#pragma once
#include "Card.h"
 
class JokerCard : public Card {
    std::string color_;
public:
    explicit JokerCard(const std::string& color);
    int value() const override;
    std::string display() const override;
};
