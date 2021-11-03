#include "Furniture.h"

Furniture::Furniture() {
    _type = "";
    _dimensions = Dimensions();
    _color = "";
    _material = "";
    _price = 0;
}

Furniture::Furniture(std::string type, Dimensions &dimensions, std::string color, std::string material, int price) {
    _type = type;
    _dimensions = Dimensions(dimensions);
    _color = color;
    _material = material;
    _price = price;
}

Furniture::Furniture(Furniture &obj) {
    _type = obj.getType();
    _dimensions = obj.getDimensions();
    _color = obj.getColor();
    _material = obj.getMaterial();
    _price = obj.getPrice();
}

Furniture::~Furniture() {
    _type = "";
    _dimensions = Dimensions();
    _color = "";
    _material = "";
    _price = 0;
}

void Furniture::setType(std::string type) {
    _type = type;
}

void Furniture::setDimensions(Dimensions &dimensions) {
    _dimensions = Dimensions(dimensions);
}

void Furniture::setColor(std::string color) {
    _color = color;
}

void Furniture::setMaterial(std::string material) {
    _material = material;
}

void Furniture::setPrice(int price) {
    _price = price;
}

std::string Furniture::getType() {
    return _type;
}

Dimensions &Furniture::getDimensions() {
    return _dimensions;
}

std::string Furniture::getColor() {
    return _color;
}

std::string Furniture::getMaterial() {
    return _material;
}

int Furniture::getPrice() {
    return _price;
}