// copyright lily deller
// derives from pixelshape

#include "Rectangle.h"

namespace CSCE240_Program6 {

// constructor for rectangle - make sure length and width are atleast 1 
Rectangle::Rectangle(int length, int width, char pixel)
    : PixelShape("rectangle", pixel), length_(length), width_(width) {
  if (length_ < 1) {
    length_ = 2; // defailt length if not valid
  }
  if (width_ < 1) {
    width_ = 1; // default width if not valid 
  }
}

// destructor for rectangle
Rectangle::~Rectangle() {}

// set the rectangle's length to a new value 
void Rectangle::SetLength(int length) {
  if (length > 0) {
    length_ = length;
  }
}

// sets the rectangle's width to a new value 
void Rectangle::SetWidth(int width) {
  if (width > 0) {
    width_ = width;
  }
}

// return the current length of the rectangle
int Rectangle::GetLength() const {
  return length_;
}

// return the current width of the rectangle
int Rectangle::GetWidth() const {
  return width_;
}

// scale the rectangle's dimensions by the specified factor
Rectangle& Rectangle::operator*=(double scale) {
  int new_length = static_cast<int>(length_ * scale);
  int new_width = static_cast<int>(width_ * scale);

  if (new_length >= 1 && new_width >= 1) {
    length_ = new_length;
    width_ = new_width;
  }
  return *this;
}

// print the rectangle to the console 
// `fill` is true the rectangle is filled with the pix character
// `fill` is false ONLY the border of the rectangle is printed
void Rectangle::Print(bool fill) const {
  std::cout << name_ << std::endl; 
  for (int i = 0; i < length_; ++i) {
    for (int j = 0; j < width_; ++j) {
      if (fill || i == 0 || i == length_ - 1 || j == 0 || j == width_ - 1) {
        std::cout << pixel_ << ' ';
      } else {
        std::cout << "  "; // empty space 
      }
    }
    std::cout << std::endl; // new line after each row
  }
}

} // namespace CSCE240_Program6
