#include "../../utils/main.h"
#include <iostream>
#include <cmath>

bool is_prime(int n) {
    if (n % 2 == 0 || n <= 2)
        return n == 2;
    int end = std::floor(std::sqrt(n));
    for (int divisor = 3; divisor <= end; divisor++) {
        if (n % divisor == 0)
            return false;
    }
    return true;
}

int find_prime_by_index(int i) {
    int count = 1;
    int last = std::numeric_limits<int>::max() - 2;
    for (int candidate = 3; candidate <= last; candidate++) {
        if (is_prime(candidate)) {
            if (++count >= i) {
                return candidate;
            }
        }
    }
    return -1;
}

#define PRIME_INDEX 10001

void solve() {
    int prime = find_prime_by_index(PRIME_INDEX);
    if (prime < 0)
        std::cout << "not found" << std::endl;
    else
        std::cout << prime << std::endl;
}
