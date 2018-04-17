//
// Created by actsha001 on 2018/04/17.
//

#ifndef IMAGEMANIPULATION_IMAGE_H
#define IMAGEMANIPULATION_IMAGE_H

#include <string>
#include <vector>


namespace ACTSHA001 {
    class Image{

    private:
        //unsigned char** image;
        std::vector<unsigned char*> image;
        int width;
        int height;

        bool checkCompatible(const Image & lhs , const Image & rhs );




    public:
        void loadImage(std::string file);
        void saveImage(std::string file);

        Image & operator+(const Image & rhs );
        Image & operator-(const Image & rhs );
        Image & operator!();
        Image & operator/(const Image & rhs );
        Image & operator*(const int & f);
        //Image & operator<<();
        //Image & operator>>();


        Image();//default constructor

    };
}
#endif //IMAGEMANIPULATION_IMAGE_H
