//copyright lily deller
//this is only for prototypes! which are declarations to tell the compiler about the function, they help organize code 
//consists of return type (int, bool, void) , function name, and parameter list 

#include "program2functions.h" // include header file 

// 1st LeapYear Function
// determines if a given year is a leap year
bool LeapYear(int year) {
    
    if (year % 400 == 0) return true;
    if (year % 100 == 0) return false;
    if (year % 4 == 0) return true;
    return false;
}

// 2nd LastDayOfMonth Function
// will return the last day of a given month (takes leap years into account for February)
int LastDayOfMonth(int month, int year) {
    // check for valid month range
    if (month < 1 || month > 12) {
        return 0;  // invalid month
    }

    // deal w february 
    if (month == 2) {
        if (year <= 0) return 0;  // invalid year for February
        return LeapYear(year) ? 29 : 28;  // feb has 29 days in a leap year, 28 otherwise
    }

    // our months with 31 days
    if (month == 1 || month == 3 || month == 5 || month == 7 || 
        month == 8 || month == 10 || month == 12) {
        return 31;
    }

    // other months have 30 days
    return 30;
}

// 3rd ValidDate function
// will check if the given day, month, and year constitute a valid date
bool ValidDate(int month, int day, int year) {
    // check if the year is positive
    if (year <= 0) {
        return false;
    }

    // get the last valid day for the given month and year
    int lastDay = LastDayOfMonth(month, year);

    // will check if day is valid
    if (day < 1 || day > lastDay) {
        return false;
    }

    return true;
}

// 4th NextDate Function
// advances the given date by one day (updates the passed arguments)
void NextDate(int& month, int& day, int& year) {
    // validate the current date first
    if (!ValidDate(month, day, year)) {
        return;  // do nothing if the date is invalid
    }

    // get the last day of the current month
    int lastDay = LastDayOfMonth(month, year);

    // move to the next day
    if (day < lastDay) {
        day++;  // just move to the next day within the month
    } else {
        // move to the next month
        day = 1;
        if (month == 12) {
            month = 1;  // move to January and increment the year
            year++;
        } else {
            month++;
        }
    }
}

// 5th PreviousDate Function
// moves the given date back by one day (updates the passed arguments)
void PreviousDate(int& month, int& day, int& year) {
    // validate the current date first
    if (!ValidDate(month, day, year)) {
        return;  // do nothing if the date is invalid
    }

    // move to the previous day
    if (day > 1) {
        day--;  // just move to the previous day within the month
    } else {
        // move to the previous month
        if (month == 1) {
            month = 12;  // move to December of the previous year
            year--;
        } else {
            month--;
        }
        day = LastDayOfMonth(month, year);  // set the day to the last day of the new month
    }
}
