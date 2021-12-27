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

Digits Digits::multiply(const Digits &other) const {
    Digits result;
    for (int i = 0; i < other.digits.length(); i++) {
        result = result + multiply(other.digits[i]).shift(i);
    }
    return result;
}

Digits Digits::multiply(char other) const {
    Digits result;
    result.digits.reserve(digits.length() + 1);
    result.digits.resize(digits.length());
    int carry = 0;
    for (int i = 0; i < digits.length(); i++) {
        carry += (digits[i] - '0') * (other - '0');
        result.digits[i] = carry % 10 + '0';
        carry /= 10;
    }
    if (carry)
        result.digits.push_back(carry + '0');
    return result;
}

Digits Digits::shift(int offset) const {
    Digits result;
    result.digits.assign(offset, '0');
    result.digits.append(digits);
    return result;
}

Digits operator*(const Digits &a, const Digits &b) {
    if (a.digits == "0" || b.digits == "0")
        return {};
    else if (a.digits.length() > b.digits.length())
        return a.multiply(b);
    else
        return b.multiply(a);
}
