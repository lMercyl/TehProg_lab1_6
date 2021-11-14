#include "Worker.h"

Worker::Worker() {
    _fullName = "Full name not found";
    _position = "Position not found";
    _income = "0";
    _address = "Address not found";
    _phone = "Phone not found";
    std::cout << "Run constructor Worker" << std::endl;
    std::cout << std::endl;
}

Worker::Worker(std::string fullName, std::string position, std::string income, std::string address, std::string phone) {
    _fullName = fullName;
    _position = position;
    _income = income;
    _address = address;
    _phone = phone;
    std::cout << "Run constructor Worker(props)" << std::endl;
    std::cout << std::endl;
}

Worker::Worker(Worker &obj) {
    _fullName = obj._fullName;
    _position = obj._position;
    _income = obj._income;
    _address = obj._address;
    _phone = obj._phone;
    std::cout << "Run constructor-copy Worker" << std::endl;
    std::cout << std::endl;
}

Worker::~Worker() {
    _fullName = "";
    _position = "";
    _income = " ";
    _address = "";
    _phone = "";
    std::cout << "Run destructor Worker" << std::endl;
    std::cout << std::endl;
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

void Worker::editInfoObject(int id) {
    std::string str;
    std::cin.ignore(32767, '\n');
    switch (id) {
        case 1:
            std::cout << "Input new full name worker: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _fullName = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 2:
            std::cout << "Input new position worker: ";
            std::getline(std::cin, str);
            if (!numbersInStr(str)) {
                _position = str;
            } else {
                std::cout << "You input string-line when is number. Value not set" << std::endl;
            }
            break;
        case 3:
            std::cout << "Input new income worker: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _income = str;
            } else {
                std::cout << "You input string-line when is char. Value not set" << std::endl;
            }
            break;
        case 4:
            std::getline(std::cin, str);
            _address = str;
            break;
        case 5:
            std::cout << "Input new phone worker: ";
            std::getline(std::cin, str);
            if (charInNumbers(str)) {
                _phone = str;
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

void Worker::setInfoObject() {
    std::string str;
    std::cin.ignore(32767, '\n');
    std::cout << "Input full name worker: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _fullName = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input position worker: ";
    std::getline(std::cin, str);
    if (!numbersInStr(str)) {
        _position = str;
    } else {
        std::cout << "You input string-line when is number. Value is default" << std::endl;
    }
    std::cout << "Input income worker: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _income = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << "Input address worker: ";
    std::getline(std::cin, str);
    _address = str;
    std::cout << "Input phone worker: ";
    std::getline(std::cin, str);
    if (charInNumbers(str)) {
        _phone = str;
    } else {
        std::cout << "You input string-line when is char. Value is default" << std::endl;
    }
    std::cout << std::endl;
}

void Worker::showInfoObject() {
    std::cout << "1. Worker name: " << _fullName << std::endl;
    std::cout << "2. Worker position: " << _position << std::endl;
    std::cout << "3. Worker income: " << _income << std::endl;
    std::cout << "4. Worker address: " << _address << std::endl;
    std::cout << "5. Worker phone: " << _phone << std::endl;
    std::cout << std::endl;
}

void Worker::saveInfoObject() {
    std::ofstream fileOut;
    fileOut.open("factory.txt", std::ios_base::app);
    try {
        if (!fileOut.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            fileOut << "WORKER" << std::endl << "fullName:" << _fullName << std::endl
            << "position:" <<  _position << std::endl << "income:"  << _income << std::endl
            << "address:"  << _address << std::endl << "phone:"  << _phone << std::endl;
            fileOut.close();
        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
        std::cout << std::endl;
    }
}

int Worker::getIncomeObject() {
    return atoi(_income.c_str());
}

int Worker::getPriceObject() {
    return 0;
}
