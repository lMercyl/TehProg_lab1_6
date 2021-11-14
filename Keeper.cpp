#include "Keeper.h"

Keeper::Keeper() {
    head = nullptr;
    _size = 0;
    std::cout << "Run constructor Keeper" << std::endl;
    std::cout << std::endl;
}

Keeper::Keeper(int size) {
    head = nullptr;
    _size = size;
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
    std::string item;
    bool work = false;
    bool found = false;
    int counterObject = 0;
    Factory *factory;
    fileIn.open("factory.txt");
    if (!fileIn.is_open()) {
        std::cout << std::endl;
        std::cout << "Error open file" << std::endl;
    } else {
        if (fileIn.peek() == EOF) {
            std::cout << "File is empty" << std::endl;
        } else {
            while (!fileIn.eof()) {
                if (item == "CAR" || item == "WORKER" || item == "FURNITURE") {
                    work = true;
                } else {
                    std::getline(fileIn, item);
                }
                if (item == "CAR" || item == "WORKER" || item == "FURNITURE") {
                    found = true;
                    if (item == "CAR") {
                        std::string mark = "mark not found";
                        std::string model = "model not found";
                        std::string number = "number not found";
                        do {
                            std::getline(fileIn, item);
                            if (item[0] == 'm' && item[1] == 'a' && item[2] == 'r' && item[3] == 'k' &&
                                item[4] == ':') {
                                item = item.substr(5);
                                if (!factory->numbersInStr(item)) {
                                    if (item == "") {
                                        mark = "mark is empty";
                                    } else {
                                        mark = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is number. Value is default"
                                              << std::endl;
                                }
                            }
                            if (item[0] == 'm' && item[1] == 'o' && item[2] == 'd' && item[3] == 'e'
                                && item[4] == 'l' && item[5] == ':') {
                                item = item.substr(6);
                                if (item == "") {
                                    model = "model is empty";
                                } else {
                                    model = item;
                                }
                            }
                            if (item[0] == 'n' && item[1] == 'u' && item[2] == 'm' && item[3] == 'b'
                                && item[4] == 'e' && item[5] == 'r' && item[6] == ':') {
                                item = item.substr(7);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        number = "number is empty";
                                    } else {
                                        number = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default"
                                              << std::endl;
                                }
                            }
                            if (item == "CAR" || item == "WORKER" || item == "FURNITURE" || fileIn.eof()) {
                                Car* car;
                                car = new Car(mark, model, number);
                                factory = car;
                                pushObject(factory);
                                counterObject++;
                                break;
                            }
                        } while (true);
                    }
                    if (item == "WORKER") {
                        std::string fullName = "full name not found";
                        std::string position = "position not found";
                        std::string income = "0";
                        std::string address = "address not found";
                        std::string phone = "phone not found";
                        do {
                            std::getline(fileIn, item);
                            if (item[0] == 'f' && item[1] == 'u' && item[2] == 'l' && item[3] == 'l' && item[4] == 'N'
                                && item[5] == 'a' && item[6] == 'm' && item[7] == 'e' && item[8] == ':') {
                                item = item.substr(9);
                                if (!factory->numbersInStr(item)) {
                                    if (item == "") {
                                        fullName = "full name is empty";
                                    } else {
                                        fullName = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is number. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'p' && item[1] == 'o' && item[2] == 's' && item[3] == 'i'
                                && item[4] == 't' && item[5] == 'i' && item[6] == 'o' && item[7] == 'n' && item[8] == ':') {
                                item = item.substr(9);
                                if (!factory->numbersInStr(item)) {
                                    if (item == "") {
                                        position = "position is empty";
                                    } else {
                                        position = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is number. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'i' && item[1] == 'n' && item[2] == 'c' && item[3] == 'o'
                                && item[4] == 'm' && item[5] == 'e' && item[6] == ':') {
                                item = item.substr(7);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        income = "income is empty";
                                    } else {
                                        income = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'a' && item[1] == 'd' && item[2] == 'd' && item[3] == 'r'
                                && item[4] == 'e' && item[5] == 's' && item[6] == 's' && item[7] == ':') {
                                item = item.substr(8);
                                if (item == "") {
                                    address = "address is empty";
                                } else {
                                    address = item;
                                }
                            }
                            if (item[0] == 'p' && item[1] == 'h' && item[2] == 'o' && item[3] == 'n'
                                && item[4] == 'e' && item[5] == ':') {
                                item = item.substr(6);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        phone = "phone is empty";
                                    } else {
                                        phone = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item == "CAR" || item == "WORKER" || item == "FURNITURE" || fileIn.eof()) {
                                Worker* worker;
                                worker = new Worker(fullName, position, income, address, phone);
                                factory = worker;
                                pushObject(factory);
                                counterObject++;
                                break;
                            }
                        } while (true);
                    }
                    if (item == "FURNITURE") {
                        std::string type = "type not found";
                        std::string color = "color not found";
                        std::string material = "material not found";
                        std::string price = "0";
                        std::string width = "width not found";
                        std::string height = "height not found";
                        std::string depth = "depth not found";
                        do {
                            std::getline(fileIn, item);
                            if (item[0] == 't' && item[1] == 'y' && item[2] == 'p' && item[3] == 'e' && item[4] == ':') {
                                item = item.substr(5);
                                if (!factory->numbersInStr(item)) {
                                    if (item == "") {
                                        type = "type name is empty";
                                    } else {
                                        type = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is number. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'c' && item[1] == 'o' && item[2] == 'l' && item[3] == 'o'
                                && item[4] == 'r' && item[5] == ':') {
                                item = item.substr(6);
                                if (!factory->numbersInStr(item)) {
                                    if (item == "") {
                                        color = "color is empty";
                                    } else {
                                        color = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is number. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'm' && item[1] == 'a' && item[2] == 't' && item[3] == 'e'
                                && item[4] == 'r' && item[5] == 'i' && item[6] == 'a' && item[7] == 'l' && item[8] == ':') {
                                item = item.substr(9);
                                if (item == "") {
                                    material = "material is empty";
                                } else {
                                    material = item;
                                }
                            }
                            if (item[0] == 'p' && item[1] == 'r' && item[2] == 'i' && item[3] == 'c'
                                && item[4] == 'e' && item[5] == ':') {
                                item = item.substr(6);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        price = "price is empty";
                                    } else {
                                        price = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'w' && item[1] == 'i' && item[2] == 'd' && item[3] == 't'
                                && item[4] == 'h' && item[5] == ':') {
                                item = item.substr(6);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        width = "width is empty";
                                    } else {
                                        width = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'h' && item[1] == 'e' && item[2] == 'i' && item[3] == 'g'
                                && item[4] == 'h' && item[5] == 't' && item[6] == ':') {
                                item = item.substr(7);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        height = "height is empty";
                                    } else {
                                        height = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item[0] == 'd' && item[1] == 'e' && item[2] == 'p' && item[3] == 't'
                                && item[4] == 'h' && item[5] == ':') {
                                item = item.substr(6);
                                if (factory->charInNumbers(item)) {
                                    if (item == "") {
                                        depth = "depth is empty";
                                    } else {
                                        depth = item;
                                    }
                                } else {
                                    std::cout << "You input string-line when is char. Value is default" << std::endl;
                                }
                            }
                            if (item == "CAR" || item == "WORKER" || item == "FURNITURE" || fileIn.eof()) {
                                Furniture* furniture;
                                furniture = new Furniture(type, color, material, price, width, height, depth);
                                factory = furniture;
                                pushObject(factory);
                                counterObject++;
                                break;
                            }
                        } while (true);
                    }
                }
            }
        }
    }
    if (fileIn.eof() && (item == "CAR" || item == "WORKER" || item == "FURNITURE")) {
        std::cout << "It is impossible to create an object at the end of the file without defining parameters." << std::endl;
        std::cout << "Fill in the file normally" << std::endl;
        std::cout << std::endl;
    }
    if (!found) {
        std::cout << "Impossible to define" << std::endl;
        std::cout << std::endl;
    }
    fileIn.close();
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
    } else {
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
    } else {
        for (int i = 0; i < index; i++) {
            buf = buf->nextItem;
        }
    }
    return (buf->data);
}

