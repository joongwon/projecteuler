#include "../../utils/main.h"
#include <iostream>
#include <functional>
#include <numeric>
#include <algorithm>

#define SERIES \
"73167176531330624919225119674426574742355349194934"\
"96983520312774506326239578318016984801869478851843"\
"85861560789112949495459501737958331952853208805511"\
"12540698747158523863050715693290963295227443043557"\
"66896648950445244523161731856403098711121722383113"\
"62229893423380308135336276614282806444486645238749"\
"30358907296290491560440772390713810515859307960866"\
"70172427121883998797908792274921901699720888093776"\
"65727333001053367881220235421809751254540594752243"\
"52584907711670556013604839586446706324415722155397"\
"53697817977846174064955149290862569321978468622482"\
"83972241375657056057490261407972968652414535100474"\
"82166370484403199890008895243450658541227588666881"\
"16427171479924442928230863465674813919123162824586"\
"17866458359124566529476545682848912883142607690042"\
"24219022671055626321111109370544217506941658960408"\
"07198403850962455444362981230987879927244284909188"\
"84580156166097919133875499200524063689912560717606"\
"05886116467109405077541002256983155200055935729725"\
"71636269561882670428252483600823257530420752963450"

#define N 13
#define SOLVE_OPTION 0

void solve() {
    static_assert(std::size(SERIES) >= N, "series length must be larger than N");
    std::string_view raw_series = SERIES;
    std::vector<int> series;
    series.reserve(raw_series.length());
    for (auto c: raw_series)
        series.push_back(c - '0');

#if SOLVE_OPTION == 0
    std::int64_t max = 0;
    for (int i = N; i <= series.size(); i++) {
        std::int64_t product = std::reduce(series.begin() + (i - N), series.begin() + i, 1, std::multiplies{});
        if (max < product)
            max = product;
    }
#else
    std::int64_t product = std::reduce(series.begin(), series.begin() + N, 1, std::multiplies{});
    std::int64_t max = product;
    int zeros_in_product = 0;
    for (int i = N; i < series.size(); i++) {
        if (series[i - N] == 0)
            zeros_in_product--;
        else
            product /= series[i - N];
        if (series[i] == 0)
            zeros_in_product++;
        else
            product *= series[i];

        if (!zeros_in_product && product > max)
            max = product;
    }
#endif
    std::cout << max << std::endl;
}
