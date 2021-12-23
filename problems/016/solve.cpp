#include "../../utils/main.h"
#include "../../utils/Digits.h"
#include <iostream>
#include <sstream>

void solve() {
    Digits x("1");
    for (int i = 0; i < 1000; i++)
        x = x + x;
    std::ostringstream oss;
    oss << x;
    auto digits = oss.str();
    int sum = 0;
    for (auto d: digits)
        sum += d - '0';
    std::cout << sum << std::endl;
}
