#include "Furniture.h"

Furniture::Furniture() {
    _type = "";
    _color = "";
    _material = "";
    _price = 0;
    _width = 0;
    _height = 0;
    _depth = 0;
    std::cout << "Run constructor Furniture" << std::endl;
}

Furniture::Furniture(std::string type, std::string color, std::string material, int price, int width, int height, int depth) {
    _type = type;
    _color = color;
    _material = material;
    _price = price;
    _width = width;
    _height = height;
    _depth = depth;
    std::cout << "Run constructor Furniture(props)" << std::endl;
}

Furniture::Furniture(Furniture &obj) {
    _type = obj._type;
    _color = obj._color;
    _material = obj._material;
    _price = obj._price;
    _width = obj._width;
    _height = obj._height;
    _depth = obj._depth;
    std::cout << "Run constructor-copy Furniture" << std::endl;
}

Furniture::~Furniture() {
    _type = "";
    _color = "";
    _material = "";
    _price = 0;
    _width = 0;
    _height = 0;
    _depth = 0;
}

void Furniture::setType(std::string type) {
    _type = type;
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

void Furniture::setWidth(int width) {
    _width = width;
}

void Furniture::setHeight(int height) {
    _height = height;
}

void Furniture::setDepth(int depth) {
    _depth = depth;
}

std::string Furniture::getType() {
    return _type;
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

int Furniture::getWidth() {
    return _width;
}

int Furniture::getHeight() {
    return _height;
}

int Furniture::getDepth() {
    return _depth;
}

void Furniture::editInfoObject(int id, std::string value) {
    switch (id) {
        case 1:
            _type = value;
            break;
        case 2:
            _color = value;
            break;
        case 3:
            _material = value;
            break;
        case 4:
            _price = atoi(value.c_str());
            break;
        case 5:
            _width = atoi(value.c_str());
            break;
        case 6:
            _height = atoi(value.c_str());
            break;
        case 7:
            _depth = atoi(value.c_str());
            break;
        default:
            std::cout << "Error, not found value" << std::endl;
            break;
    }
}

void Furniture::setInfoObject() {
    std::string str;
    std::cout << "Input type furniture: " << std::endl;
    getline(std::cin, _type);
    std::cout << "Input color furniture: " << std::endl;
    getline(std::cin, _color);
    std::cout << "Input material furniture: " << std::endl;
    getline(std::cin, _material);
    std::cout << "Input width furniture: " << std::endl;
    std::getline(std::cin, str);
    _width = atoi(str.c_str());
    std::cout << "Input height furniture: " << std::endl;
    std::getline(std::cin, str);
    _height = atoi(str.c_str());
    std::cout << "Input depth furniture: " << std::endl;
    std::getline(std::cin, str);
    _depth = atoi(str.c_str());
}

void Furniture::setInfoObject(std::string type, std::string color, std::string material, int price, int width, int height, int depth) {
    _type = type;
    _color = color;
    _material = material;
    _price = price;
    _width = width;
    _height = height;
    _depth = depth;
}

void Furniture::showInfoObject() {
    std::cout << "Furniture type: " << _type << std::endl;
    std::cout << "Furniture color: " << _color << std::endl;
    std::cout << "Furniture material: " << _material << std::endl;
    std::cout << "Furniture price: " << _price << std::endl;
    std::cout << "Furniture width: " << _height << std::endl;
    std::cout << "Furniture height: " << _height << std::endl;
    std::cout << "Furniture depth: " << _depth << std::endl;
    std::cout << std::endl;
}

void Furniture::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("furniture.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            throw "Error open file";
        }
        else {
            fileOut << 2 << std::endl << _type << std::endl << _color << std::endl << _material << std::endl << _price << std::endl << _width << std::endl << _height << std::endl << _depth << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}