#include <cstdint>
#include <stdlib.h>

struct Image {
    uint8_t* data = nullptr;
    size_t size = 0; 
    int w;
    int h;
    int channels;

    Image(const char* filename);    // Accepts a filename
    Image(int w, int h, int channels);  // Creating a blank black image
    Image(const Image& img);  // Copy images
    ~Image();   // Destructor

    bool read(const char* filename);    // Read a file
    bool write(const char* filename);   // Write a file
    
};