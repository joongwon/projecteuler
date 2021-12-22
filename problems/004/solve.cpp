#include "../../utils/main.h"
#include <iostream>
#include <functional>

int make_palindrome(int first_half) {
    int result = first_half;
    while (first_half) {
        result = result * 10 + first_half % 10;
        first_half /= 10;
    }
    return result;
}

bool factorizable_in_range(int n, int minimum, int maximum) {
    int begin = std::max(minimum, n / maximum);
    int end = std::min(maximum, n / minimum);
    for (int factor = begin; factor <= end; factor++) {
        if (n % factor == 0) {
            return true;
        }
    }
    return false;
}

#define FACTOR_MIN 100
#define FACTOR_MAX 999
#define SEED_MIN 100
#define SEED_MAX 999

void solve() {
    for (int half = SEED_MAX; half >= SEED_MIN; half--) {
        int palindrome = make_palindrome(half);
        if (factorizable_in_range(palindrome, FACTOR_MIN, FACTOR_MAX)) {
            std::cout << palindrome << std::endl;
            return;
        }
    }
    std::cout << "not solved" << std::endl;
}
