#pragma once
#include "Card.h"
#include <deque>
#include <memory>
#include <ostream>
 
class Deck {
    std::deque<std::unique_ptr<Card>> cards_;
public:
    void addToBottom(std::unique_ptr<Card> card);
    std::unique_ptr<Card> drawFromTop();
    bool empty() const;
    size_t size() const;
    friend std::ostream& operator<<(std::ostream& os, const Deck& d);
};
