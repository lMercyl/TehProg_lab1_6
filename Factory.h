#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <fstream>
#include <string>
#include <iostream>

class Factory {
public:
    Factory();
    virtual ~Factory();
    bool numbersInStr(std::string str);
    bool charInNumbers(std::string str);
    virtual void setInfoObject() = 0;
    virtual void editInfoObject(int id) = 0;
    virtual void showInfoObject() = 0;
    virtual void saveInfoObject() = 0;
    virtual int getPriceObject() = 0;
    virtual int getIncomeObject() = 0;
};

#endif //UNTITLED_FACTORY_H
