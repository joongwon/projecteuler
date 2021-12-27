#include "../../utils/main.h"
#include <iostream>
#include "../../utils/SumDivisor.h"

#define UPPER_LIMIT 10000

void solve() {
    SumDivisor whole_sum(UPPER_LIMIT);
    int sum = 0;
    for (int i = 2; i < UPPER_LIMIT; i++) {
        int a = i;
        int b = whole_sum(a) - a;
        if (a != b && whole_sum(b) - b == a) {
            sum += a;
        }
    }
    std::cout << sum << std::endl;
}
