#include "../../utils/main.h"
#include <iostream>
#include <array>

std::string to_english(int n) {
    std::string result;
    int thousands = n / 1000;
    n %= 1000;
    if (thousands) {
        result += to_english(thousands) + " thousand";
        if (n)
            result += " and ";
    }
    int hundreds = n / 100;
    n %= 100;
    if (hundreds) {
        if (result.empty()) {
            result += to_english(hundreds) + " hundred";
            if (n)
                result += " and ";
        } else {
            result += to_english(hundreds) + " hundred";
        }
    }
    int tens = n / 10;
    n %= 10;
    if (tens) {
        if (tens == 1) {
            constexpr std::array TEENS{
                    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen",
                    "nineteen"
            };
            result += TEENS[n];
        } else {
            constexpr std::array TIES{
                    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
            };
            result += TIES[tens];
            if (n) {
                result += "-" + to_english(n);
            }
        }
    } else {
        constexpr std::array SIMPLES{
                "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        result += SIMPLES[n];
    }
    return result;
}

void solve() {
    int count = 0;
    for (int i = 1; i <= 1000; i++) {
        for (char c: to_english(i)) {
            if (c >= 'a' && c <= 'z')
                count++;
        }
    }
    std::cout << count << std::endl;

}
