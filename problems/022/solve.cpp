#include "../../utils/main.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

const char *NAMES[] = {
#include "p022_names.txt"
};

void solve() {
    std::vector<std::string> names(std::begin(NAMES), std::end(NAMES));
    std::sort(names.begin(), names.end());
    int total = 0;
    for (int i = 0; i < names.size(); i++) {
        int sum = 0;
        for (char c: names[i])
            sum += c - 'A' + 1;
        int score = sum * (i + 1);
        total += score;
    }
    std::cout << total << std::endl;
}
