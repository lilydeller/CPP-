// copyright lily deller
// derives from PixelShape 

#ifndef CSCE240_PROGRAM6_RECTANGLE_H_
#define CSCE240_PROGRAM6_RECTANGLE_H_

#include "PixelShape.h" 

namespace CSCE240_Program6 {

// inheriting from PixelShape - represents rectangle w specifications
class Rectangle : public PixelShape {
 private:
  int length_; // length of the rectangle
  int width_;  // width of the rectangle

 public:
  // constructor - initialize rectangle w legth width and the pixels 
  Rectangle(int length = 2, int width = 1, char pixel = '*');

  // destructor 
  ~Rectangle() override;

  // set the length of the rectangle
  void SetLength(int length);

  // sets the width of the rectangle
  void SetWidth(int width);

  // get the current length of the rectangle
  int GetLength() const;

  // get the current width of the rectangle.
  int GetWidth() const;

  // overloaded *= operator - make sure both dimensions remain valid 
  Rectangle& operator*=(double scale) override;

  // print the rectangle  
  void Print(bool fill = true) const override;
};

}  // namespace CSCE240_Program6

#endif  // CSCE240_PROGRAM6_RECTANGLE_H_
