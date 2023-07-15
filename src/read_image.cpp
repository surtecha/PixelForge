#include <limits>
#include "read_image.hpp"

std::vector<std::vector<Pixel>> read_image::read_PPM(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if(!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return std::vector<std::vector<Pixel>>(); // Return an empty vector on error
    }

    std::string format;
    int width, height, maxVal;
    file >> format >> width >> height >> maxVal;

    if(format != "P6" || maxVal != 255) {
        std::cerr << "Invalid PPM format or max value" << std::endl;
        return std::vector<std::vector<Pixel>>(); // Return an empty vector on error
    }

    // Skip newline character
    file.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


    std::vector<std::vector<Pixel>> pixels(height, std::vector<Pixel>(width));
    for(int row = 0; row < height; ++row) {
        file.read(reinterpret_cast<char*>(pixels[row].data()), width * sizeof(Pixel));
    }

    return pixels;
}
