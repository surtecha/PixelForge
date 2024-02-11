#pragma once

#include <vector>

struct Color {
  float r, g, b;

  Color();
  Color(float r, float g, float b);
  ~Color();
};

class Image {
public:
  Image();
  Image(int width, int height);
  ~Image();

  // Returns color pixel position
  Color GetColor(int x, int y) const;

  // Sets color at the pixel position
  void SetColor(const Color &color, int x, int y);

  void Read(const char *path);

  void SetDimensions(int width, int height);

  void Export(const char *path) const;

  int GetWidth() const { return m_width; };
  int GetHeight() const { return m_height; };

private:
  int m_width{0};
  int m_height{0};
  std::vector<Color> m_colors;
};
