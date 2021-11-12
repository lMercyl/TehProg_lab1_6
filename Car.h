#ifndef UNTITLED_CAR_H
#define UNTITLED_CAR_H

#include "Factory.h"

class Car : public Factory {
private:
    std::string _mark;
    std::string _model;
    std::string _number;
public:
    Car();
    Car(std::string mark, std::string model, std::string number);
    Car(Car& obj);
    ~Car() override;

    void setMark(std::string mark);
    void setModel(std::string model);
    void setNumber(std::string number);

    std::string getMark();
    std::string getModel();
    std::string getNumber();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
    int getPriceObject() override;
    int getIncomeObject() override;
};

#endif //UNTITLED_CAR_H
