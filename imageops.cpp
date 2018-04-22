//
// Created by actsha001 on 2018/04/17.
//
#include <iostream>
#include "Image.h"

using namespace std;

int main(int argc, char* argv[]) {
    if(argc < 2) {
        //test runs
        std::cout << "Hello, World!" << std::endl;

        ACTSHA001::Image image;
        ACTSHA001::Image im2;
        ACTSHA001::Image im3;
        ACTSHA001::Image mask;


        image<<"Lenna_standard";
        mask<<"Lenna_hat_mask.pgm";
        im2<<"Lenna_standard";


        im3 = (im2 + image) + im2;

        im3>>"testadd3";

    }else{
        for(int i=0;i<argc;i++){
            cout<<argv[i]<<endl;
        }

        string op = argv[1];

    }



    return 0;
}
