#include "../../utils/main.h"
#include <iostream>

class CountMonthStart {
    int year = 1900;
    int month = 1;
    int day = 1;

public:
    CountMonthStart &advance() {
        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                day += 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) day += 29;
                else day += 28;
                break;
            default:
                day += 31;
        }
        day %= 7;
        if (++month == 13) {
            month = 1;
            ++year;
        }
        return *this;
    }

    int get_year() const {
        return year;
    }

    int get_month() const {
        return month;
    }

    int get_day() const {
        return day;
    }
};

void solve() {
    CountMonthStart cms;
    while (cms.get_year() < 1901)
        cms.advance();

    int cnt = 0;
    while (cms.get_year() <= 2000) {
        if (cms.get_day() == 0)
            cnt++;
        cms.advance();
    }
    std::cout << cnt << std::endl;
}
