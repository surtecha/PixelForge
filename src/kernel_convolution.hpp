#ifndef KERNEL_CONVOLUTION_HPP
#define KERNEL_CONVOLUTION_HPP

#include <vector>

struct Pixel    {
    unsigned char red, green, blue;
};

class kernel_convolution    {
    public:
        kernel_convolution(const std::vector<std::vector<Pixel>>& inputImage);  // Constructor

        std::vector<std::vector<Pixel>> mean_blur();
        std::vector<std::vector<Pixel>> gaussian_blur();
        std::vector<std::vector<Pixel>> edge_detection();
        std::vector<std::vector<Pixel>> sharpen();
        std::vector<std::vector<Pixel>> grayscale();
        std::vector<std::vector<Pixel>> blackhat_filter();
        std::vector<std::vector<Pixel>> apply_threshold(int thresh);              

    private:
        std::vector<std::vector<Pixel>> image;

        std::vector<std::vector<Pixel>> convolve(const std::vector<std::vector<float>>& kernel);
};

#endif