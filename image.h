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
  Image(int width, int height);
  ~Image();

  // Returns color pixel position
  Color GetColor(int x, int y) const;

  // Sets color at the pixel position
  void SetColor(const Color &color, int x, int y);

  void Export(const char *path) const;

private:
  int m_width;
  int m_height;
  std::vector<Color> m_colors;
};
