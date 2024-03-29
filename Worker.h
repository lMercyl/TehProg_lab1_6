#ifndef UNTITLED_WORKER_H
#define UNTITLED_WORKER_H

#include "Factory.h"

class Worker : public Factory {
private:
    std::string _fullName;
    std::string _position;
    std::string _income;
    std::string _address;
    std::string _phone;
public:
    Worker();
    Worker(std::string fullName, std::string position, std::string income, std::string address, std::string phone);
    Worker(Worker& obj);
    ~Worker() override;

    void setFullName(std::string fullName);
    void setPosition(std::string position);
    void setIncome(std::string income);
    void setAddress(std::string address);
    void setPhone(std::string phone);

    std::string getFullName();
    std::string getPosition();
    std::string getIncome();
    std::string getAddress();
    std::string getPhone();

    void setInfoObject() override;
    void editInfoObject(int id) override;
    void showInfoObject() override;
    void saveInfoObject() override;
    int getIncomeObject() override;
    int getPriceObject() override;
};

#endif //UNTITLED_WORKER_H
