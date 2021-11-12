#include "Furniture.h"

Furniture::Furniture() {
    _type = "type not found";
    _color = "color not found";
    _material = "material not found";
    _price = "price not found";
    _width = "width not found";
    _height = "height not found";
    _depth = "depth not found";
    std::cout << "Run constructor Furniture" << std::endl;
    std::cout << std::endl;
}

Furniture::Furniture(std::string type, std::string color, std::string material, std::string price,
                     std::string width, std::string height, std::string depth) {
    _type = type;
    _color = color;
    _material = material;
    _price = price;
    _width = width;
    _height = height;
    _depth = depth;
    std::cout << "Run constructor Furniture(props)" << std::endl;
    std::cout << std::endl;
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
    std::cout << std::endl;
}

Furniture::~Furniture() {
    _type = "";
    _color = "";
    _material = "";
    _price = "";
    _width = "";
    _height = "";
    _depth = "";
    std::cout << "Run destructor Furniture" << std::endl;
    std::cout << std::endl;
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

void Furniture::setPrice(std::string price) {
    _price = price;
}

void Furniture::setWidth(std::string width) {
    _width = width;
}

void Furniture::setHeight(std::string height) {
    _height = height;
}

void Furniture::setDepth(std::string depth) {
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

std::string Furniture::getPrice() {
    return _price;
}

std::string Furniture::getWidth() {
    return _width;
}

std::string Furniture::getHeight() {
    return _height;
}

std::string Furniture::getDepth() {
    return _depth;
}

void Furniture::editInfoObject(int id) {
    std::string str;
    std::cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            std::cout << "Input new type furniture: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _type = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 2:
            std::cout << "Input new color furniture: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _color = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 3:
            std::cout << "Input new material furniture: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _material = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 4:
            std::cout << "Input new price furniture: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _price = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        case 5:
            std::cout << "Input new width furniture: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _width = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        case 6:
            std::cout << "Input new height furniture: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _height = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        case 7:
            std::cout << "Input new depth furniture: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _depth = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        default:
            std::cout << "Error, not found value" << std::endl;
            break;
    }
}

void Furniture::setInfoObject() {
    std::string str;
    std::cin.ignore(32767, '\n');
    std::cout << "Input type furniture: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _type = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input color furniture: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _color = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input material furniture: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _material = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input price furniture: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _price = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << "Input width furniture: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _width = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << "Input height furniture: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _height = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << "Input depth furniture: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _depth = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << std::endl;
}

void Furniture::showInfoObject() {
    std::cout << "1. Furniture type: " << _type << std::endl;
    std::cout << "2. Furniture color: " << _color << std::endl;
    std::cout << "3. Furniture material: " << _material << std::endl;
    std::cout << "4. Furniture price: " << _price << std::endl;
    std::cout << "5. Furniture width: " << _height << std::endl;
    std::cout << "6. Furniture height: " << _height << std::endl;
    std::cout << "7. Furniture depth: " << _depth << std::endl;
    std::cout << std::endl;
}

void Furniture::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("factory.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            fileOut << "FURNITURE" << std::endl << "type: " << _type << std::endl << "color: "  << _color << std::endl
                    << "material: " << _material << std::endl << "price: "  << _price << std::endl
                    << "width: " << _width << std::endl << "height: " << _height << std::endl
                    << "depth: " << _depth << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
    }
}