//copyright lily deller 
#ifndef PROGRAM2FUNCTIONS_H
#define PROGRAM2FUNCTIONS_H

//have to submit ZIP file - can't attach .h//.cc 
//all prototypes have to be included in program2function.h
// to do - make testprogram original - make sure it compiles outside of his practice inputs 

// function 1: LeapYear
// determines if a given year is a leap year.
// takes an integer year and returns a boolean.
bool LeapYear(int year);

// function 2: LastDayOfMonth
// returns the last day of the given month for the specified year (for February).
// takes an integer month and an optional integer year.
// returns an integer representing the number of days in the month.
int LastDayOfMonth(int month, int year = 0);

// function 3: ValidDate
// checks if the given date is valid (day, month, and year).
// take three integers: month, day, and year.
// returns a boolean indicating whether the date is valid.
bool ValidDate(int month, int day, int year);

// function 4: NextDate
// advances the given date by one day.
// take three integer reference arguments (month, day, year) and updates them.
void NextDate(int& month, int& day, int& year);

// function 5: PreviousDate
// move the given date back by one day.
// takes three integer reference arguments (month, day, year) and updates them.
void PreviousDate(int& month, int& day, int& year);

#endif  // PROGRAM2FUNCTIONS_H
