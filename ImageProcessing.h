#pragma once

#include "image.h"

class ImageProcessing {
public:
  static void GaussianBlur(Image &image, int kernelSize, float sigma);

  static void MeanBlur();

  static void SobelOperator();

  static void CannyEdgeDetector();

  static void Sharpner();

  static void GrayScale();

  static void Flip();

  static void BlackhatFilter();

  static void LinearFiltering();

private:
  static Color GetColorSafe(const Image &image, int x, int y);
};
