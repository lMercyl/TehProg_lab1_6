#include "Dimensions.h"

Dimensions::Dimensions() {
    _width = 0;
    _height = 0;
    _depth = 0;
}

Dimensions::Dimensions(int width, int height, int depth) {
    _width = width;
    _height = height;
    _depth = depth;
}

Dimensions::Dimensions(Dimensions &obj) {
    _width = obj.getWidth();
    _height = obj.getHeight();
    _depth = obj.getDepth();
}

Dimensions::~Dimensions() {
    _width = 0;
    _height = 0;
    _depth = 0;
}

void Dimensions::setWidth(int width) {
    _width = width;
}

void Dimensions::setHeight(int height) {
    _height = height;
}

void Dimensions::setDepth(int depth) {
    _depth = depth;
}

int Dimensions::getWidth() {
    return _width;
}

int Dimensions::getHeight() {
    return _height;
}

int Dimensions::getDepth() {
    return _depth;
}