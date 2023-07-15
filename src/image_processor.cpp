#include <iostream>
#include "read_image.hpp"
#include "kernel_convolution.hpp"

int main()  {
    std::string filename = "imagefile.ppm";
    std::vector<std::vector<Pixel>> pixels = read_image::read_PPM(filename);

    if(pixels.empty()) {
        std::cerr << "Error reading image file." << std::endl;
        return 1;
    }


    // Accessing individual pixels' RGB values
    for(size_t i=0; i<pixels.size(); i++)   {
        for(size_t j=0; j<pixels[i].size(); j++)    {
            
            const Pixel& pixel = pixels[i][j];
            unsigned char 
                            red   = pixel.red,
                            green = pixel.green,
                            blue  = pixel.blue;
            
        }
    }


    return 0;
}
