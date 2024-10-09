#include "Table.h"
Table::Table(int number) : number(number), is_occupied(false) {}

void Table::occupy(Customer& customer) {
    is_occupied = true;
}

void Table::vacate() {
    is_occupied = false;
}

bool Table::get_occupied_status() const {
    return is_occupied;
}

int Table::get_number() const {
    return number;
}
