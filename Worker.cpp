#include "Worker.h"

Worker::Worker() {
    _fullName = "";
    _position = "";
    _income = 0;
    _address = "";
    _phone = "";
}

Worker::Worker(std::string fullName, std::string position, int income, std::string address, std::string phone) {
    _fullName = fullName;
    _position = position;
    _income = income;
    _address = address;
    _phone = phone;
}

Worker::Worker(Worker &obj) {
    _fullName = obj.getFullName();
    _position = obj.getPosition();
    _income = obj.getIncome();
    _address = obj.getAddress();
    _phone = obj.getPhone();
}

Worker::~Worker() {
    _fullName = "";
    _position = "";
    _income = 0;
    _address = "";
    _phone = "";
}

void Worker::setFullName(std::string fullName) {
    _fullName = fullName;
}

void Worker::setPosition(std::string position) {
    _position = position;
}

void Worker::setIncome(int income) {
    _income = income;
}

void Worker::setAddress(std::string address) {
    _address = address;
}

void Worker::setPhone(std::string phone) {
    _phone = phone;
}

std::string Worker::getFullName() {
    return _fullName;
}

std::string Worker::getPosition() {
    return _position;
}

int Worker::getIncome() {
    return _income;
}

std::string Worker::getAddress() {
    return _address;
}

std::string Worker::getPhone() {
    return _phone;
}