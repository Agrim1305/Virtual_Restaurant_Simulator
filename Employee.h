#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    Employee(const std::string& name, int id);
    virtual ~Employee() {}

    std::string get_name() const;
    int get_id() const;

    // Pure virtual function for polymorphism
    virtual void perform_task() const = 0;  // This makes Employee an abstract class
};

#endif
