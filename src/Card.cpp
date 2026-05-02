#include "Card.h"
 
std::ostream& operator<<(std::ostream& os, const Card& c) {
    return os << c.display();
}
