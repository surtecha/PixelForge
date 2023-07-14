#pragma once
class kernel_convolution   
{
    public:
        kernel_convolution(int width, int height);
        int getDimensions();
        void convolve();
    
    private:
        int w, h;
};