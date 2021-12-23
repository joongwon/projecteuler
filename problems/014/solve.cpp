#include "../../utils/main.h"
#include <iostream>
#include <unordered_map>

std::int64_t next_collatz(std::int64_t n) {
    return n % 2 == 0 ? n / 2 : 3 * n + 1;
}

class CollatzLength {
    std::vector<int> memo;
public:
    explicit CollatzLength(int memo_max) : memo(std::max(2, memo_max)) {
        memo[0] = 0;
        memo[1] = 1;
    }

    int operator()(std::int64_t n) {
        if (n < memo.size()) {
            if (!memo[n])
                memo[n] = 1 + operator()(next_collatz(n));
            return memo[n];
        } else {
            return 1 + operator()(next_collatz(n));
        }
    }
};

#define UPPER_LIMIT 100'0000
#define VERBOSE_UNIT (1 << 16)

void solve() {
    CollatzLength collatzLength(UPPER_LIMIT);
    int max = 0;
    int max_i = 0;
    for (int i = 1; i < UPPER_LIMIT; i++) {
        int len = collatzLength(i);
        if (len > max) {
            max = len;
            max_i = i;
        }
    }
    std::cout << max_i << std::endl;
}
