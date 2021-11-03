#ifndef UNTITLED_WORKER_H
#define UNTITLED_WORKER_H

#include "Factory.h"
#include <string>

class Worker : public Factory {
private:
    std::string _fullName;
    std::string _position;
    int _income;
    std::string _address;
    std::string _phone;
public:
    Worker();
    Worker(std::string fullName, std::string position, int income, std::string address, std::string phone);
    Worker(Worker& obj);
    ~Worker();
    void setFullName(std::string fullName);
    void setPosition(std::string position);
    void setIncome(int income);
    void setAddress(std::string address);
    void setPhone(std::string phone);
    std::string getFullName();
    std::string getPosition();
    int getIncome();
    std::string getAddress();
    std::string getPhone();
};

#endif //UNTITLED_WORKER_H
