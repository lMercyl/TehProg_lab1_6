#include "Car.h"

Car::Car() {
    _mark = "";
    _model = "";
    _number = "";
}

Car::Car(std::string mark, std::string model, std::string number) {
    _mark = mark;
    _model = model;
    _number = number;
}

Car::Car(Car &obj) {
    _mark = obj.getMark();
    _model = obj.getModel();
    _number = obj.getNumber();
}

Car::~Car() {
    _mark = "";
    _model = "";
    _number = "";
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