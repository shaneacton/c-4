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

ACTSHA001::Image im;

ACTSHA001::Image& ACTSHA001::Image::operator+(const ACTSHA001::Image &rhs) const {
    //Image im;

    im = Image(*this);

    if(checkCompatible(*this,rhs)){

        //int count=0;
        iterator rhit = rhs.begin();
        iterator resit = im.begin();
        int count = 0;
        for(auto it = begin(); it!= End();++it){
            //out.put(*it);
            //cout<<"lhs char val: " << (int)*it << " rhs char value: " << (int)*rhit << " result val = "<<  (int)(unsigned char)clamp(*it + *rhit) <<endl;
            //cout<<"before: "<< (int)*resit;
            *resit = (unsigned char)clamp(*it + *rhit);
            //cout<<" after: "<< (int)*resit<<endl;
            ++rhit;
            ++resit;
            count++;
        }
        cout<<"added " << count<< " chars together"<<endl;
    }

    return im;
}

ACTSHA001::Image& ACTSHA001::Image::operator-(const ACTSHA001::Image &rhs) const {
    //Image im;

    im = Image(*this);

    if(checkCompatible(*this,rhs)){

        iterator rhit = rhs.begin();
        iterator resit = im.begin();
        int count = 0;
        for(auto it = begin(); it!= End();++it){
            *resit = (unsigned char)clamp(*it - *rhit);
            ++rhit;
            ++resit;
        }
    }

    return im;
}

ACTSHA001::Image& ACTSHA001::Image::operator!() {
    im = Image(*this);
    iterator newit = im.begin();
    for(auto it = begin(); it!= End();++it){
        *newit = (unsigned char)(255-*it);
        ++newit;
    }

    return im;
}

ACTSHA001::Image& ACTSHA001::Image::operator/(const ACTSHA001::Image &rhs) {

    im = Image(*this);

    if(checkCompatible(*this,rhs)){

        iterator rhit = rhs.begin();
        iterator resit = im.begin();
        for(auto it = begin(); it!= End();++it){
            if(*rhit == 255){
                *resit = (unsigned char)*it;
            }else{
                *resit = (unsigned char)0;
            }
            ++rhit;
            ++resit;
        }
    }

    return im;
}

ACTSHA001::Image& ACTSHA001::Image::operator*(const int &f) {
    im = Image(*this);


        iterator resit = im.begin();
        for(auto it = begin(); it!= End();++it){
            if(*it > f){
                *resit = (unsigned char)255;
            }else{
                *resit = (unsigned char)0;
            }
            ++resit;
        }
    return im;
}

unsigned char ACTSHA001::Image::clamp(const int &i) const{
    return (unsigned char)min(255,max(0,i));
}

 bool  ACTSHA001::Image::checkCompatible  (const ACTSHA001::Image &lhs, const ACTSHA001::Image &rhs) const {
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

    //int count=0;
    for(auto it = begin(); it!= End();++it){
        //out.put(*it);
        *it = (unsigned char)file.get();
        //count++;
    }


    //cout<<"read "<<count<<" chars to image"<<endl;

    file.close();
    cout<<"loaded image"<<endl;

}

void ACTSHA001::Image::saveImage(std::string fileName) {
    ofstream out("images/"+fileName, ios::binary);
    if(height==0||width==0){
        cout<<"no image loaded to this object"<<endl;
        return;
    }

    out<<"P5"<<endl;
    out<<"#"<<endl;
    out<<(to_string(height) + " " + to_string(width))<<endl;
    out<<"255"<<endl;



    //int count=0;
    for(auto it = begin(); it!= End();++it){
        out.put(*it);
        //count++;
    }
    //cout<<"wrote "<<count<<" chars to image"<<endl;

    cout<<"saved image"<<endl;

    out.close();
}


ACTSHA001::Image& ACTSHA001::Image::operator=(const ACTSHA001::Image & rhs) {
    cout<<"copy assign called"<<endl;
    height = rhs.height;
    width = rhs.width;
    data = unique_ptr<unsigned char[]>(new unsigned char[rhs.width*rhs.height]);
    cout<<"dimensions copied"<<endl;
    //data = move(rhs.data);
    iterator newit = begin();
    cout<<"created newit"<<endl;

    for(auto it = rhs.begin(); it!= rhs.End();++it){
        *newit = *it;
        ++newit;
    }
    cout<<"finished copy assign"<<endl;
    return *this;
}


ACTSHA001::Image::Image(const ACTSHA001::Image &rhs):width(rhs.width), height(rhs.height) {
    data = unique_ptr<unsigned char[]>(new unsigned char[rhs.width*rhs.height]);
    iterator newit = begin();
    //cout<<"created newit"<<endl;
    for(auto it = rhs.begin(); it!= rhs.End();++it){
        *newit = *it;
        ++newit;
    }
}

ACTSHA001::Image::iterator& ACTSHA001::Image::iterator::operator++() {
    ptr+= sizeof(unsigned char);
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
