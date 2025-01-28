//copyright lily deller
#include <iostream> // standard input output library
using namespace std;

//function to add a digit to our integer
int addDigit(int input, int digit) {
    return input * 10 + digit;
}

//function to check if prime
bool isPrime(int n) {
    if (n <= 1) return false; // mumbers less than or equal to 1 are NOT prime
    if (n == 2 || n == 3) return true; // 2 and three are prime
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

//calculate power of number
int power(int base, int exp) {
    int result = 1;
    for (int i = 0; i < exp; i++) {
        result *= base;
    }
    return result;
}

int main() {
    char unfiltered[100]; //store input
    cin.getline(unfiltered, 100);

    int goal = 0;
    int pos_neg = 1;
    int stored[20][2] = {{0}}; //store the base and expondent for prime factorizeation

    bool valid_format = true;

    int i = 0;
    if (unfiltered[0] == '-') {
        pos_neg = -1;
        i++;
    }
    while (unfiltered[i] >= '0' && unfiltered[i] <= '9') {
        goal = addDigit(goal, unfiltered[i] - '0');
        i++;
    }
    goal *= pos_neg;

    while (unfiltered[i] != '=') {
        i++; //if theres no = sign this will crash
    }
    i++;

    while (unfiltered[i] == ' ') i++;

    if (unfiltered[i] == '-') {
        pos_neg = -1;
        i+=2; //steping past - and 1
    }
    else if (unfiltered[i] == '1') {
        pos_neg = 1;
        i++; //steping past the 1
    }
    else {
        cout << "Invalid input format." << endl;
        return 0;
    }

    while (unfiltered[i] == ' ' || unfiltered[i] == '*') i++;

    int row = 0;
    int column = 0;
    while (unfiltered[i] != '?' && valid_format) {
        if (unfiltered[i] == '*') {
            column = 0;
            row++;
            while (unfiltered[i] == ' ' || unfiltered[i] == '*') i++;
        }
        else if (unfiltered[i] == '^') {
            column = 1;
            i++;
        }
        else if (unfiltered[i] >= '0' && unfiltered[i] <= '9') {
            stored[row][column] = addDigit(stored[row][column], unfiltered[i] - '0'); 
            i++;
        }
        else if (unfiltered[i] == ' ') {
            i++;
        }
        else {
            valid_format = false; // false if we find an invalid character
        }
    }

    if (!valid_format) {
        cout << "Invalid input format." << endl;
        return 0;
    }
//math 
    int computed_value = pos_neg;
    for (int j = 0; j <= row; j++) {
        if (!isPrime(stored[j][0]) || stored[j][0] == 0 || stored[j][1] == 0) {
            valid_format = false;
            break; //exit the loop
        }
        computed_value *= power(stored[j][0], stored[j][1]);
    }

    if (!valid_format) {
        cout << "Invalid input format." << endl; //our error message
        return 0;
    }

    if (computed_value == goal) {
        cout << "Correct!" << endl; //if value matches our goal
    }
    else {
        cout << "Incorrect." << endl; //if value doesn't match goal
    }

    return 0;
}
//the end