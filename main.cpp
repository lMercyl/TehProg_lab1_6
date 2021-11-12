#include <iostream>
#include "Keeper.h"
#include "Factory.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"

int main() {
    int variant;
    int _variant;
    int id;
    int _id;
    std::string value;
    Keeper keep;
    Factory* factory;
    do {
        std::cout << "Main menu" << std::endl;
        std::cout << "1 Add in factory" << std::endl;
        std::cout << "2 Edit in factory" << std::endl;
        std::cout << "3 Delete from factory" << std::endl;
        std::cout << "4 Show all list" << std::endl;
        std::cout << "5 Save list in file" << std::endl;
        std::cout << "6 Load list from file" << std::endl;
        std::cout << "0 Exit" << std::endl;
        std::cout << "Variant: ";
        std::cin >> variant;
        std::cin.ignore(32767, '\n');
        std::cout << std::endl;
        switch (variant) {
            case 1:
                std::cout << "What add?" << std::endl;
                std::cout << "1 Furniture" << std::endl;
                std::cout << "2 Car" << std::endl;
                std::cout << "3 Worker" << std::endl;
                std::cout << "Variant: ";
                std::cin >> _variant;
                std::cout << std::endl;
                switch (_variant) {
                    case 1:
                        Furniture* furniture;
                        furniture = new Furniture();
                        factory = furniture;
                        furniture->setInfoObject();
                        keep.pushObject(factory);
                        break;
                    case 2:
                        Car* car;
                        car = new Car();
                        factory = car;
                        car->setInfoObject();
                        keep.pushObject(factory);
                        break;
                    case 3:
                        Worker* work;
                        work = new Worker();
                        factory = work;
                        work->setInfoObject();
                        keep.pushObject(factory);
                        break;
                    default:
                        std::cout << "Error input" << std::endl;
                        std::cout << std::endl;
                        break;
                }
                break;
            case 2:
                std::cout << "Item? All items - " << keep.getSize() - 1  << " index item start 0" << std::endl;
                std::cin >> id;
                std::cin.ignore(32767, '\n');
                keep[id]->showInfoObject();
                std::cout << std::endl;
                std::cout << "What edit? " << std::endl;
                std::cin >> _id;
                std::cout << std::endl;
                keep[id]->editInfoObject(_id);
                std::cout << std::endl;
                break;
            case 3:
                std::cout << "Item? All items - " << keep.getSize() - 1 << " index item start 0" << std::endl;
                std::cin >> id;
                std::cin.ignore(32767, '\n');
                keep.popObject(id);
                std::cout << std::endl;
                break;
            case 4:
                for (int i = 0; i < keep.getSize(); i++) {
                    keep[i]->showInfoObject();
                }
                break;
            case 5:
                keep.saveObject();
                break;
            case 6:
                keep.loadObject();
                break;
            case 0:
                break;
            default:
                std::cout << "Error input" << std::endl;
                std::cout << std::endl;
                break;
        }
    } while (variant != 0);
}
