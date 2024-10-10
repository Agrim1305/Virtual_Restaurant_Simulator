#include "Table.h"

Table::Table(int table_number) : table_number(table_number) {}

int Table::get_table_number() const {
    return table_number;
}
