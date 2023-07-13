#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>

using namespace std;

int main()  {

    ofstream image;
    image.open("image.ppm");

    if(image.is_open()) {

        image << "P3" << endl;
        image << "250 250" << endl;
        image << "255" << endl; // RGB max
    
        for(int x=0; x<250; x++)    {
            for(int y=0; y<250; y++)    {
                image << min((x+y), 255) << " "     // R
                      << min((x+y), 255) << " "     // G
                      << min((x+y), 255) << endl;   // B
            }
        }
    }

    image.close();


    return 0;
}