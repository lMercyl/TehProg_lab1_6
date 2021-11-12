#ifndef UNTITLED_FURNITURE_H
#define UNTITLED_FURNITURE_H

#include "Factory.h"

class Furniture : public Factory {
private:
    std::string _type;
    std::string _color;
    std::string _material;
    std::string _price;
    std::string _width;
    std::string _height;
    std::string _depth;
public:
    Furniture();
    Furniture(std::string type, std::string color, std::string material, std::string price, std::string width, std::string height, std::string depth);
    Furniture(Furniture& obj);
    ~Furniture() override;

    void setType(std::string type);
    void setColor(std::string color);
    void setMaterial(std::string material);
    void setPrice(std::string price);
    void setWidth(std::string width);
    void setHeight(std::string height);
    void setDepth(std::string depth);

    std::string getType();
    std::string getColor();
    std::string getMaterial();
    std::string getPrice();
    std::string getWidth();
    std::string getHeight();
    std::string getDepth();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
    int getPriceObject() override;
    int getIncomeObject() override;
};

#endif //UNTITLED_FURNITURE_H
