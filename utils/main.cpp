#include <chrono>
#include <iostream>
#include "main.h"

int main() {
    using namespace std::chrono;
    std::cout << "begin solve\n";
    auto time_begin = steady_clock::now();

    solve();

    auto time_end = steady_clock::now();
    std::cout << "end solve\n";

    auto dur = time_end - time_begin;

    std::cout << "time: " << duration_cast<duration<double>>(dur).count() << "s\n";
}
