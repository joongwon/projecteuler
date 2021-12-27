#include "../../utils/main.h"
#include <iostream>
#include <sstream>
#include "../../utils/Digits.h"

void solve() {
    Digits n = 1;
    for (int i = 2; i <= 100; i++) {
        n = n * i;
    }
    std::ostringstream oss;
    oss << n;
    auto s = oss.str();
    int sum = 0;
    for (char c: s) {
        sum += c - '0';
    }
    std::cout << sum << std::endl;
}
