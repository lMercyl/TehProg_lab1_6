#ifndef UNTITLED_FURNITURE_H
#define UNTITLED_FURNITURE_H

#include "Factory.h"
#include "Dimensions.h"
#include <string>

class Furniture : public Factory {
private:
    std::string _type;
    Dimensions _dimensions;
    std::string _color;
    std::string _material;
    int _price;
public:
    Furniture();
    Furniture(std::string type, Dimensions& dimensions, std::string color, std::string material, int price);
    Furniture(Furniture& obj);
    ~Furniture();
    void setType(std::string type);
    void setDimensions(Dimensions& dimensions);
    void setColor(std::string color);
    void setMaterial(std::string material);
    void setPrice(int price);
    std::string getType();
    Dimensions& getDimensions();
    std::string getColor();
    std::string getMaterial();
    int getPrice();
};

#endif //UNTITLED_FURNITURE_H
