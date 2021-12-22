#include <iostream>
#include <chrono>
#include <vector>
#include <numeric>

class EvenFibonacci {
    int f1 = 1, f2 = 1, f3 = 2;
public:
    int operator()() {
        int current = f3;
        f1 = f2 + f3;
        f2 = f3 + f1;
        f3 = f1 + f2;
        return current;
    }
};

#define MAXIMUM 4'000'000

int solve() {
    EvenFibonacci gen_fib;
    std::vector<int> fibs;
    auto inserter = std::back_inserter(fibs);
    for (int i = gen_fib(); i <= MAXIMUM; i = gen_fib())
        *inserter = i;
    return std::accumulate(fibs.begin(), fibs.end(), 0);
}

int main() {
    auto time_begin = std::chrono::steady_clock::now();

    auto answer = solve();

    auto time_end = std::chrono::steady_clock::now();
    auto duration = time_end - time_begin;

    std::cout << "answer: " << answer << "\n";
    std::cout << "time: " << duration.count() << "s\n";
}