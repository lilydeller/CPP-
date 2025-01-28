// copyright lily deller
// the implementation of the PixelShape class

#include "PixelShape.h"

namespace CSCE240_Program6 {

// constructor for PixelShape (goal to initalize shape's name and pixel character, it the name is empty will default to ?)
PixelShape::PixelShape(const std::string& name, char pixel)
    : name_(!name.empty() ? name : "?"), pixel_(pixel) {
  if (pixel_ < 33 || pixel_ > 126) { // ASCII printable range check
    pixel_ = '*'; // Default pixel character
  }
}

// destructor for PixelShape (not doing much)
PixelShape::~PixelShape() {}

// set the name of the shape when the provided name is not empty 
void PixelShape::SetName(const std::string& name) {
  if (!name.empty()) {
    name_ = name;
  }
}

// sets the pixel character if its within the printable range.
void PixelShape::SetPixel(char pixel) {
  if (pixel >= 33 && pixel <= 126) { // our printable range
    pixel_ = pixel;
  }
}

// retrieve the name of the shape
std::string PixelShape::GetName() const {
  return name_;
}

// retrieve the pixel character of the shape 
char PixelShape::GetPixel() const {
  return pixel_;
}

// print the name of the shape
void PixelShape::Print(bool fill) const {
  std::cout << name_ << std::endl; // output the shape name
}

} // namespace CSCE240_Program6
