// copyright lily deller
#include "height.h"
#include <iostream>
#include <string>
#include <map>

Height::Height(double val, std::string unit) : value(0), units("feet") {
    SetValue(val);
    SetUnits(unit);
}

bool Height::SetValue(double val) {
    if (val >= 0) {
        value = val;
        return true;
    }
    return false;
}

double Height::GetValue() const {
    return value;
}

bool Height::SetUnits(std::string unit) {
    if (unit == "inches" || unit == "feet" || unit == "centimeters" || unit == "meters") {
        units = unit;
        return true;
    }
    return false;
}

std::string Height::GetUnits() const {
    return units;
}

void Height::ConvertUnits(std::string newUnit) {
    if (units == newUnit) return; // 

    // conversion factors
    std::map<std::pair<std::string, std::string>, double> conversionFactors = {
        {{"feet", "inches"}, 12.0},
        {{"inches", "feet"}, 1.0 / 12.0},
        {{"feet", "centimeters"}, 30.48},
        {{"centimeters", "feet"}, 1.0 / 30.48},
        {{"feet", "meters"}, 0.3048},
        {{"meters", "feet"}, 1.0 / 0.3048},
        {{"inches", "centimeters"}, 2.54},
        {{"centimeters", "inches"}, 1.0 / 2.54},
        {{"inches", "meters"}, 0.0254},
        {{"meters", "inches"}, 1.0 / 0.0254},
        {{"centimeters", "meters"}, 0.01},
        {{"meters", "centimeters"}, 100.0}
    };

    if (conversionFactors.count({units, newUnit})) {
        value *= conversionFactors[{units, newUnit}];
        units = newUnit;
    }
}

std::ostream& operator<<(std::ostream& os, const Height& h) {
    os << h.value << " " << h.units;
    return os;
}
