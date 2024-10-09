#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <vector>

class Employee {
protected:
    std::string name;
    int id;
    std::string role;

public:
    Employee(std::string name, int id, std::string role);

    // Pure virtual function to perform tasks
    virtual void perform_task() = 0;

    std::string get_name() const;
    std::string get_role() const;
};

// Derived class: Chef
class Chef : public Employee {
public:
    Chef(std::string name, int id);
    
    void prepare_order();  // Specific to Chef
    void perform_task() override;  // Override perform_task
};

// Derived class: Waiter
class Waiter : public Employee {
public:
    Waiter(std::string name, int id);
    
    void serve_order();  // Specific to Waiter
    void assign_table(int table_number);  // Assign a customer to a table
    void perform_task() override;  // Override perform_task
};

// Derived class: Manager
class Manager : public Employee {
public:
    Manager(std::string name, int id);
    
    void manage_staff(std::vector<Employee*>& staff);  // Manager-specific task
    void perform_task() override;  // Override perform_task
};

#endif
