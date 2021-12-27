#pragma once

#include <string>

class Digits {
    std::string digits;

    Digits add(const Digits &other) const;

    Digits multiply(const Digits &other) const;

    Digits multiply(char other) const;

    Digits shift(int offset) const;

public:

    Digits(std::string digits) : digits{digits.rbegin(), digits.rend()} {}

    Digits() : Digits("0") {}

    Digits(int n) : Digits(std::to_string(n)) {}

    friend Digits operator+(const Digits &a, const Digits &b);

    friend Digits operator*(const Digits &a, const Digits &b);

    friend std::ostream &operator<<(std::ostream &os, const Digits &n);
};
