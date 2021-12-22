//
// Created by Joongwon on 2021-12-22.
//

#include <iostream>
#include <chrono>

#define UPPER_LIMIT 1000
#define PRIME_A 3
#define PRIME_B 5

constexpr int count_multiple(int base, int maximum) {
    return maximum / base;
}

constexpr int sum_multiple_n(int base, int n) {
    return n * (1 + n) / 2 * base;
}

constexpr int sum_multiple_below(int base, int upper_limit) {
    return sum_multiple_n(base, count_multiple(base, upper_limit - 1));
}

int main(void) {
    auto time_begin = std::chrono::steady_clock::now();
    constexpr int answer = sum_multiple_below(PRIME_A, UPPER_LIMIT)
            + sum_multiple_below(PRIME_B, UPPER_LIMIT)
            - sum_multiple_below(PRIME_A * PRIME_B, UPPER_LIMIT);
    auto time_end = std::chrono::steady_clock::now();
    auto duration = time_end - time_begin;

    std::cout << "answer: " << answer << "\n";
    std::cout << "time: " << duration.count() << "s\n";
}