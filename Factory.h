#ifndef UNTITLED_FACTORY_H
#define UNTITLED_FACTORY_H

#include <fstream>
#include <string>
#include <iostream>

class Factory
{
public:
    Factory();
    virtual ~Factory();
    virtual void setInfoObject() = 0;
    virtual void editInfoObject(int id, std::string value) = 0;
    virtual void showInfoObject() = 0;
    virtual void saveInfoObject() = 0;

};


#endif //UNTITLED_FACTORY_H
