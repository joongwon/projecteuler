#pragma once

#include <vector>
#include "Factorize.h"

class SumDivisor {
    std::vector<int> memo;

    int calc(int n);

    int get_or_calc(int n);

public:
    explicit SumDivisor(int capacity) : memo(std::max(capacity, 2), 0) {
        memo[1] = 1;
    }

    int operator()(int n) {
        return get_or_calc(n);
    }
};

