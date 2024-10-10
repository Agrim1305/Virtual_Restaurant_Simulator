#include "Table.h"

Table::Table(int table_number) : table_number(table_number), occupied(false) {}

int Table::get_table_number() const {
    return table_number;
}

bool Table::is_occupied() const {
    return occupied;
}

void Table::occupy() {
    occupied = true;
}

void Table::vacate() {
    occupied = false;
}
