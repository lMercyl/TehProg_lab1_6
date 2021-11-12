#include "Keeper.h"

Keeper::Keeper() {
    head = nullptr;
    _size = 0;
    _sizeObjectFurniture = 0;
    _sizeObjectCar = 0;
    _sizeObjectWorker = 0;
    std::cout << "Run constructor Keeper" << std::endl;
    std::cout << std::endl;
}

Keeper::Keeper(int size) {
    head = nullptr;
    _size = size;
    _sizeObjectFurniture = 0;
    _sizeObjectCar = 0;
    _sizeObjectWorker = 0;
    std::cout << "Run constructor Keeper(props)" << std::endl;
    std::cout << std::endl;
}

Keeper::~Keeper() {
    if (head != nullptr) {
        Item* buffer;
        while (head->nextItem != nullptr) {
            buffer = head;
            head = head->nextItem;
            buffer->data->~Factory();
            delete(buffer);
        }
        head->data->~Factory();
        delete(head);
    }
    std::cout << "Run destructor Keeper" << std::endl;
    std::cout << std::endl;
}

int Keeper::getSize() {
    return _size;
}

int Keeper::getSizeObjectFurniture() {
    return _sizeObjectFurniture;
}

int Keeper::getSizeObjectCar() {
    return _sizeObjectCar;
}

int Keeper::getSizeObjectWorker() {
    return _sizeObjectWorker;
}

void Keeper::pushObject(Factory *obj) {
    Item* newItemObj;
    newItemObj = new Item;
    if (_size == 0) {
        newItemObj->data = obj;
        _size++;
        newItemObj->nextItem = 0;
        head = newItemObj;
    }
    else {
        Item *buf = head;
        while (buf->nextItem != nullptr) {
            buf = buf->nextItem;
        }
        newItemObj->data = obj;
        newItemObj->nextItem = 0;
        buf->nextItem = newItemObj;
        _size++;
    }
}

void Keeper::saveObject() {
    std::ofstream fileOut;
    fileOut.open("factory.txt", std::ios_base::out);
    try {
        if (!fileOut.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            fileOut << "Size: " << _size << std::endl;
            fileOut.close();
        }
        Item* buf = head;
        for (int i = 0; i < _size; i++) {
            buf->data->saveInfoObject();
            buf = buf->nextItem;
        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
    }
}

void Keeper::loadObject() {
    if (head != nullptr) {
        Item* buffer;
        while (head->nextItem != nullptr) {
            buffer = head;
            head = head->nextItem;
            buffer->data->~Factory();
            delete(buffer);
        }
        head->data->~Factory();
        delete(head);
        _size = 0;
    }
    std::ifstream fileIn;
    int typeData;
    int sizeFile;
    Factory *factory;
    fileIn.open("factory.txt");
    try {
        if (!fileIn.is_open()) {
            std::cout << std::endl;
            throw "Error open file";
        }
        else {
            fileIn >> sizeFile;
            for (int i = 0; i < sizeFile; i++) {
                fileIn >> typeData;
                fileIn.ignore(32767, '\n');
                if (typeData == 1) {
                    std::string mark;
                    std::string model;
                    std::string number;
                    getline(fileIn, mark);
                    getline(fileIn, model);
                    getline(fileIn, number);
                    Car* car;
                    car = new Car(mark, model, number);
                    factory = car;
                    pushObject(factory);
                }
                if (typeData == 2) {
                    std::string fullName;
                    std::string position;
                    std::string income;
                    std::string address;
                    std::string phone;
                    getline(fileIn, fullName);
                    getline(fileIn, position);
                    getline(fileIn, income);
                    getline(fileIn, address);
                    getline(fileIn, phone);
                    Worker* work;
                    work = new Worker(fullName, position, income, address, phone);
                    factory = work;
                    pushObject(factory);
                }
                if (typeData == 3) {
                    std::string type;
                    std::string color;
                    std::string material;
                    std::string price;
                    std::string width;
                    std::string height;
                    std::string depth;
                    getline(fileIn, type);
                    getline(fileIn, color);
                    getline(fileIn, material);
                    getline(fileIn, price);
                    getline(fileIn, width);
                    getline(fileIn, height);
                    getline(fileIn, depth);
                    Furniture* furniture;
                    furniture = new Furniture(type, color, material, price, width, height, depth);
                    factory = furniture;
                    pushObject(factory);
                }

            }

        }
    }
    catch (const char* exception) {
        std::cout << std::endl;
        std::cerr << "Error: " << exception << '\n';
    }
}

void Keeper::popObject(int index) {
    Item* buf = head;
    Item* bufOne;
    if (_size == 0) {
        std::cout << "Is empty" << std::endl;
        return;
    }
    if (((index) >= _size) || (index < 0)) {
        std::cout << "Not found index" << std::endl;
    }

    else {
        if (buf->nextItem == nullptr) {
            std::cout << "Delete last object and one in all"<< std::endl;
            buf->data->~Factory();
            _size--;
            return;
        }
        if (index == 0) {
            head = buf->nextItem;
            buf->data->~Factory();
            _size--;
            return;
        }
        for (int i = 0; i < index - 1; i++) {
            buf = buf->nextItem;
        }
        bufOne = buf->nextItem;
        buf->nextItem = bufOne->nextItem;
        bufOne->data->~Factory();
        _size--;
    }
}

Factory* Keeper::operator[] (const int index) {
    Item* buf = head;
    if (((index) >= _size) || (index < 0)) {
        std::cout << "Error" << std::endl;
    }
    else {
        for (int i = 0; i < index; i++) {
            buf = buf->nextItem;
        }
    }
    return (buf->data);
}

