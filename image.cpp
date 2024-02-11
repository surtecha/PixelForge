#include "image.h"

#include <cstring>
#include <fstream>
#include <iostream>

// Color class constructors and destructor
Color::Color() : r(0), g(0), b(0) {}

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

Color::~Color() = default; // Use default if the destructor does nothing

// Default constructor for the Image class
Image::Image() = default; // This implements the default constructor

// Constructor with width and height for the Image class
Image::Image(int width, int height)
    : m_width(width), m_height(height),
      m_colors(std::vector<Color>(width * height)) {}

// Destructor for the Image class
Image::~Image() = default; // Use default if the destructor does nothing

// SetDimensions for the Image class
void Image::SetDimensions(int width, int height) {
  m_width = width;
  m_height = height;
  m_colors.resize(width *
                  height); // Resize the vector to fit the new dimensions
}

// GetColor function
Color Image::GetColor(int x, int y) const {
  return m_colors[y * m_width +
                  x]; // Access the color at the specified location
}

// SetColor function
void Image::SetColor(const Color &color, int x, int y) {
  m_colors[y * m_width + x] = color; // Set the color at the specified location
}

// Read function to load an image from a file
void Image::Read(const char *path) {
  std::ifstream f;
  f.open(path, std::ios::in | std::ios::binary);

  if (!f.is_open()) {
    std::cout << "File could not be opened\n";
    return;
  }

  const int fileHeaderSize = 14;
  const int informationHeaderSize = 40;

  unsigned char fileHeader[fileHeaderSize];
  f.read(reinterpret_cast<char *>(fileHeader), fileHeaderSize);

  // Check if the image read is of .bmp format
  if (fileHeader[0] != 'B' || fileHeader[1] != 'M') {
    f.close();
    std::cout << "Not a bitmap image\n";
    return;
  }

  unsigned char informationHeader[informationHeaderSize];
  f.read(reinterpret_cast<char *>(informationHeader), informationHeaderSize);

  // Read image dimensions from the information header
  m_width = informationHeader[4] + (informationHeader[5] << 8) +
            (informationHeader[6] << 16) + (informationHeader[7] << 24);
  m_height = informationHeader[8] + (informationHeader[9] << 8) +
             (informationHeader[10] << 16) + (informationHeader[11] << 24);

  m_colors.resize(m_width *
                  m_height); // Resize the vector based on the image dimensions

  const int paddingAmount = ((4 - (m_width * 3) % 4) % 4);

  for (int y = 0; y < m_height; y++) {
    for (int x = 0; x < m_width; x++) {
      unsigned char color[3];
      f.read(reinterpret_cast<char *>(color), 3);

      m_colors[y * m_width + x].r = color[2] / 255.0f;
      m_colors[y * m_width + x].g = color[1] / 255.0f;
      m_colors[y * m_width + x].b = color[0] / 255.0f;
    }
    f.ignore(paddingAmount); // Skip padding bytes at the end of each row
  }
  f.close();
  std::cout << "The file read successfully\n";
}

// Export function - currently a stub with no implementation
void Image::Export(const char *path) const {
  std::ofstream file(path, std::ios::out | std::ios::binary);
  if (!file) {
    std::cerr << "Could not open file for writing.\n";
    return;
  }

  // BMP files have a 54-byte header
  unsigned char header[54] = {0};
  int fileSize = 54 + 3 * m_width * m_height; // 3 bytes per pixel
  int dataOffset = 54;
  int headerSize = 40;
  int planes = 1;
  int bitsPerPixel = 24;
  int compression = 0;
  int imageSize = 3 * m_width * m_height;
  int ppm = 2835; // 72 DPI in pixels per meter

  // Fill the header
  header[0] = 'B';
  header[1] = 'M';
  memcpy(header + 2, &fileSize, 4);
  memcpy(header + 10, &dataOffset, 4);
  memcpy(header + 14, &headerSize, 4);
  memcpy(header + 18, &m_width, 4);
  memcpy(header + 22, &m_height, 4);
  memcpy(header + 26, &planes, 2);
  memcpy(header + 28, &bitsPerPixel, 2);
  memcpy(header + 30, &compression, 4);
  memcpy(header + 34, &imageSize, 4);
  memcpy(header + 38, &ppm, 4);
  memcpy(header + 42, &ppm, 4);

  file.write(reinterpret_cast<char *>(header), 54);

  // Write pixel data
  for (int y = 0; y < m_height; y++) { // BMP stores pixels bottom-to-top
    for (int x = 0; x < m_width; x++) {
      Color color = m_colors[y * m_width + x];
      unsigned char pixel[3] = {static_cast<unsigned char>(color.b * 255),
                                static_cast<unsigned char>(color.g * 255),
                                static_cast<unsigned char>(color.r * 255)};
      file.write(reinterpret_cast<char *>(pixel), 3);
    }

    // Row padding
    unsigned char padding[3] = {0, 0, 0};
    int paddingSize = (4 - (m_width * 3) % 4) % 4;
    if (paddingSize) {
      file.write(reinterpret_cast<char *>(padding), paddingSize);
    }
  }

  file.close();
  std::cout << "Image exported successfully to " << path << std::endl;
}
