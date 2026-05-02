#include "PlayingCard.h"
 
PlayingCard::PlayingCard(const std::string& suit, int rank)
    : suit_(suit), rank_(rank) {}
 
int PlayingCard::value() const {
    return rank_;
}
 
std::string PlayingCard::display() const {
    return std::to_string(rank_) + " of " + suit_;
}
