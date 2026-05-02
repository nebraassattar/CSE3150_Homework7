#include "Deck.h"
 
void Deck::addToBottom(std::unique_ptr<Card> card) {
    cards_.push_back(std::move(card));
}
 
std::unique_ptr<Card> Deck::drawFromTop() {
    if (cards_.empty()) return nullptr;
    auto card = std::move(cards_.front());
    cards_.pop_front();
    return card;
}
 
bool Deck::empty() const {
    return cards_.empty();
}
 
size_t Deck::size() const {
    return cards_.size();
}
 
std::ostream& operator<<(std::ostream& os, const Deck& d) {
    for (size_t i = 0; i < d.cards_.size(); ++i) {
        if (i > 0) os << ", ";
        os << d.cards_[i]->display();
    }
    return os;
}

