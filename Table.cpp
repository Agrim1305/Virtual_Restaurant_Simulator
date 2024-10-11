#include "Table.h"

// Table Class
// Initializes the table with a specified table number and sets its initial state to unoccupied
Table::Table(int table_number) : table_number(table_number), occupied(false) {}

 // Method to return the table's number
int Table::get_table_number() const {
    return table_number;
}

// Checks if the table is currently occupied
// Return True if occupied, otherwise False
bool Table::is_occupied() const {
    return occupied;
}

// Marks the table as occupied
void Table::occupy() {
    occupied = true;
}

// Marks the table as vacant
void Table::vacate() {
    occupied = false;
}
