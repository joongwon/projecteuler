#include "../../utils/main.h"
#include <iostream>
#include <vector>
#include <sstream>

class TriangleMaxPathSum {
    std::vector<int> triangle;
    std::vector<int> memo;
    int size;

    int index(int row, int col) {
        return row * (row + 1) / 2 + col;
    }

    int solve(int row, int col) {
        int i = index(row, col);
        if (memo[i] < 0) {
            if (row == 0)
                memo[i] = triangle[i];
            else if (col == 0)
                memo[i] = triangle[i] + solve(row - 1, 0);
            else if (col == row)
                memo[i] = triangle[i] + solve(row - 1, col - 1);
            else
                memo[i] = triangle[i] + std::max(solve(row - 1, col - 1), solve(row - 1, col));
        }
        return memo[i];
    }

public:
    explicit TriangleMaxPathSum(const char *triangle) {
        std::istringstream iss(triangle);
        for (;;) {
            int n;
            iss >> n;
            if (!iss)
                break;
            this->triangle.push_back(n);
        }
        size = (-1 + std::sqrt(1 + 8 * this->triangle.size())) / 2;
        memo.resize(this->triangle.size(), -1);
    }

    int operator()() {
        int max = 0;
        for (int i = 0; i < size; i++) {
            int s = solve(size - 1, i);
            if (max < s)
                max = s;
        }
        return max;
    }
};

#define TRIANGLE \
"75 "\
"95 64 "\
"17 47 82 "\
"18 35 87 10 "\
"20 04 82 47 65 "\
"19 01 23 75 03 34 "\
"88 02 77 73 07 63 67 "\
"99 65 04 28 06 16 70 92 "\
"41 41 26 56 83 40 80 70 33 "\
"41 48 72 33 47 32 37 16 94 29 "\
"53 71 44 65 25 43 91 52 97 51 14 "\
"70 11 33 28 77 73 17 78 39 68 17 57 "\
"91 71 52 38 17 14 91 43 58 50 27 29 48 "\
"63 66 04 68 89 53 67 30 73 16 69 87 40 31 "\
"04 62 98 27 23 09 70 98 73 93 38 53 60 04 23 "

void solve() {
    std::cout << TriangleMaxPathSum(TRIANGLE)() << std::endl;
}
