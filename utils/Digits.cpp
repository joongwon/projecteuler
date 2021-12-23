#include "Digits.h"
#include <ostream>

Digits Digits::add(const Digits &other) const {
    Digits result;
    std::string &result_digits = result.digits;
    result_digits.resize(other.digits.length());
    bool carry = 0;
    for (int i = 0; i < digits.length(); i++) {
        auto sum = digits[i] - '0' + other.digits[i] - '0' + carry;
        carry = sum / 10;
        sum %= 10;
        result_digits[i] = sum + '0';
    }
    for (int i = digits.length(); i < other.digits.length(); i++) {
        auto sum = other.digits[i] - '0' + carry;
        carry = sum / 10;
        sum %= 10;
        result_digits[i] = sum + '0';
    }
    if (carry)
        result_digits.push_back('1');
    return result;
}

Digits operator+(const Digits &a, const Digits &b) {
    if (a.digits.length() < b.digits.length())
        return a.add(b);
    else
        return b.add(a);
}

std::ostream &operator<<(std::ostream &os, const Digits &n) {
    return os << std::string{n.digits.rbegin(), n.digits.rend()};
}
