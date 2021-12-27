//
// Created by Joongwon on 2021-12-23.
//

#include "Factorize.h"

std::int64_t Factorize::operator()() {
    while (n != 1) {
        if (n % factor == 0) {
            n /= factor;
            return factor;
        } else {
            factor++;
        }
    }
    return 1;
}

std::unordered_map<int, int> factorize(int n) {
    std::unordered_map<int, int> count_factors;
    Factorize factors_gen(n);
    for (int factor = factors_gen(); factor != 1; factor = factors_gen()) {
        count_factors[factor]++;
    }
    return count_factors;
}
