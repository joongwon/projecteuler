#include <chrono>
#include <iostream>
#include "main.h"

int main() {
    std::cout << "begin solve\n";
    auto time_begin = std::chrono::steady_clock::now();

    solve();

    auto time_end = std::chrono::steady_clock::now();
    std::cout << "end solve\n";

    auto duration = time_end - time_begin;

    std::cout << "time: " << duration.count() << "s\n";
}
