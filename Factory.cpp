#include "Factory.h"

Factory::Factory() {
    std::cout << "Run constructor Factory" << std::endl;
    std::cout << std::endl;
}

Factory::~Factory() {
    std::cout << "Run destructor Factory" << std::endl;
    std::cout << std::endl;
}

bool Factory::numbersInStr(std::string str) {
    int i = 0;
    int found = 0;
    while (str[i]) {
        if (str[i] >= '0' && str[i] <= '9') {
            found++;
            return true;
        }
        i++;
    }
    if (found == 0) {
        return false;
    }
}

bool Factory::charInNumbers(std::string str) {
    return str.find_first_not_of("0123456789") == std::string::npos;
}
