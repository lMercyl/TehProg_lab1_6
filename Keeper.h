#ifndef UNTITLED2_KEEPER_H
#define UNTITLED2_KEEPER_H

#include "Factory.h"
#include "Furniture.h"
#include "Car.h"
#include "Worker.h"
#include "Item.h"

class Keeper {
private:
    Item *head;
    int _size;
    int _sizeObjectFurniture;
    int _sizeObjectCar;
    int _sizeObjectWorker;
public:
    Keeper();
    Keeper(int size);
    ~Keeper();
    void saveObject();
    void pushObject(Factory* obj);
    void popObject(int index);
    void loadObject();
    int getSize();
    int getSizeObjectFurniture();
    int getSizeObjectCar();
    int getSizeObjectWorker();
    Factory* operator[] (int index);
};

#endif //UNTITLED2_KEEPER_H
