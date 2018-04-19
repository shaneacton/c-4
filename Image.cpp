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
    Image im;
    im.width = width;
    im.height = height;
    if(checkCompatible(*this,rhs)){
        for(int row=0;row<height;row++){
            im.image.push_back(new unsigned char[width]);
            for(int col=0;col,width;col++){
                int num = clamp((*this).image[row][col] + rhs.image[row][col]);
                cout<<"summing values " << (int)((*this).image[row][col]) << " + " << (int)(rhs.image[row][col]) << " = " << num << endl;
                im.image[row][col] = (unsigned char)num;
            }
        }
    }
}

unsigned char ACTSHA001::Image::clamp(const int &i) {
    return (unsigned char)min(255,max(0,i));
}

bool ACTSHA001::Image::checkCompatible(const ACTSHA001::Image &lhs, const ACTSHA001::Image &rhs) {
    if(height==rhs.height && width==rhs.width){
        return true;
    }else{
        cout<<"images are not the same dimension"<<endl;
        return false;
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
    data = unique_ptr<unsigned char[]>(new unsigned char[width*height]);

    getline(file,line);

    iterator it = begin();
    for(int row=0;row<height;row++){
        image.push_back(new unsigned char[width]);
        file.read((char*)image[row],width);
        //cout<< "finished "<< (row+1) << endl;
        for(int col=0;col++;col<width){
            *it = image[row][col];
            ++it;
        }
    }

    file.close();

}

void ACTSHA001::Image::saveImage(std::string fileName) {
    ofstream out("images/"+fileName);
    if(height==0||width==0){
        cout<<"no image loaded to this object"<<endl;
        return;
    }
    /**
    out.write("P5\n",3);
    out.write("#\n",2);
    string dims = to_string(height) + " " + to_string(width) ;
    cout<<"'"<<dims<<"'"<<endl;
    out.write("dims\n",dims.size()+1);
    out.write("255\n",4);
*/


    iterator it = begin();
    for(auto it = begin(); it!= end();++it){
        out.put(*it);
        ++it;
    }
/**
    for(int row=0;row<height;row++){
        out.write((char*)image[row],width);
        //cout<< "finished "<< (row+1) << endl;
    }
*/
    out.close();
}

ACTSHA001::Image::iterator& ACTSHA001::Image::iterator::operator++() {
    ptr+= sizeof(char);
    return *this;
}
ACTSHA001::Image::iterator& ACTSHA001::Image::iterator::operator--() {
    ptr-= sizeof(char);
    return *this;
}
ACTSHA001::Image::iterator& ACTSHA001::Image::iterator::operator=(const iterator & rhs) {
    ptr=rhs.ptr;
    return *this;
}
unsigned char & ACTSHA001::Image::iterator::operator*() {
    return *ptr;
}
bool ACTSHA001::Image::iterator::operator!=(const iterator & rhs) {
    return ptr!=rhs.ptr;
}
