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
    //image.saveImage("Lenna_standard_copy.pgm");
    ACTSHA001::Image mask;
    //mask.loadImage("Lenna_hat_mask.pgm");



    ACTSHA001::Image im2;
    im2.loadImage("Lenna_standard.pgm");

    ACTSHA001::Image im3;

    im3 = (im2+image);

    im3.saveImage("testadd.pgm");
    (im2-image).saveImage("should_be_black.pgm");
    (im3-im2).saveImage("should_be_normal.pgm");

    (!im2).saveImage("inverse.pgm");

    //(im2/mask).saveImage("test_mask.pgm");
    (!(im2*100) + im2).saveImage("thresh.pgm");


    return 0;
}
