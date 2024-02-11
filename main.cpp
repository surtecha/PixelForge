#include "image.h"
#include <iostream>

int main() {
  const char *imagePath = "test_image.bmp";

  Image image;
  image.Read(imagePath);

  Color color = image.GetColor(0, 0); // Get color of the top-left pixel
  std::cout << "Color of the top-left pixel: R=" << color.r << ", G=" << color.g
            << ", B=" << color.b << std::endl;

  return 0;
}
