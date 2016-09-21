#include <stdio.h>
#include <inttypes.h>

typedef enum {MON, TUE, WED, THU, FRI, SAT, SUN, DAYS_IN_WEEK} week_day_t;
typedef enum {JAN, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC, MONTHS_IN_YEAR} month_t;

uint_fast8_t isLeapYear(uint64_t year)
{
    if (year % 4 != 0) {
        return 0;
    }

    if (year % 100 == 0) {
        if (year % 400 == 0) {
            return 1;
        }

        return 0;
    }

    return 1;
}

uint64_t getDaysInMonth(uint64_t year, month_t monthOfYear)
{
    switch (monthOfYear) {
        case JAN:
        case MAR:
        case MAY:
        case JUL:
        case AUG:
        case OCT:
        case DEC:
            return 31;

        case FEB:
            if (isLeapYear(year)) {
                return 29;
            }
            return 28;

        default:
            return 30;
    }
}

int main(int argc, uint8_t *argv[])
{
    uint64_t year, dayOfMonth, daysInMonth, sundays;
    month_t monthOfYear;

    /**
     * 1900-01-01 is a Monday.
     */
    week_day_t weekDay = MON;

    dayOfMonth  = 1;
    sundays     = 0;

    for (year = 1900; year <= 2000; year++) {
        for (monthOfYear = JAN; monthOfYear < MONTHS_IN_YEAR; monthOfYear++) {
            daysInMonth = getDaysInMonth(year, monthOfYear);
            for (dayOfMonth = 1; dayOfMonth <= daysInMonth; dayOfMonth++) {
                weekDay = (weekDay + 1) % DAYS_IN_WEEK;

                if (year > 1900 && dayOfMonth == 1 && weekDay == SUN) {
                    sundays += 1;
                }

            }
        }
    }
    printf("Sundays: %" PRIu64 "\n", sundays);

    return 0;
}
