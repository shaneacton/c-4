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
        std::unique_ptr<unsigned char[]> data;

        int width;
        int height;

        bool  checkCompatible (const Image & lhs , const Image & rhs ) const;
        unsigned char clamp(const int & i) const;



    public:


        void loadImage(std::string file);
        void saveImage(std::string file);

        Image & operator+(const Image & rhs ) const;
        Image & operator-(const Image & rhs );
        Image & operator!();
        Image & operator/(const Image & rhs );
        Image & operator*(const int & f);
        Image &  operator = ( const Image & );
        Image (const Image &obj);
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

         iterator begin(void) const { return iterator(&data.get()[0]);}
         iterator End(void) const { return iterator(&data.get()[width*height]);}//capital because c++

    };
}
#endif //IMAGEMANIPULATION_IMAGE_H
