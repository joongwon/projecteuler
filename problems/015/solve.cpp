#include "../../utils/main.h"
#include <iostream>
#include <vector>

class LatticePath {
    std::vector<std::int64_t> memo;
    int size;

    std::int64_t solve(int x, int y) {
        int i = y * size + x;
        if (!memo[i]) {
            if (x == 0 || y == 0)
                memo[i] = 1;
            else
                memo[i] = solve(x - 1, y) + solve(x, y - 1);
        }
        return memo[i];
    }

public:
    explicit LatticePath(int size) : memo(size * size), size{size} {}

    std::int64_t operator()() {
        return solve(size - 1, size - 1);
    }
};

#define SIZE 20

void solve() {
    std::cout << LatticePath(SIZE + 1)() << std::endl;
}
