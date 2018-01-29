#ifndef IMAGESIZE_H_INCLUDED
#define IMAGESIZE_H_INCLUDED
class ImageSize{
    private :
        unsigned imageWidth;
        unsigned imageHeight;

    public :
        void setImageWidth(unsigned w);
        void setImageHeight(unsigned h);

        unsigned getImageWidth();
        unsigned getImageHeight();
        ImageSize();

};


#endif // IMAGESIZE_H_INCLUDED
