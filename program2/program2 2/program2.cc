// copyright lily deller
#include <iostream> // to provide basic input and output 
#include "program2functions.h" // include the header file 
using namespace std;

int main() {
    // declare variables for two dates
    int month1, day1, year1;
    int month2, day2, year2;
    char separator;  // so we can handle the '/' character between month/day/year

    // input two dates from the user in the format month/day/year
    cin >> month1 >> separator >> day1 >> separator >> year1;
    cin >> month2 >> separator >> day2 >> separator >> year2;

    // validate both dates using the ValidDate function
    bool isValidDate1 = ValidDate(month1, day1, year1);
    bool isValidDate2 = ValidDate(month2, day2, year2);

    // check both dates for validity and output errors if invalid
    if (!isValidDate1) {
        cout << month1 << '/' << day1 << '/' << year1 << " is not a valid date" << endl;
    }

    if (!isValidDate2) {
        cout << month2 << '/' << day2 << '/' << year2 << " is not a valid date" << endl;
    }

    // if either date is invalid, return to exit
    if (!isValidDate1 || !isValidDate2) {
        return 0;  // exit if any date is invalid
    }

    // step 3: compute the number of days between the two dates
    int daysDifference = 0;

    // so we can create  backup variables to preserve the original dates
    int backupMonth1 = month1, backupDay1 = day1, backupYear1 = year1;

    // first date is earlier than the second, use NextDate
    while (month1 != month2 || day1 != day2 || year1 != year2) {
        if (year1 < year2 || (year1 == year2 && month1 < month2) || 
            (year1 == year2 && month1 == month2 && day1 < day2)) {
            NextDate(month1, day1, year1);
            daysDifference++;
        } 
        // if first date is later than the second, use PreviousDate
        else {
            PreviousDate(month1, day1, year1);
            daysDifference--;
        }
    }

    // step 4: output the result based on the computed difference
    if (daysDifference == 0) {
        cout << backupMonth1 << '/' << backupDay1 << '/' << backupYear1 
             << " is 0 days before " << month2 << '/' << day2 << '/' << year2 << endl;
    } else if (daysDifference > 0) {
        cout << backupMonth1 << '/' << backupDay1 << '/' << backupYear1
             << " is " << daysDifference << " days before "
             << month2 << '/' << day2 << '/' << year2 << endl;
    } else {
        cout << backupMonth1 << '/' << backupDay1 << '/' << backupYear1
             << " is " << -daysDifference << " days after "
             << month2 << '/' << day2 << '/' << year2 << endl;
    }

    return 0;
}
