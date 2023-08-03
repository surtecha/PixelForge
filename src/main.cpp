#include "Image.h"

int main(int argc, char** argv) {
    Image test("test.jpg");
    test.write("new.jpg");
    
    Image copy = test;
    for(int i=0; i<copy.w*copy.channels; ++i)  {
        copy.data[i] = 255;
    }
    
    copy.write("copy.jpg");
    Image blank(100, 100, 3);
    blank.write("blank.jpg");

    return 0;
}