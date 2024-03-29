#include "Car.h"

Car::Car() {
    _mark = "mark not found";
    _model = "model not found";
    _number = "number not found";
    std::cout << "Run constructor Car" << std::endl;
    std::cout << std::endl;
}

Car::Car(std::string mark, std::string model, std::string number) {
    _mark = mark;
    _model = model;
    _number = number;
    std::cout << "Run constructor Car(props)" << std::endl;
    std::cout << std::endl;
}

Car::Car(Car &obj) {
    _mark = obj._mark;
    _model = obj._model;
    _number = obj._number;
    std::cout << "Run constructor-copy Car" << std::endl;
    std::cout << std::endl;
}

Car::~Car() {
    _mark = "";
    _model = "";
    _number = "";
    std::cout << "Run destructor Car" << std::endl;
    std::cout << std::endl;
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

void Car::editInfoObject(int id) {
    std::string str;
    std::cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            std::cout << "Input new mark car: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _mark = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 2:
            std::cout << "Input new model car: ";
            std::getline(std::cin, str);
            _model = str;
            break;
        case 3:
            std::cout << "Input new number car: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _number = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        default:
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Error, not found value" << std::endl;
            std::cout << std::endl;
            break;
    }
}

void Car::setInfoObject() {
    std::string str;
    std::cin.ignore(32767, '\n');
    std::cout << "Input mark car: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _mark = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input model car: ";
    std::getline(std::cin, str);
    _model = str;
    std::cout << "Input number car: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _number = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << std::endl;
}

void Car::showInfoObject() {
    std::cout << "1. Car mark: " << _mark << std::endl;
    std::cout << "2. Car model: " << _model << std::endl;
    std::cout << "3. Car number: " << _number << std::endl;
    std::cout << std::endl;
}

void Car::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("factory.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            fileOut << "CAR" << std::endl << "mark:"  << _mark << std::endl << "model:" << _model << std::endl
                    << "number:" << _number << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
        std::cout << std::endl;
    }
}

int Car::getIncomeObject() {
    return 0;
}

int Car::getPriceObject() {
    return 0;
}
