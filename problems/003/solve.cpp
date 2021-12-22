#include "../../utils/main.h"
#include "../../utils/Factorize.h"
#include <iostream>
#include <vector>

#define NUMBER 600851475143

void solve() {
    std::vector<std::int64_t> factors;
    Factorize gen_factors(NUMBER);
    auto inserter = std::back_inserter(factors);
    for (auto i = gen_factors(); i != 1; i = gen_factors()) {
        *inserter++ = i;
    }
    std::cout << factors.back() << "\n";
}
