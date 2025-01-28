// copyright lily deller
#ifndef HEIGHT_H
#define HEIGHT_H

#include <iostream>
#include <string>
#include <map>

class Height {
private:
    double value;      // height value
    std::string units; // units of height

public:
    // constructor with default arguments
    Height(double val = 0, std::string unit = "feet");

    // mutators
    bool SetValue(double val);
    bool SetUnits(std::string unit);

    // accessors
    double GetValue() const;
    std::string GetUnits() const;

    // conversion
    void ConvertUnits(std::string newUnit);

    // overloaded operator for output
    friend std::ostream& operator<<(std::ostream& os, const Height& h);
};

#endif 