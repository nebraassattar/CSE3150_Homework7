#include "FaceCard.h"
#include <stdexcept>
 
FaceCard::FaceCard(const std::string& suit, int rank) : suit_(suit), rank_(rank) {
    if (rank == 11)      name_ = "Jack";
    else if (rank == 12) name_ = "Queen";
    else if (rank == 13) name_ = "King";
    else throw std::runtime_error("Invalid face card rank");
}
 
int FaceCard::value() const {
    return rank_;
}
 
std::string FaceCard::display() const {
    return name_ + " of " + suit_;
}
