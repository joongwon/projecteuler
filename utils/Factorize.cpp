//
// Created by Joongwon on 2021-12-23.
//

#include "Factorize.h"

std::int64_t Factorize::operator()() {
    while (n != 1) {
        if (n % factor == 0) {
            n /= factor;
            return factor;
        } else {
            factor++;
        }
    }
    return 1;
}
