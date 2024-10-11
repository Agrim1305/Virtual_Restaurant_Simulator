#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

// Declaration of the abstract base class 'Employee'
class Employee {
protected:
    std::string name;  // Stores the name of the employee
    int id;            // Stores the employee's ID

public:
//Initializes the Employee's name and ID
    Employee(const std::string& name, int id);
    virtual ~Employee() {}

// Method to return the Employee's name
    std::string get_name() const;
    int get_id() const;

    // Pure virtual function for polymorphism
    virtual void perform_task() const = 0;  // This makes Employee an abstract class
};

#endif
