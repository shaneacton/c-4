//
// Created by actsha001 on 2018/04/17.
//
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iterator>

#include "Image.h"

using namespace std;

ACTSHA001::Image::Image() {
    height=0;
    width=0;
}

ACTSHA001::Image& ACTSHA001::Image::operator+(const ACTSHA001::Image &rhs) {
    if(height==rhs.height && width==rhs.width){

    for(int row=0;row<height;row++){
        image.push_back(new unsigned char[width]);
    }}
}

bool ACTSHA001::Image::checkCompatible(const ACTSHA001::Image &lhs, const ACTSHA001::Image &rhs) {
    if(height==rhs.height && width==rhs.width){


    }else{
        cout<<"images are not the same size";
    }
}

void ACTSHA001::Image::loadImage(std::string fileName){
    cout<<"attempting to load image: " << fileName<<endl;

    ifstream file("images/"+fileName, ios::in | ios::binary);

    string line;
    getline(file,line);
    getline(file,line);//skip first two lines
    getline(file,line);

    istringstream b(line);
    istream_iterator<string> i(b), end;
    vector<string> tokens(i,end);

    width = stoi(tokens[1]);
    height = stoi(tokens[0]);

    cout<<"width: " <<width << "  height: " << height << endl;
    //file.close();
    //image.reserve(height);

    getline(file,line);
    for(int row=0;row<height;row++){
        image.push_back(new unsigned char[width]);
    }

    for(int row=0;row<height;row++){
        file.read((char*)image[row],width);
        //cout<< "finished "<< (row+1) << endl;
    }

    file.close();

}

void ACTSHA001::Image::saveImage(std::string fileName) {
    ofstream out("images/"+fileName);
    if(height==0||width==0){
        cout<<"no image loaded to this object"<<endl;
        return;
    }
    //out.write("P5\n",3);
    //out.write("#\n",2);
    //string dims = to_string(height) + " " + to_string(width) ;
    //cout<<"'"<<dims<<"'"<<endl;
    //out.write("dims\n",dims.size()+1);
    //out.write("255\n",4);




    for(int row=0;row<height;row++){
        out.write((char*)image[row],width);
        //cout<< "finished "<< (row+1) << endl;
    }

    out.close();
}

