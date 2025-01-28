// copyright lily deller 
#include "RightIsosceles.h"

namespace CSCE240_Program6 {

// constructor 
// given leg length and pixel character 
RightIsosceles::RightIsosceles(int leg, char pixel)
    : PixelShape("right isosceles triangle", pixel), leg_(leg) {
  if (leg_ < 2) { 
    leg_ = 2;
  }
}

// destructor
RightIsosceles::~RightIsosceles() {}

// set the leg length of the triangle
void RightIsosceles::SetLeg(int leg) {
  if (leg >= 2) {
    leg_ = leg;
  }
}

// retrieve the current leg length of the triangle.
int RightIsosceles::GetLeg() const {
  return leg_;
}

// overloaded *= operator
RightIsosceles& RightIsosceles::operator*=(double scale) {
  int new_leg = static_cast<int>(leg_ * scale); 
  if (new_leg >= 2) { // validate the new leg length
    leg_ = new_leg;
  }
  return *this;
}

// print right isosceles triangle to the console.
// if `fill` is true triangle is filled with pixel 
// if `fill` is false only the border 
void RightIsosceles::Print(bool fill) const {
  std::cout << name_ << std::endl; 
  for (int i = 1; i <= leg_; ++i) { 
    for (int j = 1; j <= i; ++j) { 
      if (fill || j == 1 || j == i || i == leg_) {
        std::cout << pixel_ << ' ';
      } else {
        std::cout << "  "; // print space for the hollow triangles
      }
    }
    std::cout << std::endl; 
  }
}

} // namespace CSCE240_Program6
