#include "image.h"

#include <fstream>
#include <iostream>

Color::Color() : r(0), g(0), b(0) {}

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

Color::~Color() {}

Image ::Image(int width, int height)
    : m_width(width), m_height(height),
      m_colors(std::vector<Color>(width * height)) {}

Image::~Image() {}

Color Image::GetColor(int x, int y) const { return m_colors[y * m_width + x]; }

void Image::SetColor(const Color &color, int x, int y) {
  m_colors[y * m_width + x].r = color.r;
  m_colors[y * m_width + x].g = color.g;
  m_colors[y * m_width + x].b = color.b;
}

void Image::Export(const char *path) const {
  std::ofstream f;
  f.open(path, std::ios::out | std::ios::binary);

  if (!f.is_open()) {
    std::cout << "File could not be opened\n";
    return;
  }
  unsigned char bmpPad[3] = {0, 0, 0};
  const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

  const int fileHeaderSize = 14;
  const int informationHeaderSize = 40;
  const int fileSize = fileHeaderSize + informationHeaderSize +
                       m_width * m_height * 3 + paddingAmount * m_height;
}
