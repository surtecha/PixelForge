#ifndef READ_IMAGE_HPP
#define READ_IMAGE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct Pixel
{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
};

class read_image    {
    public:
        static std::vector<std::vector<Pixel>> read_PPM(const std::string& filename);
};

#endif