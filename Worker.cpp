#include "Worker.h"

Worker::Worker() {
    _fullName = "";
    _position = "";
    _income = "";
    _address = "";
    _phone = "";
    std::cout << "Run constructor Worker" << std::endl;
}

Worker::Worker(std::string fullName, std::string position, std::string income, std::string address, std::string phone) {
    _fullName = fullName;
    _position = position;
    _income = income;
    _address = address;
    _phone = phone;
    std::cout << "Run constructor Worker(props)" << std::endl;
}

Worker::Worker(Worker &obj) {
    _fullName = obj._fullName;
    _position = obj._position;
    _income = obj._income;
    _address = obj._address;
    _phone = obj._phone;
    std::cout << "Run constructor-copy Worker" << std::endl;
}

Worker::~Worker() {
    _fullName = "";
    _position = "";
    _income = "";
    _address = "";
    _phone = "";
    std::cout << "Run destructor Worker" << std::endl;
}

void Worker::setFullName(std::string fullName) {
    _fullName = fullName;
}

void Worker::setPosition(std::string position) {
    _position = position;
}

void Worker::setIncome(std::string income) {
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

std::string Worker::getIncome() {
    return _income;
}

std::string Worker::getAddress() {
    return _address;
}

std::string Worker::getPhone() {
    return _phone;
}

void Worker::editInfoObject(int id, std::string value) {
    switch (id) {
        case 1:
            _fullName = value;
            break;
        case 2:
            _position = value;
            break;
        case 3:
            _income = value;
            break;
        case 4:
            _address = value;
            break;
        case 5:
            _phone = value;
            break;
        default:
            std::cout << "Error, not found value" << std::endl;
            break;
    }
}

void Worker::setInfoObject() {
    std::cout << "Input full name worker: " << std::endl;
    getline(std::cin, _fullName);
    std::cout << "Input position worker: " << std::endl;
    getline(std::cin, _position);
    std::cout << "Input income worker: " << std::endl;
    std::getline(std::cin, _income);
    std::cout << "Input address worker: " << std::endl;
    std::getline(std::cin, _address);
    std::cout << "Input phone worker: " << std::endl;
    std::getline(std::cin, _phone);
}

void Worker::setInfoObject(std::string fullName, std::string position, std::string income, std::string address, std::string phone) {
    _fullName = fullName;
    _position = position;
    _income = income;
    _address = address;
    _phone = phone;
}

void Worker::showInfoObject() {
    std::cout << "Worker name: " << _fullName << std::endl;
    std::cout << "Worker position: " << _position << std::endl;
    std::cout << "Worker income: " << _income << std::endl;
    std::cout << "Worker address: " << _address << std::endl;
    std::cout << "Worker phone: " << _phone << std::endl;
    std::cout << std::endl;
}

void Worker::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("worker.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            throw "Error open file";
        }
        else {
            fileOut << 1 << std::endl << _fullName << std::endl << _position << std::endl << _income << std::endl << _address << std::endl << _phone << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cerr << "Error: " << exception << '\n';
    }
}