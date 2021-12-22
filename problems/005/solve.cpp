#include "../../utils/main.h"
#include <iostream>
#include <vector>
#include <numeric>

void solve() {
    std::vector<int> ns(20, 0);
    std::iota(ns.begin(), ns.end(), 1);
    auto result = std::reduce(ns.begin(), ns.end(), 1, std::lcm<int, int>);
    std::cout << result << std::endl;
}
