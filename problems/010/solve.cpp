#include "../../utils/main.h"
#include <iostream>
#include <vector>

std::vector<bool> create_primeness_table(int upper_limit) {
    std::vector<bool> primeness(upper_limit, true);
    primeness[0] = primeness[1] = false;
    for (int i = 4; i < upper_limit; i += 2) {
        primeness[i] = false;
    }
    int last = std::floor(std::sqrt(upper_limit));
    for (int i = 3; i <= last; i += 2) {
        if (!primeness[i])
            continue;
        for (int j = i * i; j < upper_limit; j += i * 2) {
            primeness[j] = false;
        }
    }
    return primeness;
}

#define UPPER_LIMIT 200'0000

void solve() {
    auto primeness = create_primeness_table(UPPER_LIMIT);
    std::int64_t sum = 0;
    for (int i = 0; i < primeness.size(); i++) {
        if (primeness[i])
            sum += i;
    }
    std::cout << sum << std::endl;
}
