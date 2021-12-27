#include "../../utils/main.h"
#include "../../utils/SumDivisor.h"
#include <iostream>

void solve() {
    constexpr int ABUNDANT_SUM_LIMIT = 28123;
    SumDivisor whole_sum(ABUNDANT_SUM_LIMIT);
    std::vector<int> abundant_nums;
    std::vector<int> is_abundant_sum(ABUNDANT_SUM_LIMIT, false);
    for (int n = 12; n < ABUNDANT_SUM_LIMIT; n++) {
        if (whole_sum(n) - n > n) {
            abundant_nums.push_back(n);
            for (auto m: abundant_nums) {
                if (n + m >= ABUNDANT_SUM_LIMIT)
                    break;
                is_abundant_sum[n + m] = true;
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < ABUNDANT_SUM_LIMIT; i++)
        if (!is_abundant_sum[i])
            sum += i;
    std::cout << sum << std::endl;
}
