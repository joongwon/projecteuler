#include "../../utils/main.h"
#include <iostream>

constexpr int sum_linear(int n) {
    return n * (n + 1) / 2;
}

constexpr int sum_quadratic(int n) {
    return n * (n + 1) * (2 * n + 1) / 6;
}

constexpr int square(int n) {
    return n * n;
}

#define NUMBER 100

void solve() {
    std::cout << square(sum_linear(NUMBER)) - sum_quadratic(NUMBER) << std::endl;
}
