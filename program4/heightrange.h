// copyright lily deller
#ifndef HEIGHTRANGE_H
#define HEIGHTRANGE_H

#include "height.h"

class HeightRange {
private:
    Height shortest; // shortest Height
    Height tallest;  // tllest Height

public:
    // default constructor
    HeightRange();

    // costructor with two heights
    HeightRange(const Height& h1, const Height& h2);

    // mutators
    void SetShortest(const Height& h);
    void SetTallest(const Height& h);

    // accessors
    Height GetShortest() const;
    Height GetTallest() const;

    // fuction to check if a height in the range
    bool InRange(const Height& h, bool includeEndpoints = true) const;

    // width of the range
    Height Width() const;
};

#endif 
