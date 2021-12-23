#include "../../utils/main.h"
#include <iostream>
#include <array>

std::array<int, 3> pythagorean_triplet(int a, int b) {
    int x = a * a - b * b;
    int y = 2 * a * b;
    int z = a * a + b * b;
    if (x > y) std::swap(x, y);
    return {x, y, z};
}

void solve() {
    for (int a = 2; a < std::numeric_limits<int>::max(); a++) {
        for (int b = 1; b < a; b++) {
            auto[x, y, z] = pythagorean_triplet(a, b);
            int sum = x + y + z;
            if (1000 % sum == 0) {
                int multiply = 1000 / sum;
                x *= multiply, y *= multiply, z *= multiply;
                std::cout << x * y * z << std::endl;
                return;
            }
        }
    }
    std::cout << "not solved" << std::endl;
}
