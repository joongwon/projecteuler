#pragma once

#include <cstdint>

class Factorize {
    std::int64_t n;
    std::int64_t factor = 2;
public:
    explicit Factorize(std::int64_t n) : n{n} {}

    std::int64_t operator()();

    std::int64_t get_n() const { return n; }

    std::int64_t get_factor_lower_limit() const { return factor; }
};
