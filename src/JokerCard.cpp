#include "JokerCard.h"
 
JokerCard::JokerCard(const std::string& color)
    : color_(color) {}
 
int JokerCard::value() const {
    return 14;
}
 
std::string JokerCard::display() const {
    return color_ + " Joker";
}
