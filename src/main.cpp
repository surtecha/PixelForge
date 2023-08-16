#include "Image.h"

int main(int argc, char** argv){
    Image test("test.jpg");
    test.write("new.png");
    Image copy = test;

    for(int i=0; i<copy.w*copy.channels; ++i){
        copy.data[i] = 255;
    }
    copy.write("copy.png");
    Image blank("blank.jpg");
    blank.write("blank.jpg");

    return 0;
}