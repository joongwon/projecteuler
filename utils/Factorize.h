#pragma once

#include <cstdint>
#include <unordered_map>

class Factorize {
    std::int64_t n;
    std::int64_t factor = 2;
public:
    explicit Factorize(std::int64_t n) : n{n} {}

    std::int64_t operator()();

    std::int64_t get_n() const { return n; }

    std::int64_t get_factor_lower_limit() const { return factor; }
};

extern std::unordered_map<int, int> factorize(int n);
