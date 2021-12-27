#include "../../utils/main.h"
#include "../../utils/Factorize.h"
#include <iostream>
#include <unordered_map>
#include <numeric>
#include <functional>

#define DIVISORS 500

void solve() {
    for (std::int32_t n = 1; n <= std::numeric_limits<std::int32_t>::max(); n++) {
        std::int32_t a = n, b = n + 1;
        if (n % 2 == 0)
            a /= 2;
        else
            b /= 2;
        std::unordered_map<std::int32_t, int> factors;
        for (auto m: {a, b})
            for (auto &[factor, count]: factorize(m))
                factors[factor] += count;
        std::int32_t product = 1;
        for (auto &[factor, count]: factors) {
            product *= count + 1;
        }
        if (product > DIVISORS) {
            std::int64_t triangle = a;
            triangle *= b;
            std::cout << triangle << std::endl;
            return;
        }
    }
    std::cout << "not solved" << std::endl;
}
