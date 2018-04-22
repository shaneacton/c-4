The program is run by the given format: imageops <option> OutputImageName
please run it from the same folder as this readme is located.
place any and all additional images used for marking in the images folder, all newly generated images will also be stored here

included in the sumission are:
imageops.cpp the driver file for this project
Image.cpp/Image.h, the wrapper class used to store loaded image data as well as perform the required operations. contained as a subclass is the iterator class
Makefile for easy project compilation

Bellow are sample commands which can be run to test the various functions of the project

./imageops -a Lenna_standard Lenna_hat_mask testadd
./imageops -s Lenna_standard Lenna_hat_mask testsubtract
./imageops -l Lenna_standard Lenna_hat_mask testmask
./imageops -i Lenna_standard testinverse
./imageops -t Lenna_standard 120 testthreshhold
