//
// Created by actsha001 on 2018/04/17.
//
#include <iostream>
#include "Image.h"

using namespace std;

int main() {
    std::cout << "Hello, World!" << std::endl;

    ACTSHA001::Image image;
    image.loadImage("Lenna_standard.pgm");
    image.saveImage("Lenna_standard_copy.pgm");


    ACTSHA001::Image im2;
    im2.loadImage("Lenna_standard.pgm");

    ACTSHA001::Image im3;



    im3 = (im2+image);
    cout<<"added size: " << sizeof(im3) <<endl;

    im3.saveImage("testadd.pgm");

    return 0;
}
