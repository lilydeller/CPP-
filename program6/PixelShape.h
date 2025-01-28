// copyright lily deller
// header defining interface and member functions

#ifndef CSCE240_PROGRAM6_PIXELSHAPE_H_
#define CSCE240_PROGRAM6_PIXELSHAPE_H_

#include <string>
#include <iostream> 

namespace CSCE240_Program6 {

// PixelShape class represents a shape defined by a name and a character pixel
// an abstract base class meant to be used by more specific shape types
class PixelShape {
 protected:
  std::string name_; 
  char pixel_;       // character used to represent the shape

 public:
  // constructor initializes shape name and pixel w defeault values if they weren't provided
  PixelShape(const std::string& name = "?", char pixel = '*');
  
  // virtual destructor for cleanup on derived classes
  virtual ~PixelShape();

  // set the name of the shape
  void SetName(const std::string& name);

  // set the pixel character of the shape
  void SetPixel(char pixel);

  // return the name of the shape
  std::string GetName() const;

  // return the pixel character of the shape
  char GetPixel() const;

  // virtual method to print the shape
  // `fill` parameter is for customization in derived classes like filled or outlined
  virtual void Print(bool fill = true) const;

  // virtual operator overload for scaling the shape -  can be overridden in derived classes 
  virtual PixelShape& operator*=(double scale) {
    return *this; 
  }
};

} // namespace CSCE240_Program6

#endif // CSCE240_PROGRAM6_PIXELSHAPE_H_
