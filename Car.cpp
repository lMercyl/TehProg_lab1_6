#include "Car.h"

Car::Car() {
    _mark = "";
    _model = "";
    _number = "";
    std::cout << "Run constructor Car" << std::endl;
}

Car::Car(std::string mark, std::string model, std::string number) {
    _mark = mark;
    _model = model;
    _number = number;
    std::cout << "Run constructor Car(props)" << std::endl;
}

Car::Car(Car &obj) {
    _mark = obj._mark;
    _model = obj._model;
    _number = obj._number;
    std::cout << "Run constructor-copy Car" << std::endl;
}

Car::~Car() {
    _mark = "";
    _model = "";
    _number = "";
    std::cout << "Run destructor Car" << std::endl;
}

void Car::setMark(std::string mark) {
    _mark = mark;
}

void Car::setModel(std::string model) {
    _model = model;
}

void Car::setNumber(std::string number) {
    _number = number;
}

std::string Car::getMark() {
    return _mark;
}

std::string Car::getModel() {
    return _model;
}

std::string Car::getNumber() {
    return _number;
}

void Car::editInfoObject(int id, std::string value) {
    switch (id) {
        case 1:
            _mark = value;
            break;
        case 2:
            _model = value;
            break;
        case 3:
            _number = value;
            break;
        default:
            std::cout << "Error, not found value" << std::endl;
            break;
    }
}

void Car::setInfoObject() {
    std::cout << "Input mark car: " << std::endl;
    getline(std::cin, _mark);
    std::cout << "Input model car: " << std::endl;
    std::getline(std::cin, _model);
    std::cout << "Input number car: " << std::endl;
    std::getline(std::cin, _number);
}

void Car::setInfoObject(std::string mark, std::string model, std::string number) {
    _mark = mark;
    _model = model;
    _number = number;
}

void Car::showInfoObject() {
    std::cout << "Car mark: " << _mark << std::endl;
    std::cout << "Car model: " << _model << std::endl;
    std::cout << "Car number: " << _number << std::endl;
    std::cout << std::endl;
}

void Car::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("fabric.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            throw "Error open file";
        }
        else {
            fileOut << 0 << std::endl << _mark << std::endl << _model << std::endl << _number << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}