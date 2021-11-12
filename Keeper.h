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
public:
    Keeper();
    explicit Keeper(int size);
    ~Keeper();

    void saveObject();
    void pushObject(Factory* obj);
    void popObject(int index);
    void loadObject();
    int getSize();

    Factory* operator[] (int index);
};

#endif //UNTITLED2_KEEPER_H
