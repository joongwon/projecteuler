#include "SumDivisor.h"

int SumDivisor::calc(int n) {
    Factorize factors_gen(n);
    int prime_factor = factors_gen();
    int factor = prime_factor;
    while (factors_gen() == prime_factor) {
        factor *= prime_factor;
    }
    return (factor * prime_factor - 1) / (prime_factor - 1) * get_or_calc(n / factor);
}

int SumDivisor::get_or_calc(int n) {
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
