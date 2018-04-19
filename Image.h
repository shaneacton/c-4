//
// Created by actsha001 on 2018/04/17.
//

#ifndef IMAGEMANIPULATION_IMAGE_H
#define IMAGEMANIPULATION_IMAGE_H

#include <string>
#include <vector>
#include <memory>


namespace ACTSHA001 {
    class Image{

    private:
        //unsigned char** image;
        std::vector<unsigned char*> image;
        std::unique_ptr<unsigned char[]> data;

        int width;
        int height;

        bool checkCompatible(const Image & lhs , const Image & rhs );
        unsigned char clamp(const int & i);



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

        class iterator
        {
        private:
            friend class Image;
            unsigned char *ptr;
// construct only via Image class (begin/end)
            iterator(unsigned char *p) : ptr(p) {}
        public://copy construct is public
            iterator( const iterator & rhs) : ptr(rhs.ptr) {}
// define overloaded ops: *, ++, --, =
            iterator & operator=(const iterator & rhs);
            bool operator!=(const iterator & rhs);

            iterator & operator++();
            unsigned char  & operator*();
            iterator & operator--();


// other methods for iterator
        };

        iterator begin(void) { return iterator(data.get());}
        iterator end(void) { return iterator(&data.get()[width*height]);}

    };
}
#endif //IMAGEMANIPULATION_IMAGE_H
