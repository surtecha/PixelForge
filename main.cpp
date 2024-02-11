#include "ImageProcessing.h"
#include "image.h"
#include <iostream>

int main() {
  const char *inputImagePath = "test_image.bmp";
  const char *outputImagePath = "blurred_image.bmp";

  Image image;
  image.Read(inputImagePath);

  // Apply Gaussian Blur to the image
  int kernelSize = 5; // Example kernel size
  float sigma = 3.0f; // Example standard deviation for Gaussian kernel
  ImageProcessing::GaussianBlur(image, kernelSize, sigma);

  // Export the blurred image
  image.Export(outputImagePath);
  std::cout << "Blurred image exported to " << outputImagePath << std::endl;

  return 0;
}
