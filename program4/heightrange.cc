// copyright lily deller
#include "heightrange.h"
#include <iostream>

// default constructor
HeightRange::HeightRange() : shortest(0, "feet"), tallest(0, "feet") {}

// constructor with two heights
HeightRange::HeightRange(const Height& h1, const Height& h2) {
    Height h1Converted = h1;
    Height h2Converted = h2;

    // convert both heights to a common unit for comparison
    h1Converted.ConvertUnits("feet");
    h2Converted.ConvertUnits("feet");

    if (h1Converted.GetValue() <= h2Converted.GetValue()) {
        shortest = h1;
        tallest = h2;
    } else {
        shortest = h2;
        tallest = h1;
    }
}


void HeightRange::SetShortest(const Height& h) {
    Height hConverted = h;
    hConverted.ConvertUnits(tallest.GetUnits()); // convert for consistent comparison
    if (hConverted.GetValue() <= tallest.GetValue()) {
        shortest = h;  
    } else {
        std::cerr << "Error: New shortest height exceeds the current tallest height." << std::endl;
    }
}

 
void HeightRange::SetTallest(const Height& h) {
    Height hConverted = h;
    hConverted.ConvertUnits(shortest.GetUnits()); // convert for consistent comparison
    if (hConverted.GetValue() >= shortest.GetValue()) {
        tallest = h;  // 
    } else {
        std::cerr << "Error: New tallest height is less than the current shortest height." << std::endl;
    }
}

// GetShortest
Height HeightRange::GetShortest() const {
    return shortest;
}

// GetTallest
Height HeightRange::GetTallest() const {
    return tallest;
}

// InRange function
bool HeightRange::InRange(const Height& h, bool includeEndpoints) const {
    Height hConverted = h;
    hConverted.ConvertUnits(shortest.GetUnits()); // match units for comparison

    bool withinShortest = (hConverted.GetValue() > shortest.GetValue()) ||
                          (includeEndpoints && hConverted.GetValue() == shortest.GetValue());
    bool withinTallest = (hConverted.GetValue() < tallest.GetValue()) ||
                         (includeEndpoints && hConverted.GetValue() == tallest.GetValue());
    return withinShortest && withinTallest;
}

// width function
Height HeightRange::Width() const {
    Height tempShortest = shortest;
    tempShortest.ConvertUnits(tallest.GetUnits()); // make sure units are consistent
    double widthValue = tallest.GetValue() - tempShortest.GetValue();
    return Height(widthValue, tallest.GetUnits());
}
