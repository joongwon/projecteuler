#pragma once

#include <string>

class Digits {
    std::string digits;

    Digits add(const Digits &other) const;

public:
    Digits(std::string digits) : digits{digits.rbegin(), digits.rend()} {
    }

    Digits() : Digits("0") {}

    friend Digits operator+(const Digits &a, const Digits &b);

    friend std::ostream &operator<<(std::ostream &os, const Digits &n);
};
