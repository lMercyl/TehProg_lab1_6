#ifndef UNTITLED_DIMENSIONS_H
#define UNTITLED_DIMENSIONS_H

#include "Furniture.h"

class Dimensions : public Furniture {
public:
    int _width;
    int _height;
    int _depth;
public:
    Dimensions();
    Dimensions(int width, int height, int depth);
    Dimensions(Dimensions& obj);
    ~Dimensions();
    void setWidth(int width);
    void setHeight(int height);
    void setDepth(int depth);
    int getWidth();
    int getHeight();
    int getDepth();
};

#endif //UNTITLED_DIMENSIONS_H
