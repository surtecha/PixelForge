#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

#include "kernel_convolution.h"

#define MAX_PIXEL_VALUE 255
#define KERNEL_SIZE 3

using namespace std;

int main()  {

    ofstream image;
    image.open("image.ppm");

    if(image.is_open()) {
        // function to call other image processing functions 
    }
}
