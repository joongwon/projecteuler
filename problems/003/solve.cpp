#include "../../utils/main.h"
#include <iostream>
#include <cinttypes>
#include <vector>

#define NUMBER 600851475143

class Factorize {
    std::int64_t n;
    std::int64_t factor = 2;
public:
    explicit Factorize(std::int64_t n) : n{n} {}

    std::int64_t operator()() {
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
};

void solve() {
    std::vector<std::int64_t> factors;
    Factorize gen_factors(NUMBER);
    auto inserter = std::back_inserter(factors);
    for (auto i = gen_factors(); i != 1; i = gen_factors()) {
        *inserter++ = i;
    }
    std::cout << factors.back() << "\n";
}
