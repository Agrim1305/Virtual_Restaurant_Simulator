#ifndef TABLE_H
#define TABLE_H

#include "Customer.h"

class Table {
    int number;
    bool is_occupied;

public:
    Table(int number);
    void occupy(Customer& customer);
    void vacate();
    bool get_occupied_status() const;
    int get_number() const;
};

#endif
