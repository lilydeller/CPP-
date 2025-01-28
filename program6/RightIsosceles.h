// copyright lily deller
#ifndef CSCE240_PROGRAM6_RIGHTISOSCELES_H_
#define CSCE240_PROGRAM6_RIGHTISOSCELES_H_

#include "PixelShape.h" 

namespace CSCE240_Program6 {

// class models a right isosceles triangle and inherits from PixelShape 
class RightIsosceles : public PixelShape {
 private:
  int leg_; // legth of the equal legs of the triangle

 public:
  // constructor initalizes the isosceles w specified leg lenth and pixel character
  RightIsosceles(int leg = 2, char pixel = '*');

  // destructor
  ~RightIsosceles() override;

  
  // updates the leg length of the triangle.
  void SetLeg(int leg);

  // returns the current leg length of the triangle 
  int GetLeg() const;

  // scales the triangle's leg length by a given factor 
  RightIsosceles& operator*=(double scale) override;


  // if `fill` is true the triangle is completely filled 
  // if `fill` is false ONLY the borders of the triangle are printed
  void Print(bool fill = true) const override;
};

} // namespace CSCE240_Program6

#endif // CSCE240_PROGRAM6_RIGHTISOSCELES_H_
