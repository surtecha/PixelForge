#ifndef KERNEL_CONVOLUTION_HPP
#define KERNEL_CONVOLUTION_HPP

class kernel_convolution    {
    public:
        int width, height, number_of_bands;
        unsigned char * image;

        void read_image(char **argv);
};

#endif