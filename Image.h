//
// Created by actsha001 on 2018/04/17.
//

#ifndef IMAGEMANIPULATION_IMAGE_H
#define IMAGEMANIPULATION_IMAGE_H

#include <string>

namespace ACTSHA001 {
    class Image{

    private:
        unsigned char** image;

        void loadImage(std::string file);
        void saveImage(std::string file);




    public:
        Image & operator+(const Image & rhs);
        Image & operator-(const Image & rhs );
        Image & operator!(const Image & rhs );
        Image & operator/(const Image & rhs );
        Image & operator*(const int & f);
        Image & operator<<();
        Image & operator>>();


        Image();//default constructor
        Image(int width, int height);

    };
}
#endif //IMAGEMANIPULATION_IMAGE_H
