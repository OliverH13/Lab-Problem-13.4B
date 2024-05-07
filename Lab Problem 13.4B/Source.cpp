
#include <iostream>
#include <string>

using namespace std;

int dayOfWeek(int month, int day, int year);
int getModifiedMonth(int month, int year);
int getModifiedYear(int month, int year);
void displayCalendar(int month, int year);

int main() {
    int month, year;

    cout << "Enter a month and year: ";
    cin >> month >> year;

    displayCalendar(month, year);

    return 0;
}

/**
dayOfWeek - Computes the weekday of a given date.
@param year the year
@param month the month (1 = January ... 12 = December)
@param day the day of the month
@return the weekday (0 = Saturday ... 6 = Friday)
*/
int dayOfWeek(int month, int day, int year) {
    int modifiedMonth = getModifiedMonth(month, year);
    int modifiedYear = getModifiedYear(month, year);

    int K = modifiedYear % 100;
    int J = modifiedYear / 100;
    int h = (day + (13 * (modifiedMonth + 1)) / 5 + K + (K / 4) + (J / 4) - (2 * J)) % 7;

    if (h < 0) {
        h += 7;
    }

    return h;
}

int getModifiedMonth(int month, int year) {
    if (month == 1 || month == 2) {
        return month + 12;
    }
    else {
        return month;
    }
}

int getModifiedYear(int month, int year) {
    if (month == 1 || month == 2) {
        return year - 1;
    }
    else {
        return year;
    }
}

void displayCalendar(int month, int year) {
    string calendar[] = { "                   1  2  3  4  5  6  7 ",
                          " 2  3  4  5  6  7  8  9 10 11 12 13 14 ",
                          " 9 10 11 12 13 14 15 16 17 18 19 20 21 ",
                          "16 17 18 19 20 21 22 23 24 25 26 27 28 ",
                          "23 24 25 26 27 28 29 30 31             ",
                          "30 31                                  ", };

    int firstDayOfWeek = dayOfWeek(month, 1, year); // Determine the first day of the month

    cout << "Su Mo Tu We Th Fr Sa" << endl;
    for (int i = 0; i < 4; i++) {
        cout << calendar[i].substr(firstDayOfWeek * 3, 21 - firstDayOfWeek * 3) << endl;
    }

    if (calendar[4].length() > 1) {
        cout << calendar[4].substr(0, 21) << endl;
    }

    if (calendar[5].length() > 1) {
        cout << calendar[5].substr(0, 14) << endl;
    }
}