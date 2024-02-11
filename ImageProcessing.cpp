#include "ImageProcessing.h"
#include "image.h"

#include <algorithm>
#include <cmath>
#include <vector>

Color ImageProcessing::GetColorSafe(const Image &image, int x, int y) {
  x = std::max(0, std::min(x, image.GetWidth() - 1));
  y = std::max(0, std::min(y, image.GetHeight() - 1));
  return image.GetColor(x, y);
}

std::vector<std::vector<float>> GenerateGaussianKernel(int kernelSize,
                                                       float sigma) {
  std::vector<std::vector<float>> kernel(kernelSize,
                                         std::vector<float>(kernelSize));
  float sum = 0.0;

  int edge = kernelSize / 2;
  for (int y = -edge; y <= edge; y++) {
    for (int x = -edge; x <= edge; x++) {
      float exponent = -(x * x + y * y) / (2 * sigma * sigma);
      kernel[y + edge][x + edge] = exp(exponent) / (2 * M_PI * sigma * sigma);
      sum += kernel[y + edge][x + edge];
    }
  }

  // Normalize the kernel
  for (int i = 0; i < kernelSize; ++i)
    for (int j = 0; j < kernelSize; ++j)
      kernel[i][j] /= sum;

  return kernel;
}

void ImageProcessing::GaussianBlur(Image &image, int kernelSize, float sigma) {
  auto kernel = GenerateGaussianKernel(kernelSize, sigma);

  Image finalImage(image.GetWidth(), image.GetHeight());

  int edge = kernelSize / 2;
  for (int y = 0; y < image.GetHeight(); ++y) {
    for (int x = 0; x < image.GetWidth(); ++x) {
      float red = 0.0, green = 0.0, blue = 0.0;

      for (int ky = -edge; ky <= edge; ++ky) {
        for (int kx = -edge; kx <= edge; ++kx) {
          Color color = GetColorSafe(image, x + kx, y + ky);

          red += color.r * kernel[ky + edge][kx + edge];
          green += color.g * kernel[ky + edge][kx + edge];
          blue += color.b * kernel[ky + edge][kx + edge];
        }
      }

      // Clamp color values to the range [0, 1]
      red = std::min(std::max(red, 0.0f), 1.0f);
      green = std::min(std::max(green, 0.0f), 1.0f);
      blue = std::min(std::max(blue, 0.0f), 1.0f);

      finalImage.SetColor(Color(red, green, blue), x, y);
    }
  }
}
