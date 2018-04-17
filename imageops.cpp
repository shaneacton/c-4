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


    cout<<"loaded image"<<endl;

    return 0;
}
