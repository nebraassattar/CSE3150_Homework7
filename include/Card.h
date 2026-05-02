#pragma once
#include <string>
#include <ostream>
 
class Card {
public:
    virtual ~Card() = default;
    virtual int value() const = 0;
    virtual std::string display() const = 0;
    friend std::ostream& operator<<(std::ostream& os, const Card& c);
};
