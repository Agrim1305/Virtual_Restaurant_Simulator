#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>
#include "Order.h"  // Ensure Order is included

class Employee {
protected:
    std::string name;
    int id;
    std::string role;

public:
    Employee(std::string name, int id, std::string role);
    virtual void perform_task() = 0;
    std::string get_name() const;
    std::string get_role() const;
};

class Chef : public Employee {
public:
    Chef(std::string name, int id);
    void prepare_order(const Order& order);
    void perform_task() override;
};

class Waiter : public Employee {
public:
    Waiter(std::string name, int id);
    void serve_order(const Order& order);
    void assign_table(int table_number);
    void perform_task() override;
};

class Manager : public Employee {
public:
    Manager(std::string name, int id);
    void manage_staff(std::vector<Employee*>& staff);
    void perform_task() override;
};

#endif
