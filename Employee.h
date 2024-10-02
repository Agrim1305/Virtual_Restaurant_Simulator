#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <iostream>
using namespace std;

// Abstract class Employee
class Employee {
protected:
    string name;
    int id;
    string role;
public:
    Employee(string name, int id, string role) : name(name), id(id), role(role) {}
    virtual void performDuties() = 0;  // Pure virtual function
    string getName() const { return name; }
    string getRole() const { return role; }
};

// Derived class Chef
class Chef : public Employee {
public:
    Chef(string name, int id) : Employee(name, id, "Chef") {}
    void performDuties() override {
        cout << "Chef " << name << " is preparing food." << endl;
    }
};

// Derived class Waiter
class Waiter : public Employee {
public:
    Waiter(string name, int id) : Employee(name, id, "Waiter") {}
    void performDuties() override {
        cout << "Waiter " << name << " is serving food." << endl;
    }
};

// Derived class Manager
class Manager : public Employee {
public:
    Manager(string name, int id) : Employee(name, id, "Manager") {}
    void performDuties() override {
        cout << "Manager " << name << " is managing the staff." << endl;
    }
};

#endif
