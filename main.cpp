#include <iostream>
#include "Keeper.h"
#include "Factory.h"
#include "Furniture.h"
#include "Worker.h"
#include "Car.h"

int profit(Keeper& keep) {
    int outlay = 0;
    int sales = 0;
    for (int i = 0; i < keep.getSize(); i++) {
        outlay += keep[i]->getIncomeObject();
        sales += keep[i]->getPriceObject();
    }
    return sales - outlay;
}

int main() {
    int variant;
    int _variant;
    int id;
    int _id;
    bool exit = false;
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
        std::cout << "7 Profit calculation" << std::endl;
        std::cout << "0 Exit" << std::endl;
        std::cout << "Variant: ";
        if ((std::cin >> variant)) {
            switch (variant) {
                case 1:
                    std::cout << "1 Furniture" << std::endl;
                    std::cout << "2 Car" << std::endl;
                    std::cout << "3 Worker" << std::endl;
                    std::cout << "What add: ";
                    if ((std::cin >> _variant)) {
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
                                std::cout << std::endl;
                                std::cout << "Error input" << std::endl;
                                std::cout << std::endl;
                                break;
                        }
                    } else {
                        std::cin.clear();
                        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::cout << std::endl;
                        std::cout << "Error input. Try again" << std::endl;
                        std::cout << std::endl;
                    }
                    break;
                case 2:
                    if (keep.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            std::cout << "Object " << i << std::endl;
                            keep[i]->showInfoObject();
                        }
                        std::cout << "Select object: ";
                        if ((std::cin >> id)) {
                            if (id < 0 || id > (keep.getSize() - 1)) {
                                std::cout << "Error input. Try again" << std::endl;
                                std::cout << std::endl;
                            } else {
                                std::cout << std::endl;
                                std::cin.ignore(32767, '\n');
                                keep[id]->showInfoObject();
                                std::cout << "What edit: ";
                                std::cin >> _id;
                                std::cout << std::endl;
                                keep[id]->editInfoObject(_id);
                            }
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 3:
                    if (keep.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            std::cout << "Object " << i << std::endl;
                            keep[i]->showInfoObject();
                        }
                        std::cout << "Select object: ";
                        if ((std::cin >> id)) {
                            if (id < 0 || id > (keep.getSize() - 1)) {
                                std::cout << "Error input. Try again" << std::endl;
                                std::cout << std::endl;
                            } else {
                                std::cin.ignore(32767, '\n');
                                keep.popObject(id);
                                std::cout << "Object " << id << " delete" << std::endl;
                                std::cout << std::endl;
                            }
                        } else {
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            std::cout << std::endl;
                            std::cout << "Error input. Try again" << std::endl;
                            std::cout << std::endl;
                        }
                    }
                    break;
                case 4:
                    if (keep.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        std::cout << std::endl;
                        for (int i = 0; i < keep.getSize(); i++) {
                            keep[i]->showInfoObject();
                        }
                    }
                    break;
                case 5:
                    if (keep.getSize() == 0) {
                        std::cout << "Keeper is empty. Add object" << std::endl;
                        std::cout << std::endl;
                    } else {
                        keep.saveObject();
                        std::cout << "Keeper save in file" << std::endl;
                        std::cout << std::endl;
                    }
                    break;
                case 6:
                    keep.loadObject();
                    break;
                case 7:
                    std::cout << "The profit of the factory is: " << profit(keep) << std::endl;
                    std::cout << std::endl;
                    break;
                case 0:
                    exit = true;
                    break;
                default:
                    std::cout << std::endl;
                    std::cout << "Error input. Try again" << std::endl;
                    std::cout << std::endl;
                    break;
            }
        } else {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << std::endl;
            std::cout << "Error input. Try again" << std::endl;
            std::cout << std::endl;
        }
    } while (!exit);
}
