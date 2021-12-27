#include "../../utils/main.h"
#include <iostream>
#include "../../utils/Factorize.h"

class SumDivisor {
    std::vector<int> memo;

    int calc(int n) {
        Factorize factors_gen(n);
        int prime_factor = factors_gen();
        int factor = prime_factor;
        while (factors_gen() == prime_factor) {
            factor *= prime_factor;
        }
        return (factor * prime_factor - 1) / (prime_factor - 1) * get_or_calc(n / factor);
    }

    int get_or_calc(int n) {
        if (n <= 0)
            return 0;
        else if (n >= memo.size())
            return calc(n);
        else {
            if (memo[n] == 0)
                memo[n] = calc(n);
            return memo[n];
        }
    }

public:
    explicit SumDivisor(int capacity) : memo(std::max(capacity, 2), 0) {
        memo[1] = 1;
    }

    int operator()(int n) {
        return get_or_calc(n);
    }
};

#define UPPER_LIMIT 10000

void solve() {
    SumDivisor whole_sum(UPPER_LIMIT);
    int sum = 0;
    for (int i = 2; i < UPPER_LIMIT; i++) {
        int a = i;
        int b = whole_sum(a) - a;
        if (a != b && whole_sum(b) - b == a) {
            sum += a;
        }
    }
    std::cout << sum << std::endl;
}
