#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <fstream>
#include <string>
#include <iostream>
#include <regex>

class Factory {
protected:
    bool numbersInStr(std::string str);
    bool charInNumbers(std::string str);
public:
    Factory();
    virtual ~Factory();
    virtual void setInfoObject() = 0;
    virtual void editInfoObject(int id) = 0;
    virtual void showInfoObject() = 0;
    virtual void saveInfoObject() = 0;
};

#endif //UNTITLED_FACTORY_H
