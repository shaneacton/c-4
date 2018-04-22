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
            //cout<<argv[i]<<endl;
        }

        string op = argv[1];
        string out;
        ACTSHA001::Image l1;
        ACTSHA001::Image l2;

        l1 << argv[2];
        if(op != "-i" && op != "-t"){
            l2<< argv[3];
            out = argv[4];
            if(op == "-a"){
                cout<<"adding images"<<endl;
                (l1+l2)>>out;
            }
            if(op == "-s"){
                cout<<"subtracting images"<<endl;
                (l1-l2)>>out;
            }
            if(op == "-l"){
                cout<<"masking images"<<endl;
                (l1/l2)>>out;
            }
        }else{
            if(op == "-i"){
                out = argv[3];

                cout<<"inverting image"<<endl;
                (!l1)>>out;
            }
            if(op == "-t"){
                int f = stoi(argv[3]);
                out = argv[4];

                cout<<"applying threshold to image"<<endl;
                (l1*f)>>out;
            }
        }


    }



    return 0;
}
