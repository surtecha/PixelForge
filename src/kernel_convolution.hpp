#ifndef KERNEL_CONVOLUTION_HPP
#define KERNEL_CONVOLUTION_HPP

#include <vector>

struct Pixel    {
    unsigned char red, green, blue;
};

class kernel_convolution    {
    public:
        kernel_convolution(const std::vector<std::vector<Pixel>>& inputImage);  // Constructor
              

};

#endif