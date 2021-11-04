#ifndef UNTITLED_FURNITURE_H
#define UNTITLED_FURNITURE_H

#include "Factory.h"

class Furniture : public Factory {
private:
    std::string _type;
    std::string _color;
    std::string _material;
    int _price;
    int _width;
    int _height;
    int _depth;
public:
    Furniture();
    Furniture(std::string type, std::string color, std::string material, int price, int width, int height, int depth);
    Furniture(Furniture& obj);
    ~Furniture();
    void setType(std::string type);
    void setColor(std::string color);
    void setMaterial(std::string material);
    void setPrice(int price);
    void setWidth(int width);
    void setHeight(int height);
    void setDepth(int depth);
    std::string getType();
    std::string getColor();
    std::string getMaterial();
    int getPrice();
    int getWidth();
    int getHeight();
    int getDepth();
    void setInfoObject();
    void setInfoObject(std::string type, std::string color, std::string material, int price, int width, int height, int depth);
    void editInfoObject(int id, std::string value);
    void showInfoObject();
    void saveInfoObject();
};

#endif //UNTITLED_FURNITURE_H
