#include "ImageSize.h"

void ImageSize::setImageHeight(unsigned h){
    this->imageHeight= h;
}

void ImageSize::setImageWidth(unsigned w){
    this->imageWidth = w;
}

unsigned ImageSize::getImageHeight(){
    return this->imageHeight;
}
unsigned ImageSize::getImageWidth(){
    return this->imageWidth;
}
ImageSize::ImageSize()
{
    this->imageHeight = 0;
    this->imageWidth = 0;
}

